#include "gcd.hpp"
#include <math>

//gcc - greatest common divisor
//difficulty is O(logN)
int gcd(int a, int b) {
    absA = std::abs(a);
    absB = std::abs(b);

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

