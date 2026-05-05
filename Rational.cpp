#include "Rational.hpp"
#include <iostream>
#include <limits>
#include "gcd_lcm.hpp"
#include "exceptions.hpp"


void Rational::swap(Rational& other) noexcept {
    std::swap(numerator_, other.numerator_);
    std::swap(denominator_, other.denominator_);
}

void Rational::reduct() {
    long long gcd = getGCD(numerator_, denominator_);
    numerator_ /= gcd;
    denominator_ /= gcd;
    if (numerator_ < 0 && denominator_ < 0) {
        numerator_ *= -1;
        denominator_ *= -1;
    }
}

void Rational::reduct(long long gcd) {
    numerator_ /= gcd;
    denominator_ /= gcd;
}

long long Rational::getNumerator() const {
    return numerator_;
}

long long Rational::getDenominator() const {
    return denominator_;
}

Rational& Rational::pow(int n) {
    if (n == 0) {
        numerator_ = 1;
        denominator_ = 1;
        return *this;
    }

    bool isNegativePower = n < 0;
    if (n < 0) {
        n *= -1;
    }
    
    Rational result(1ll, 1ll);
    Rational base = *this;
    
    for (int i = 0; i < n; ++i) {
        result *= base;
    }
    
    // if pow is negative, we swap numerator and denominator
    if (isNegativePower) {
        if (result.numerator_ == 0ll) {
            throw DivisionByZeroException();
        }
        std::swap(result.numerator_, result.denominator_);
    }
    
    *this = result;
    return *this;
}

double Rational::getSqrt() const {
    double rationalDouble = static_cast<double>(*this);

    if (rationalDouble < 0) {
        throw std::runtime_error("Unable to get square root from negative value");
    }

    if (rationalDouble == 0) {
        return 0;
    }

    double result = rationalDouble;
    for (int i = 0; i < 10; ++i) {
        result = 0.5 * (result + rationalDouble / result);
    }
    return result;
}

Rational& Rational::sqrt(bool debugMode) {
    constexpr long long SCALE = 10000ll;

    if (debugMode) {
        std::cout << "Calculating sqrt() from rational " << *this << "\n";
        std::cout << "SCALE = " << SCALE << "\n";
    }

    if (!isNotNegative()) {
        if (debugMode) {
            std::cout << "sqrt() cannot be assigned to negative number.\n";
        }
        throw NegativeSquareRootException();
    }

    if (numerator_ == 0ll) {
        if (debugMode) {
            std::cout << "Handling special case when numerator = 0. sqrt(0) = 0\n";
            std::cout << "--------------\n\n";
        }
        denominator_ = 1ll;
        return *this;
    }

    long long absNumerator = numerator_ < 0 ? -numerator_ : numerator_;
    long long absDenominator = denominator_ < 0 ? -denominator_ : denominator_;
    if (std::numeric_limits<long long>::max() / absNumerator < absDenominator) {
        if (debugMode) {
            std::cout << "numerator * denominator affects long long overflow\n";
        }
        throw LongLongOverflowException();
    }

    long long bigNumerator = numerator_ * denominator_;

    long long scale = 1;
    while (true) {
        if ((std::numeric_limits<long long>::max() / scale < scale) ||
            (std::numeric_limits<long long>::max() / scale < absDenominator) ||
            (std::numeric_limits<long long>::max() / (scale * scale) < bigNumerator)) {
            scale /= 10;
            break;
        }
        scale *= 10;
    }

    bigNumerator *= (scale * scale);

    // if (std::numeric_limits<long long>::max() / SCALE < SCALE) {
    //     if (debugMode) {
    //         std::cout << "SCALE * SCALE affects long long overflow\n";
    //     }
    //     throw LongLongOverflowException();
    // }
    // if ((std::numeric_limits<long long>::max() / bigNumerator) < (SCALE * SCALE)) {
    //     if (debugMode) {
    //         std::cout << "numerator * denominator * SCALE * SCALE affects long long overflow\n";
    //     }
    //     throw LongLongOverflowException();
    // }
    // bigNumerator *= SCALE * SCALE;

    if (debugMode) {
        std::cout << "scale = " << scale << "\n";
        std::cout << "bigNumerator = " << bigNumerator << "\n";
    }

    if (std::numeric_limits<long long>::max() - 1 < bigNumerator) {
        if (debugMode) {
            std::cout << "bigNumerator + 1 affects long long overflow\n";
        }
        throw LongLongOverflowException();
    }
    long long entryN = bigNumerator;
    long long entryNPlusOne = (entryN + 1) / 2;
    while (entryNPlusOne < entryN) {
        entryN = entryNPlusOne;
        entryNPlusOne = (entryN + bigNumerator / entryN) / 2;
    }
    long long bigNumeratorSqrt = entryN;

    // if (std::numeric_limits<long long>::max() / absDenominator < SCALE) {
    //     if (debugMode) {
    //         std::cout << "denominator * SCALE causes long long overflow\n";
    //     }
    //     throw LongLongOverflowException();
    // }
    numerator_ = bigNumeratorSqrt;
    denominator_ *= scale;
    reduct();
    if (debugMode) {
        std::cout << "Result of sqrt():\n";
        std::cout << *this << "\n";
        std::cout << "--------------\n\n";
    }
    return *this;
}

