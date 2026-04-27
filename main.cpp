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

    Rational r6(0);
    r6.sqrt(true);

    Rational r7(49);
    r7.sqrt(true);

    Rational r8(144);
    r8.sqrt(true);

    Rational r9(1000000);
    r9.sqrt(true);

    Rational r10(2);
    r10.sqrt(true);

    Rational r11(81);
    r11.sqrt(true);

    Rational r12(121);
    r12.sqrt(true);

    Rational r13(169);
    r13.sqrt(true);

    Rational r14(225);
    r14.sqrt(true);

    Rational r15(256);
    r15.sqrt(true);

    Rational r16(289);
    r16.sqrt(true);

    Rational r17(324);
    r17.sqrt(true);

    Rational r18(361);
    r18.sqrt(true);

    Rational r19(400);
    r19.sqrt(true);

    Rational r20(99999);
    r20.sqrt(true);

    Rational r21(1, 4);
    r21.sqrt(true);

    Rational r22(1, 9);
    r22.sqrt(true);

    Rational r23(1, 16);
    r23.sqrt(true);

    Rational r24(1, 144);
    r24.sqrt(true);

    Rational r25(1, 625);
    r25.sqrt(true);

    Rational r26(1, 676);
    r26.sqrt(true);

    Rational r27(1, 7);
    r27.sqrt(true);

    Rational r28(1, 5);
    r28.sqrt(true);

    Rational r29(1, 6);
    r29.sqrt(true);

    Rational r30(31, 49);
    r30.sqrt(true);
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

        std::cout << "Enter coefficient a (numerator and denominator):\n";
        Rational a;
        std::cin >> a;

        std::cout << "Enter coefficient b (numerator and denominator):\n";
        Rational b;
        std::cin >> b;

        std::cout << "Enter coefficient c (numerator and denominator):\n";
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



