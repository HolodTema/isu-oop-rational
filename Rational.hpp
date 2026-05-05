#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iosfwd>
#include "exceptions.hpp"

class Rational {
private:
    long long numerator_;
    long long denominator_;

    void swap(Rational& other) noexcept;

    
    friend std::istream& operator>>(std::istream& is, Rational& rational);

public:

    Rational():
        numerator_(0ll),
        denominator_(1ll)
    {

    }

    explicit Rational(long long numerator):
        numerator_(numerator),
        denominator_(1ll)
    {

    }

    Rational(long long numerator, long long denominator):
        numerator_(numerator)
    {
        if (denominator == 0) {
            throw DivisionByZeroException();
        }
        denominator_ = denominator;
    }

    Rational(const Rational& other):
        numerator_(other.numerator_),
        denominator_(other.denominator_)
    {
    
    }

    Rational(Rational&& other) noexcept:
        numerator_(other.numerator_),
        denominator_(other.denominator_)
    {

    }

    void reduct();

    void reduct(long long gcd);

    long long getNumerator() const;

    long long getDenominator() const;

    Rational& pow(int n);

    Rational& sqrt(bool debugMode);

    bool isPositive() const;

    bool isNotNegative() const;

    Rational& operator=(const Rational& other);

    Rational& operator=(Rational&& other) noexcept;

    Rational& operator+=(const Rational& other);

    Rational operator+(const Rational& other) const;

    Rational& operator-=(const Rational& other);

    Rational operator-(const Rational& other) const;

    Rational& operator*=(const Rational& other);
    
    Rational operator*(const Rational& other) const;

    Rational& operator/=(const Rational& other);

    Rational operator/(const Rational& other) const;

    bool operator==(const Rational& other) const;

    bool operator!=(const Rational& other) const;

    bool operator<(const Rational& other) const;
    
    bool operator<=(const Rational& other) const;

    bool operator>(const Rational& other) const;

    bool operator>=(const Rational& other) const;

    operator int() const;

    operator long long() const;

    operator double() const;
};

std::istream& operator>>(std::istream& is, Rational& rational);

std::ostream& operator<<(std::ostream& os, const Rational& rational);


#endif
