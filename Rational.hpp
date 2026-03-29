#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iosfwd>

class Rational {
private:
    int numerator_;
    int denominator_;

    void swap(Rational& other) noexcept;

    void reduct();

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

    Rational(int numerator, int denominator_):
        numerator_(numerator)
    {

    }

    Rational(Rational& other)
        numerator_(other.numerator_),
        denominator_(other.denominator_)
    {
    
    }

    Rational(Rational&& other) noexcept:
        numerator_(other.numerator),
        denominator_(other.denominator_)
    {

    }

    int getNumerator() const;

    int getDenominator() const;

    Rational& operator=(Rational& other);

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

    operator double() const;
};


std::ostream operator<<(std::ostream& os, const Rational& rational);


#endif
