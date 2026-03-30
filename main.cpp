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

    Rational r5(5);
    r5.sqrt(true);
}

void testEquation1() {
    Rational a(2);
    Rational b(-5);
    Rational c(3);
    
    try {
        quadraticEquation(std::cout, a, b, c, true);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
}


void testEquationCLI() {
    try {
        std::cout << "Quadratic equation CLI\n\n";

        std::cout << "Enter koeff a:\n";
        Rational a;
        std::cin >> a;

        std::cout << "Enter koeff b:\n";
        Rational b;
        std::cin >> b;

        std::cout << "Enter koeff c:\n";
        Rational c;
        std::cin >> c;

        quadraticEquation(std::cout, a, b, c, true);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
}


int main() {
    //testSqrt();

    //testEquation1();
    
    testEquationCLI();   

    return 0;
}



