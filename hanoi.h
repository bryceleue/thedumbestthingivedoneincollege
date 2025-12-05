#include <vector>
#include <map>
#include <utility>
#include "int_array_3d.h"
#include <iostream>

class Hanoi {
    public:

    template <class... Args>
    Hanoi(int depth, int poles, Args... values);
    ~Hanoi();

    void Solve();
    void PrintStates();

    private:

    int Position(int value);
    int PositionOnPoleQuantity(int pole);
    int TopOccupied(int pole);
    void UpdatePosition(int value, int position);
    int Depth(int disc);
    int Pole(int disc);
    int PoleQuantity(int pole);
    int EmptyPole();
    int HighestAtOrAbove(int position);
    int LowestQuantityViablePole(int source_pole, int ignore_pole = -1);
    int Unburden(int to_move);
    int UnburdenWithPriority(int to_move, int ignore_pole);

    template <class... Args>
    void PopulateTower(int value, Args... values);
    void PopulateTower();

    int depth_;
    int poles_;
    int disc_quantity_;
    int subject_;
    int largest_disc_starting_pole_;
    int last_installed_foundation_;
    int* tower_;
    IntArray3D states_; 
    //< value: position >
    std::map<int,int> discs_;
    //< pole: qty >
    std::map<int,int> pole_quantities_;
    std::vector<int> unplaced_discs_;

};

//constructor and destructor

template <class... Args>
Hanoi::Hanoi(int depth, int poles, Args... values): 
depth_(depth),
poles_(poles),
disc_quantity_(0),
subject_(0),
tower_(new int[poles * depth]),
states_(new int[poles * depth * 2], depth, poles)
{   
    for(int i = 0; i < poles_; ++i) {
        pole_quantities_[i] = 0;
    }

    PopulateTower(values...);

    unplaced_discs_ = std::vector<int>(disc_quantity_);
    subject_ = 0;
    for(std::pair<int,int> disc : discs_) {
        unplaced_discs_.at(subject_) = disc.first;
        ++subject_;
    }

    
    largest_disc_starting_pole_ = discs_[unplaced_discs_.back()] % poles_;
}

Hanoi::~Hanoi() {
    delete[] tower_;
}

void Hanoi::Solve() {

    bool discs_unplaced = true;

    while(discs_unplaced) {

        int target_disc_position = Position(unplaced_discs_.back());


        //the target foundation disc has stuff on it that it shouldn't
        if(target_disc_position - poles_ >= 0 && 
            tower_[target_disc_position - poles_] > 0) {

            int highest_above_target = HighestAtOrAbove(target_disc_position - poles_);

            //the largest disc is placed, we need to make sure we aren't covering it
            if(unplaced_discs_.size() < disc_quantity_) {

                UnburdenWithPriority(highest_above_target, last_installed_foundation_);
            } 
            //still clearing the largest disc
            else {

                Unburden(highest_above_target);
            }

        }
        //the target foundation is at the wrong height or pole but there is nothing on it
        else if(unplaced_discs_.size() != Depth(target_disc_position) || 
            Pole(target_disc_position) == largest_disc_starting_pole_ ) {

            //the target foundation is the largest disc
            if(target_disc_position == discs_[disc_quantity_]) {

                int empty_pole = EmptyPole();
                //there is an empty pole move the base to it
                if(empty_pole > -1) {

                    int position = PositionOnPoleQuantity(empty_pole);
                    UpdatePosition(tower_[target_disc_position], position);
                    last_installed_foundation_ = position;

                    unplaced_discs_.pop_back();
                }

                //there isn't, pick the best pole to unburden
                else {

                    int to_move = TopOccupied(LowestQuantityViablePole(Pole(target_disc_position)));
                    UnburdenWithPriority(to_move, Pole(target_disc_position));

                }
            //the target foundation is not the largest disc, ready to be installed onto the next biggest
            } else {

                last_installed_foundation_ -= poles_;
                UpdatePosition(tower_[target_disc_position], last_installed_foundation_);
                
                unplaced_discs_.pop_back();
            }
            

        }
        states_.Append(tower_);

        //loop termination condition
        if(unplaced_discs_.size() == 0) discs_unplaced = false;
    }
}

