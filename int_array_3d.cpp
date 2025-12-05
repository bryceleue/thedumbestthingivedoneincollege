#include "int_array_3d.h"
#include "string"

IntArray3D::IntArray3D(const int slices, const int rows, const int cols):
    data_(new int[slices * rows * cols]), 
    size_(slices * rows * cols),
    capacity_(size_ * 2),
    slices_(slices),
    rows_(rows),
    cols_(cols)
{}

IntArray3D::IntArray3D(int* init_slice, const int rows, const int cols): 
    rows_(rows), 
    cols_(cols), 
    size_(rows * cols), 
    capacity_(rows * cols * 2), 
    slices_(1)
{
    Set(init_slice);

}

IntArray3D::~IntArray3D() {
    delete[] data_;
}

int* IntArray3D::Get() {
    return data_;
}

int IntArray3D::Get(const int slice, const int row, const int col) {
    int position = FlattenPosition(slice, row, col);
    if(size_ <= position) {
        throw std::length_error("Out of bounds...");
    }

    return data_[position];
}

void IntArray3D::Set(int* data) {
    data_ = data;
}

void IntArray3D::Set(int data, const int slice, const int row, const int col) {
    if(size_ <= slice * row * col) {
        std::string error = "Out of bounds. "+std::to_string(slice * row * col)+" exceeds "+std::to_string(size_);
        throw std::length_error(error);
    }

    data_[FlattenPosition(slice, row, col)] = data;
}

void IntArray3D::Write(int data, const int position) {
    if(size_ <= position) {
        std::string error = "Out of bounds. "+std::to_string(position)+" exceeds "+std::to_string(size_);
        throw std::length_error(error);
    }

    data_[position] = data;
}

void IntArray3D::Append(int* new_slice) {
    if(capacity_ <= size_ * 2) Resize();
    int slice_size = rows_ * cols_;
    for(int i = size_; i < size_ + slice_size; ++i) {
        data_[i] = new_slice[i - size_];
    }
    
    slices_++;
    size_ += slice_size;
}

void IntArray3D::PrintLast() {
    for(int j = 0; j < rows_; ++j) {
        for(int k = 0; k < cols_; ++k) {
            
            std::cout << data_[FlattenPosition(slices_, j, k)] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void IntArray3D::PrintSlices() {
    std::cout << std::endl;
    for(int i = 0; i < slices_; ++i) {
        for(int j = 0; j < rows_; ++j) {
            for(int k = 0; k < cols_; ++k) {
                std::cout << data_[FlattenPosition(i, j, k)] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n";
}

void IntArray3D::Size() {
    return Size();
}

int IntArray3D::FlattenPosition(const int slice, const int row, const int col) {
    return slice * rows_ * cols_ + cols_ * row + col;
}

void IntArray3D::Resize() {

    int* newArr = new int[slices_ * rows_ * cols_ * 2];

    for(int i = 0; i < size_; ++i) {
        newArr[i] = data_[i];
    }
    
    capacity_ *= 2;
    
    delete[] data_;
    data_ = newArr;

}