bool Rational::isPositive() const {
    return (numerator_ > 0ll && denominator_ > 0ll) || (numerator_ < 0ll && denominator_ < 0ll);
}

bool Rational::isNotNegative() const {
    return (numerator_ >= 0ll && denominator_ > 0ll) || (numerator_ <= 0ll && denominator_ < 0ll);
}

Rational& Rational::operator=(const Rational& other) {
    if (this != &other) {
        Rational otherCopy = Rational(other);
        swap(otherCopy);
    }
    return *this;
}

Rational& Rational::operator=(Rational&& other) noexcept {
    if (this != &other) {
        numerator_ = other.numerator_;
        denominator_ = other.denominator_;
    }
    return *this;
}


Rational& Rational::operator+=(const Rational& other) {
    long long lcm = getLCM(denominator_, other.denominator_);
    long long firstMultiplier = lcm / denominator_;
    long long secondMultiplier = lcm / other.denominator_;

    long long absNumerator = numerator_ < 0 ? -numerator_ : numerator_;
    long long absOtherNumerator = other.numerator_ < 0 ? -other.numerator_ : other.numerator_;
    long long absFirstMultiplier = firstMultiplier < 0 ? -firstMultiplier : firstMultiplier;
    long long absSecondMultiplier = secondMultiplier < 0 ? -secondMultiplier : secondMultiplier;
    if ((std::numeric_limits<long long>::max() / absNumerator < absFirstMultiplier) ||
        (std::numeric_limits<long long>::max() / absOtherNumerator < absSecondMultiplier) ||
        (std::numeric_limits<long long>::max() - (absNumerator * absFirstMultiplier) < (absOtherNumerator * absSecondMultiplier))) {
        throw LongLongOverflowException();
    }

    numerator_ = (numerator_ * firstMultiplier) + (other.numerator_ * secondMultiplier);
    denominator_ = lcm;
    reduct();
    return *this;
}

Rational Rational::operator+(const Rational& other) const {
    Rational copy(*this);
    return copy += other;
}

Rational& Rational::operator-=(const Rational& other) {
    long long lcm = getLCM(denominator_, other.denominator_);
    long long firstMultiplier = lcm / denominator_;
    long long secondMultiplier = lcm / other.denominator_;

    long long absNumerator = numerator_ < 0 ? -numerator_ : numerator_;
    long long absOtherNumerator = other.numerator_ < 0 ? -other.numerator_ : other.numerator_;
    long long absFirstMultiplier = firstMultiplier < 0 ? -firstMultiplier : firstMultiplier;
    long long absSecondMultiplier = secondMultiplier < 0 ? -secondMultiplier : secondMultiplier;
    if ((std::numeric_limits<long long>::max() / absNumerator < absFirstMultiplier) ||
        (std::numeric_limits<long long>::max() / absOtherNumerator < absSecondMultiplier) ||
        (std::numeric_limits<long long>::max() - (absNumerator * absFirstMultiplier) < (absOtherNumerator * absSecondMultiplier))) {
        throw LongLongOverflowException();
    }

    numerator_ = (numerator_ * firstMultiplier) - (other.numerator_ * secondMultiplier);
    denominator_ = lcm;
    reduct();
    return *this;
}

