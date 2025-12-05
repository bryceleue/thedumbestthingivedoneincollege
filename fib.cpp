//iterative Fib
#include <iostream>
namespace fib {

    int* fib(int x, int* result) {

        if(x <= 2) {
            *result = x == 2 ? 1 : x;

        } else {

            *result = 2;

            int n1;
            int n2 = 1;

            while(x > 3) {

                //store f(n-1)
                n1 = *result;

                //update result by the sum of the previous two terms
                *result += n2;

                //store f(n-2)
                n2 = n1;

                --x;
            }
        }

        return result;
    }

    int* fib(int x) {
        int* result = new int;
        return fib(x, result);
    }


}
