#include "quadraticEquation.hpp"
#include <exception>
#include <iostream>


void quadraticEquation(
    std::ostream& os, 
    const Rational& a, 
    const Rational& b, 
    const Rational& c, 
    bool debugMode
) {
    Rational discr = (b * b) - (Rational(4) * a * c);

    if (debugMode) {
        os << "Quadratic equation solving: \n";
        os << "a = " << a << "\n";
        os << "b = " << b << "\n";
        os << "c = " << c << "\n";
        os << "D = " << discr << "\n";
    }

    if (discr < Rational(0)) {
        os << "Equation has no roots.\n";
        return;
    }

    if (discr == Rational(0)) {
        Rational root = (b * Rational(-1)) / (Rational(2) * a);
        os << "Equation has only one root:\n";
        os << root << "\n";
        return;
    }
    
    if (debugMode) {
        std::cout << "-b = " << (b * Rational(-1)) << "\n";
        std::cout << "-b + sqrt(D) = " << ((b * Rational(-1)) + discr.sqrt(false)) << "\n";
        std::cout << "2*a = " << (Rational(2) * a) << "\n";
    }

    Rational root1 = ((b * Rational(-1)) + discr.sqrt(false)) / (Rational(2) * a);
    
    Rational root2 = ((b * Rational(-1)) - discr.sqrt(false)) / (Rational(2) * a);

    os << "Equation has two roots:\n";
    os << "Root1: " << root1 << "\n";
    os << "Root2: " << root2 << "\n";

    if (debugMode) {
        os << "---------------------\n";
    }
}

