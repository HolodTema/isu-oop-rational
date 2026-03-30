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
    
    Rational rootDenom = Rational(2) * a;
    rootDenom.reduct();

    Rational discrSqrt = discr.sqrt(false);

    Rational numeratorRoot1 = (b * Rational(-1)) + discrSqrt;

    Rational numeratorRoot2 = (b * Rational(-1)) - discrSqrt;

    if (debugMode) {
        std::cout << "-b = " << (b * Rational(-1)) << "\n";
        std::cout << "-b + sqrt(D) = " << numeratorRoot1 << "\n";
        std::cout << "2*a = " << rootDenom << "\n";
    }
    
    Rational root1 = numeratorRoot1 / rootDenom;
    Rational root2 = numeratorRoot2 / rootDenom;

    os << "Equation has two roots:\n";
    os << "Root1: " << root1 << "\n";
    os << "Root2: " << root2 << "\n";

    if (debugMode) {
        os << "---------------------\n";
    }
}

