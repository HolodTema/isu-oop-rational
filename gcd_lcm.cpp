#include "gcd_lcm.hpp"

//gcc - greatest common divisor
//difficulty is O(logN)
int getGCD(int a, int b) {
    int absA = a;
    int absB = b;

    if (absA < 0) {
        absA *= -1;
    }
    if (absB < 0) {
        absB *= -1;
    }

    while (absB != 0) {
        int temp = absB;
        absB = absA % absB;
        absA = temp;
    }
    return absA;
}

int getLCM(int a, int b) {
    int gcd = getGCD(a, b);
    int result = a / gcd;
    result *= b;
    return result;
}
