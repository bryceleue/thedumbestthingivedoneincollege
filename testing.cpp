#include <iomanip>
#include "testing.h"

using namespace std;

void assertTrue(bool b, std::string description) {
    if(!b) {
        cout << "FAILED: " << description << endl;
    } else {
        cout << "PASSED: " << description << endl;
    }
}

void assertTrueOutputDouble(bool b, std::string description, double d, int p) {
    cout << std::fixed << std::setprecision(p);
    if(!b) {
        cout << "FAILED: " << description;
    } else {
        cout << "PASSED: " << description;
    }
    cout << " " << d << endl;
}

bool assertEquals3DIntArrays(IntArray3D &x, int y[][4][3], int slices) {
    bool passing = true;
    int a, b;

    int d2size = 4;
    int d3size = 3;

    for(int i = 0; passing && i < slices; ++i) {
        for(int j = 0; j < d2size; ++j) {
            for(int k = 0; k < d3size; ++k) {
                a = x.Get(i, j, k);
                b = y[i][j][k];

                if(passing && a != b) {
                    passing = false;
                }

            }
        }
    }

    //debugging output
    if(!passing) {
        for(int i = 0; i < slices; ++i) {
            for(int j = 0; j < 4; ++j) {
                for(int k = 0; k < 3; ++k) {
                    a = x.Get(i, j, k);
                    b = y[i][j][k];

                    cout << a << (a == b ? " == " : " != ") << b << endl;

                }
            }
        }
    }
    


    return passing;
}