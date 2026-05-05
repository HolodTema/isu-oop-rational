#include "quadraticEquation.hpp"
#include <iostream>
#include "exceptions.hpp"


void quadraticEquation(
    std::ostream& os, 
    const Rational& a, 
    const Rational& b, 
    const Rational& c, 
    bool debugMode
) {
    if (a == Rational(0)) {
        os << "Error: equation is not quadratic, because of coefficient a = 0.\n";
        return;
    }

    try {
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

        Rational rootDenominator = Rational(2) * a;

        Rational discrSqrt = discr.sqrt(true);

        std::cout << "sqrt(D) = " << discrSqrt << "\n";

        Rational numeratorRoot1 = (b * Rational(-1)) + discrSqrt;

        Rational numeratorRoot2 = (b * Rational(-1)) - discrSqrt;

        if (debugMode) {
            std::cout << "-b = " << (b * Rational(-1)) << "\n";
            std::cout << "-b + sqrt(D) = " << numeratorRoot1 << "\n";
            std::cout << "2*a = " << rootDenominator << "\n";
        }

        Rational root1 = numeratorRoot1 / rootDenominator;
        Rational root2 = numeratorRoot2 / rootDenominator;

        os << "Equation has two roots:\n";
        os << "Root1: " << root1 << "\n";
        os << "Root2: " << root2 << "\n";

        if (debugMode) {
            os << "---------------------\n";
        }
    }
    catch (const LongLongOverflowException& e) {
        os << e.what() << "\n";
    }
}

