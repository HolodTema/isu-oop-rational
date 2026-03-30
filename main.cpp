#include <iostream>
#include "quadraticEquation.hpp"

void testSqrt() {
    Rational r1(16);
    r1.sqrt(true);

    Rational r2(10000);
    r2.sqrt(true);

    Rational r3(625);
    r3.sqrt(true);

    Rational r4(1);
    r4.sqrt(true);
}

int main() {
    testSqrt();

    Rational a(2);
    Rational b(-5);
    Rational c(3);
    
    try {
        quadraticEquation(std::cout, a, b, c, true);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}



