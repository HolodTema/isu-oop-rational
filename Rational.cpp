#include "Rational.hpp"
#include <iostream>
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

Rational& Rational::operator=(Rational& other) {
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
    
