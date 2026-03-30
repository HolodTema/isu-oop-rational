#include "Rational.hpp"
#include <iostream>
#include <limits>
#include "gcd.hpp"


void Rational::swap(Rational& other) noexcept {
    std::swap(numerator_, other.numerator_);
    std::swap(denominator_, other.denominator_);
}

void Rational::reduct() {
    int gcd = getGCD(numerator_, denominator_);
    numerator_ /= gcd;
    denominator_ /= gcd;
}

int Rational::getNumerator() const {
    return numerator_;
}

int Rational::getDenominator() const {
    return denominator_;
}

Rational& Rational::pow(int n) {
    if (n == 0) {
        numerator_ = 1;
        denominator_ = 1;
        return *this;
    }

    bool negativePower = (n < 0);
    int absN = (n < 0) ? -n : n;
    
    Rational result(1, 1);
    Rational base = *this;
    
    for (int i = 0; i < absN; ++i) {
        result *= base;
    }
    
    // if pow is negative, we swap numerator and denominator
    if (negativePower) {
        if (result.numerator_ == 0) {
            throw std::runtime_error("Division by zero in negative power");
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

    double result = rationalDouble;
    for (int i = 0; i < 10; ++i) {
        result = 0.5 * (result + rationalDouble / result);
    }
    return result;
}


Rational& Rational::sqrt() {
    constexpr int NUMERATOR_COEFF = 1000000;
    constexpr int GERON_ITERATIONS_NUMBER = 10;

    if (!isPositive()) {
        throw std::runtime_error("Unable to get square root from negative value");
    }
    
    if (numerator_ > std::numeric_limits<int>::max() / NUMERATOR_COEFF) {
        throw std::runtime_error("Integer max value overflow");
    }

    long long bigNumerator = static_cast<long long>(numerator_) * NUMERATOR_COEFF;
    long long  resultNumerator = bigNumerator;

    for (int i = 0; i < GERON_ITERATIONS_NUMBER; ++i) {
        resultNumerator = (resultNumerator + bigNumerator / resultNumerator) / 2;
    }

    numerator_ = static_cast<int>(resultNumerator);
    denominator_ = NUMERATOR_COEFF;

    reduct();
    return *this;
}


bool Rational::isPositive() const {
    return (numerator_ > 0 && denominator_ > 0) || (numerator_ < 0 && denominator_ < 0);
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
    numerator_ = (numerator_ * other.denominator_) + (other.numerator_ * denominator_);
    denominator_ *= other.denominator_;
    reduct();
    return *this;
}

Rational Rational::operator+(const Rational& other) const {
    Rational copy(*this);
    return copy += other;
}

Rational& Rational::operator-=(const Rational& other) {
    numerator_ = (numerator_ * other.denominator_) - (other.numerator_ * denominator_);
    denominator_ *= other.denominator_; 
    reduct();
    return *this;
}

Rational Rational::operator-(const Rational& other) const {
    Rational copy(*this);
    return copy -= other;
}

Rational& Rational::operator*=(const Rational& other) {
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
    return numerator_ / denominator_;
}

Rational::operator double() const {
    double numeratorDouble = static_cast<double>(numerator_);
    return numeratorDouble / denominator_;
}

std::istream& operator>>(std::istream& is, Rational& rational) {
    std::istream::sentry s(is);
    if (!s) {
        return is;
    }
    is >> rational.numerator_;
    is >> rational.denominator_;
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
    
