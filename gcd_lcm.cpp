#include "gcd_lcm.hpp"
#include <limits>
#include "exceptions.hpp"

//gcc - greatest common divisor
//difficulty is O(logN)
long long getGCD(long long a, long long b) {
    if (a < 0) {
        a *= -1ll;
    }
    if (b < 0) {
        b *= -1ll;
    }
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//LCM - least common multiple
// O(logN)
long long getLCM(long long a, long long b) {
    long long gcd = getGCD(a, b);
    long long result = a / gcd;
    if (std::numeric_limits<long long>::max() / b < result) {
        throw LongLongOverflowException();
    }
    result *= b;
    return result;
}

// O(1)
long long getLCM(long long a, long long b, long long gcd) {
    long long result = a / gcd;
    if (std::numeric_limits<long long>::max() / b < result) {
        throw LongLongOverflowException();
    }
    result *= b;
    return result;
}
