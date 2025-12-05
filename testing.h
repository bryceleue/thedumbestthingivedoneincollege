#ifndef TESTING_H
#define TESTING_H

#include <string>
#include <iostream>
#include "int_array_3d.h"

void assertTrue(bool b, std::string description);
void assertTrueOutputDouble(bool b, std::string description, double d, int p = 15);

bool assertEquals3DIntArrays(IntArray3D& x, int y[7][4][3], int slices);

template <class T, class U>
void assertEquals(const T& x, const U& y, std::string description) {
    if (x == y) {
        std::cout << "PASSED: " << description << std::endl;
    } else {
        std::cout << "FAILED: " << description << std::endl;
        std::cout << "  " << x << std::endl;
        std::cout << "  !=" << std::endl;
        std::cout << "  " << y << std::endl;

    }
}

#endif