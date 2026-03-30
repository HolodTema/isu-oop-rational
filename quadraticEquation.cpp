#include "quadraticEquation.hpp"
#include <exception>
#include <iostream>


void quadraticEquation(std::ostream& os, const Rational& a, const Rational& b, const Rational& c) {
    Rational discr = (b * b) - (Rational(4) * a * c);
    os << discr << "\n";

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

    Rational root1 = ((b * Rational(-1)) + discr.sqrt()) / (Rational(2) * a * c);
    
    Rational root2 = ((b * Rational(-1)) - discr.sqrt()) / (Rational(2) * a * c);

    os << "Equation has two roots:\n";
    os << "Root1: " << root1 << "\n";
    os << "Root2: " << root2 << "\n";
}

