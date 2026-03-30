#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iosfwd>
#include <stdexcept>

class Rational {
private:
    int numerator_;
    int denominator_;

    void swap(Rational& other) noexcept;

    void reduct();
    
    friend std::istream& operator>>(std::istream& is, Rational& rational);

public:

    Rational():
        numerator_(0),
        denominator_(1)
    {

    }

    Rational(int numerator):
        numerator_(numerator),
        denominator_(1)
    {

    }

    Rational(int numerator, int denominator):
        numerator_(numerator)
    {
        if (denominator == 0) {
            throw std::runtime_error("Division by zero");
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

    int getNumerator() const;

    int getDenominator() const;

    Rational& pow(int n);

    double getSqrt() const;

    Rational& sqrt(bool debugMode);

    bool isPositive() const;

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

    operator double() const;
};

std::istream& operator>>(std::istream& is, Rational& rational);

std::ostream& operator<<(std::ostream& os, const Rational& rational);


#endif
