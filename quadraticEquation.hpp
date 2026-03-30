#ifndef QUADRATIC_EQUATION_HPP
#define QUADRATIC_EQUATION_HPP

#include <iosfwd>
#include "Rational.hpp"

void quadraticEquation(
    std::ostream& os, 
    const Rational& a, 
    const Rational& b, 
    const Rational& c,
    bool debugMlde
);

#endif
