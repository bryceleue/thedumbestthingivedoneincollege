#include <iostream>
#include <string>
#include <iomanip>
#include "testing.h"
#include "int_array_3d.h"
#include "summations.cpp"
#include "asymptotic.cpp"
#include "fib.cpp"
#include "hanoi.h"


void construct3DArray();
void sums();
void asymptotic();
void fibonacci();
void hanoiTest();


int main() {

    construct3DArray();
    sums();
    asymptotic();
    fibonacci();
    hanoiTest();

    return 0;
}



void construct3DArray() {
    int states = 7;
    int rows = 4;
    int cols = 3;

    int* data = new int[states * rows * cols]{
        //state 0 (slice 0)
        0,0,0,
        2,0,0,
        1,0,0,
        4,3,0,

        //state 1 (slice 1) etc...
        0,0,0,
        0,0,0,
        1,0,0,
        4,3,2,

        0,0,0,
        0,0,0,
        0,0,1,
        4,3,2,

        0,0,0,
        0,0,0,
        3,0,1,
        4,0,2,

        0,0,0,
        0,0,0,
        3,0,0,
        4,1,2,

        0,0,0,
        2,0,0,
        3,0,0,
        4,1,0,

        1,0,0,
        2,0,0,
        3,0,0,
        4,0,0
    };

    IntArray3D dummyHanoi(states, rows, cols);

    dummyHanoi.Set(data);

    int dummyData[7][4][3] = {
        {
            {0,0,0},
            {2,0,0},
            {1,0,0},
            {4,3,0}
        },
        {
            {0,0,0},
            {0,0,0},
            {1,0,0},
            {4,3,2},
        },
        {
            {0,0,0},
            {0,0,0},
            {0,0,1},
            {4,3,2},
        },
        {
            {0,0,0},
            {0,0,0},
            {3,0,1},
            {4,0,2},
        },
        {
            {0,0,0},
            {0,0,0},
            {3,0,0},
            {4,1,2},
        },
        {
            {0,0,0},
            {2,0,0},
            {3,0,0},
            {4,1,0},
        },
        {
            {1,0,0},
            {2,0,0},
            {3,0,0},
            {4,0,0},
        },
    };

    dummyHanoi.Set(data);

    assertTrue(assertEquals3DIntArrays(dummyHanoi, dummyData, states), "3DArray Constructor, Setter and Arithmetic method for higher performance 3D array");



}

void sums() {
    int f1 = summations::f1();
    int f1r = summations::f1r();

    assertTrue(f1 == 11009, "Sum i=0, n=100, (2i + 9). output: " + std::to_string(f1));
    assertTrue(f1r == 11009, "Sum i=0, n=100, (2i + 9), recursive. output: " + std::to_string(f1r));

    int f2 = summations::f2();
    int f2r = summations::f2r();

    assertTrue(f2 == 127850850, "Sum i=1, n=100, (5i^3 + i^2). output: " + std::to_string(f2));
    assertTrue(f2r == 127850850, "Sum i=1, n=100, (5i^3 + i^2), recursive. output: " + std::to_string(f2r));

    double f3 = summations::f3();
    double f3r = summations::f3r();

    assertTrueOutputDouble(f3 == 1.8090169943749475, "Sum i=0, n=100, (5i)^(-1/2). output: ", f3);
    assertTrueOutputDouble(f3r == 1.8090169943749475, "Sum i=0, n=100, (5i)^(-1/2). output: ", f3r);
}

void asymptotic() {
    anotation::e1();
    anotation::e2();
}

void fibonacci() {
    int numVals = 5;
    int testIndices[] = { 3, 15, 20, 31, 45 };
    int expectedValues[] = {2, 610, 6765, 1346269, 1134903170};

    int** output = new int*[5];

    for(int i = 0; i < numVals; ++i) {
        output[i] = fib::fib(testIndices[i]);
    }

    for(int i = 0; i < numVals; ++i) {
        assertTrue(*output[i] == expectedValues[i], "Compute nth fibonacci term: " + std::to_string(testIndices[i]) + "... output: " + std::to_string(*output[i]));
    }

    delete[] output;

}


    //also tests Append and Resize for 3d array
    //tested up to 20, 7 (less than 7 poles doesn't work with 20)
    //can probably keep going but the test output exceeds what is rendered, so I omitted everything after 9x5
    //needs detailed complexity analysis but I think its better than O(n^2)
void hanoiTest() {

    Hanoi Tower1(4, 3, 
        1,0,0,
        2,0,0,
        3,0,0,
        4,0,0
    );

    Tower1.Solve();
    Tower1.PrintStates();

    Hanoi Tower2(6, 4, 
        1,0,0,0,
        2,0,0,0,
        3,0,0,0,
        4,0,0,0,
        5,0,0,0,
        6,0,0,0
    );

    Tower2.Solve();
    Tower2.PrintStates();

    Hanoi Tower3(9, 5, 
        1,0,0,0,0,
        2,0,0,0,0,
        3,0,0,0,0,
        4,0,0,0,0,
        5,0,0,0,0,
        6,0,0,0,0,
        7,0,0,0,0,
        8,0,0,0,0,
        9,0,0,0,0
    );

    Tower3.Solve();
    Tower3.PrintStates();

    Hanoi Tower4(4, 3, 
        0,0,0,
        2,0,0,
        1,0,0,
        4,3,0
    );

    Tower4.Solve();
    Tower4.PrintStates();

    Hanoi Tower5(6, 4, 
        0,0,0,0,
        0,0,0,0,
        0,0,0,0,
        1,0,0,0,
        4,3,0,0,
        2,5,0,6
    );

    Tower5.Solve();
    Tower5.PrintStates();

    Hanoi Tower6(9, 5, 
        0,0,0,0,0,
        0,0,0,0,0,
        0,0,0,0,0,
        0,0,0,0,0,
        0,0,0,0,0,
        0,0,0,0,0,
        0,0,0,0,8,
        4,3,0,0,9,
        2,5,1,6,7
    );

    Tower6.Solve();
    Tower6.PrintStates();

}