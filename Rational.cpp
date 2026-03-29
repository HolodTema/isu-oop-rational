#include "Rational.hpp"
#include <iostream>
#include "gcd.hpp"


void Rational::swap(Rational& other) {
    std::swap(numerator_, other.numerator_);
    std::swap(denominator_, other.denominator_);
}

void Rational::reduct() {
    int gcd = gcd(numerator_, denominator_);
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

Rational& operator=(Rational&& other) noexcept {
    numerator_ = other.numerator_;
    denominator_ = other.denominator_;
}


Rational& operator+=(const Rational& other) {

}

Rational operator+(const Rational& other) const {

}

    Rational& operator-=(const Rational& other);

    Rational operator-(const Rational& other) const;

    Rational& operator*=(const Rational& other);
    
    Rational operator*(const Rational& other) const;

    Rational& operator/=(const Rational& other);

    Rational operator/(const Rational& other) const;

bool Rational::operator==(const Rational& other) const {
    return numerator_ == other.numerator_ && 
        denominator_ == other.denominator_;
}

    bool Rational::operator!=(const Rational& other) const {
        return !((*this) == other);
    }

    bool operator<(const Rational& other) const;
    
    bool operator<=(const Rational& other) const;

    bool operator>(const Rational& other) const;

    bool operator>=(const Rational& other) const;

Rational::operator double() const {
    numeratorDouble = static_cast<double>(numerator_);
    return numeratorDouble / denominator_;
}

