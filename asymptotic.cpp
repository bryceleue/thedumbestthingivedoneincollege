//////
//Determine the asymptotic notation using the big O and big Omega
//This was tedious to type out.  I should have taken pictures of a whiteboard
#include <iostream>

namespace anotation {
    //5n^3+10n^2+600
    void e1() {

        std::cout << "\nAlgorithm Analysis\n-----------------------\n";

        std::cout << "\nDetermine the asymptotic notation using the big O (oh) and big Ω(omega) for:" << std::endl;
        std::cout << "5n^3 + 10n^2 + 600" << std::endl;
        std::cout << "call this g(n)" << std::endl;
        std::cout << "\nWe can start by determining big Θ(theta) because this gives us our upper and lower bound" << std::endl;
        std::cout << "let there be constants c1(coefficient for lower bound highest order term), c2(upper bound coefficient), and a minimum n, n0\n\n";
        std::cout << "0 <= c1n^3 <= 5n^3 + 10n^2 + 600 <= c2n^3 for all n >= n0" << std::endl;
        std::cout << "dividing by n^3 yields:  c1 <= 5 + 10/n + 600/n^3 <= c2" << std::endl;
        std::cout << "the non constant terms approach 0 as n grows, so c1 <= 5" << std::endl;
        std::cout << "5 + 10/n + 600/n^3 approaches 5 as n grows, so c2 >= 5" << std::endl;
        std::cout << "let c1 = 1 and c2 = 10" << std::endl;
        std::cout << "1(n^3) <= 5n^3 + 10n^2 + 600 <= 10(n^3)... holds for n0 = 6" << std::endl;
        std::cout << "216 <= 2040 <= 2160\n\n";
        std::cout << "We have confirmed an upper bound and lower bound exists for a function f(n) where f(n) denotes big theta of g(n)." << std::endl;
        std::cout << "Therefore: (Big Theta) Θ(n^3) = 5n^3 + 10n^2 + 600\n\n";

        std::cout << "Big O : O(n^3)" << std::endl;
        std::cout << "Because we know there exists a c2 such that c2n^3 >= 5n^3 + 10n^2 + 600 for n0 = 6 we can say that O(n^3) = 5n^3 + 10n^2 + 600 because our proof for Θ(n^3) = f(n) implies this.\n\n";

        std::cout << "Big Omega : Ω(n^3)" << std::endl;
        std::cout << "Because we know there exists a c1 such that c1n^3 <= 5n^3 + 10n^2 + 600 for n0 = 6 we can say that (Big Omega) Ω(n^3) = 5n^3 + 10n^2 + 600 because our proof for  Θ(n^3) = f(n) implies this.\n";


    }

    //20n^2+10n+n^3
    void e2() {
        std::cout << "\nUsing the same approach, we examine: n^3 + 20n^2 + 10n\n" << std::endl;
        std::cout << "let g(n) = n^3 + 20n^2 + 10n" << std::endl;
        std::cout << "0 <= c1n^3 <= n^3 + 20n^2 + 10n <= c2n^3 for all n >= n0" << std::endl;
        std::cout << "c1 <= 1 + 20/n + 10/n^2 <= c2" << std::endl;
        std::cout << "the non-constant terms approach 0 as n grows, so c1 <= 1" << std::endl;
        std::cout << "the center of the inequality approaches 1 as n grows, so c2 >= 1" << std::endl;
        std::cout << "let c1 = 1 and c2 = 6" << std::endl;
        std::cout << "1 <= 1 + 20/6 + 10/6^2 <= 6" << std::endl;
        std::cout << "1 <= 1 + 10/3 + 10/36 <= 6" << std::endl;
        std::cout << "1 <= 13/3 + 5/18 <= 6" << std::endl;
        std::cout << "1 <= 83/18 <= 6" << std::endl;
        std::cout << "18 <= 83 <= 108... holds for n0 = 6" << std::endl;
        std::cout << "\nWe have confirmed an upper bound and lower bound exists for a function f(n) where f(n) denotes big theta of g(n)." << std::endl;
        std::cout << "Therefore: (Big Theta) Θ(n^3) = n^3 + 20n^2 + 10n" << std::endl;

        std::cout << "\nBig O : O(n^3)" << std::endl;
        std::cout << "Because we know there exists a c2 such that c2n^3 >= n^3 + 20n^2 + 10n for n0 = 6 we can say that (Big O) O(n^3) = n^3 + 20n^2 + 10n because our proof for Θ(g(n)) = f(n) implies this." << std::endl;

        std::cout << "\nBig Omega : Ω(n^3)" << std::endl;
        std::cout << "Because we know there exists a c1 such that c1n^3 <= n^3 + 20n^2 + 10n for n0 = 6 we can say that (Big Omega) Ω(n^3) = n^3 + 20n^2 + 10n because our proof for  Θ(g(n)) = f(n) implies this.\n";
        std::cout << "\n-----------------------\n\n";
    }
    //////
}