Rational Rational::operator-(const Rational& other) const {
    Rational copy(*this);
    return copy -= other;
}

Rational& Rational::operator*=(const Rational& other) {
    long long absNumerator = numerator_ < 0 ? -numerator_ : numerator_;
    long long absOtherNumerator = other.numerator_ < 0 ? -other.numerator_ : other.numerator_;
    long long absDenominator = denominator_ < 0 ? -denominator_ : denominator_;
    long long absOtherDenominator = other.denominator_ < 0 ? -other.denominator_ : other.denominator_;

    if ((std::numeric_limits<long long>::max() / absNumerator < absOtherNumerator) ||
        (std::numeric_limits<long long>::max() / absDenominator < absOtherDenominator)) {
        throw LongLongOverflowException();
    }

    numerator_ *= other.numerator_;
    denominator_ *= other.denominator_;
    reduct();
    return *this;
}

Rational Rational::operator*(const Rational& other) const {
    Rational copy(*this);
    return copy *= other;
}
    
Rational& Rational::operator/=(const Rational& other) {
    long long absNumerator = numerator_ < 0 ? -numerator_ : numerator_;
    long long absOtherNumerator = other.numerator_ < 0 ? -other.numerator_ : other.numerator_;
    long long absDenominator = denominator_ < 0 ? -denominator_ : denominator_;
    long long absOtherDenominator = other.denominator_ < 0 ? -other.denominator_ : other.denominator_;

    if ((std::numeric_limits<long long>::max() / absNumerator < absOtherDenominator) ||
        (std::numeric_limits<long long>::max() / absDenominator < absOtherNumerator)) {
        throw LongLongOverflowException();
    }

    numerator_ *= other.denominator_;
    denominator_ *= other.numerator_;
    reduct();
    return *this;
}

Rational Rational::operator/(const Rational& other) const {
    Rational copy(*this);
    return copy /= other;
}

bool Rational::operator==(const Rational& other) const {
    return numerator_ == other.numerator_ && 
        denominator_ == other.denominator_;
}

bool Rational::operator!=(const Rational& other) const {
    return !((*this) == other);
}

bool Rational::operator<(const Rational& other) const {
    return (numerator_ * other.denominator_) < (other.numerator_ * denominator_);
}

bool Rational::operator<=(const Rational& other) const {
    return ((*this) < other) || ((*this) == other);
}

bool Rational::operator>(const Rational& other) const {
    return (numerator_ * other.denominator_) > (other.numerator_ * denominator_);
}

bool Rational::operator>=(const Rational& other) const {
    return ((*this) > other) || ((*this) == other);
}

Rational::operator int() const {
    return static_cast<int>(numerator_ / denominator_);
}

Rational::operator double() const {
    double numeratorDouble = static_cast<double>(numerator_);
    return numeratorDouble / denominator_;
}

Rational::operator long long() const {
    return numerator_ / denominator_;
}

std::istream& operator>>(std::istream& is, Rational& rational) {
    std::istream::sentry s(is);
    if (!s) {
        return is;
    }
    

    int denominator = 0;
    int numerator = 0;

    is >> numerator;
    is >> denominator;

    if (denominator == 0) {
        throw std::runtime_error("Division by zero");
    } 

    rational.numerator_ = numerator;
    rational.denominator_ = denominator;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Rational& rational) {
    std::ostream::sentry s(os);
    if (!s) {
        return os;
    }
    os << rational.getNumerator() << "/" << rational.getDenominator();
    return os;
}
    
