
#include <cmath>

namespace summations {
    //Sigma n = 100, i = 0 (2*i+9)

    int f1() {
        int n = 0;
        int i = 0;

        while(n <= 100) {
            i += 2*n + 9;
            ++n;

        }

        return i;
    }

    int f1r(int n, int i) {
        return n > 100 ? i : i + f1r(n + 1, (2*n + 9));
    }

    int f1r() {
        int n = 0;
        int i = 0;
        return f1r(n ,i);
    }

    //Sigma n = 100, i = 0 (5*i^3+i^2)
    
    int f2() {
        int n = 1;
        int i = 0;

        while(n <= 100) {
            i += ( 5 * pow(n, 3) ) + pow(n, 2);
            ++n;
        }

        return i;
    }

    int f2r(int n, int i) {
        return n > 100 ? i : i + f2r(n + 1, ( 5 * pow(n, 3) ) + pow(n, 2));
    }
    
    int f2r() {
        int n = 0;
        int i = 0;
        return f2r(n, i);
    }

    //Sigma n = 100, i = 0 (5*i)^-1/2
    double f3() {
        double n = 0;
        double i = 0;

        while(n <= 100) {
            i += ( 1 / sqrt(pow(5, n)) );
            ++n;
        }

        return i;
    }

    double f3r(double n, double i) {
        return n > 100 ? i : i + f3r(n + 1, 1 / sqrt(pow(5, n)) );
    }

    double f3r() {
        double n = 0;
        double i = 0;
        return f3r(n, i);
    }
}