void Hanoi::PrintStates() {
    std::cout << "\nTower of Hanoi" << std::endl;

    std::cout << "\nStates through solution:" << std::endl;

    states_.PrintSlices();
}


//private methods

int Hanoi::Position(int value) {
    subject_ = discs_[value];

    return subject_;
}

int Hanoi::PositionOnPoleQuantity(int pole) {
    int pole_quantity = pole_quantities_[pole];
    int size = ( poles_ * depth_ );
    int distance_to_depth_starting_index = poles_ * pole_quantity + poles_;
    
    int position = size - distance_to_depth_starting_index + pole;

    return position;
}

int Hanoi::TopOccupied(int pole) {
    int pole_quantity = pole_quantities_[pole];
    int size = ( poles_ * depth_ );
    int distance_to_depth_starting_index = poles_ * pole_quantity;
    
    int position = size - distance_to_depth_starting_index + pole;

    return position;
}

void Hanoi::UpdatePosition(int value, int position) {
    subject_ = position;

    //remember to keep track of pole quantities
    int old_position = discs_[value];
    pole_quantities_[old_position % poles_] -= 1;

    tower_[position] = value;
    discs_[value] = position;
    tower_[old_position] = 0;

    pole_quantities_[position % poles_] += 1;

}

int Hanoi::Depth(int value) {
    subject_ = discs_[value];

    return subject_ / poles_;
}

int Hanoi::Pole(int value) {
    subject_ = discs_[value];

    return subject_ % poles_;
}

int Hanoi::PoleQuantity(int pole) {
    return pole_quantities_[pole];
}

int Hanoi::EmptyPole() {
    int empty = -1;
    for(int i = 0; empty < 0 && i < poles_; ++i) {
        if(pole_quantities_[i] == 0) empty = i;
    }
    return empty;
}

int Hanoi::HighestAtOrAbove(int position) {
    while(position - poles_ >= 0 && tower_[position - poles_] != 0) {
        position -= poles_;
    }
    return position;
}

//this would be better as a recursive / variadic method
//that searched for the best option until possibilites are exhausted
//but im tired again and out of time
int Hanoi::LowestQuantityViablePole(int source_pole, int ignore_pole) {
    bool pole_assigned = false;
    int lowest_quantity_pole;

    for(int i = 0; i < poles_; ++i) {

        if(source_pole != i && ignore_pole != i) {

            if(!pole_assigned) {
                lowest_quantity_pole = i;
                pole_assigned = true;

            } else if(pole_quantities_[lowest_quantity_pole] > pole_quantities_[i]) {
                lowest_quantity_pole = i;
            }
        }

    }

    return lowest_quantity_pole;
}

int Hanoi::Unburden(int origin) {
    int source_pole = Pole(origin);
    int value = tower_[origin];

    //find the lowest qty pole that doesn't contain the next disc
    bool pole_assigned = false;
    int lowest_quantity_pole = LowestQuantityViablePole(source_pole);
    
    int placement_position = PositionOnPoleQuantity(lowest_quantity_pole);

    UpdatePosition(value, placement_position);

    return placement_position;

}

int Hanoi::UnburdenWithPriority(int origin, int ignore_pole) {

    int source_pole = Pole(tower_[origin]);
    int value = tower_[origin];

    //find the lowest qty pole that doesn't contain the next disc
    bool pole_assigned = false;
    int lowest_quantity_pole = LowestQuantityViablePole(source_pole, ignore_pole);
    int placement_position = PositionOnPoleQuantity(lowest_quantity_pole);

    UpdatePosition(value, placement_position);

    return placement_position;

}

void Hanoi::PopulateTower() {}

template <class... Args>
void Hanoi::PopulateTower(int value, Args... values) {

    tower_[subject_] = value;
    states_.Write(value, subject_);

    if(value > 0) {

        discs_[value] = subject_;

        ++disc_quantity_;

        int pole = subject_ % poles_;
        pole_quantities_[pole] += 1;

    }

    ++subject_;

    PopulateTower(values...);
}