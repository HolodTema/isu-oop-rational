#include <iostream>
#include "quadraticEquation.hpp"

int main() {
    Rational n(16);
    std::cout << n.sqrt() << "\n";

    std::cout << "------------------" << "\n";

    Rational a(2);
    Rational b(-5);
    Rational c(3);
    
    try {
        quadraticEquation(std::cout, a, b, c);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}



