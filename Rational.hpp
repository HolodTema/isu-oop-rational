#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iosfwd>

class Rational {
private:
    int numerator_;
    int denominator_;

    void swap(Rational& other) noexcept;

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

    Rational(Rational& other) {

    }

    Rational(Rational&& other) noexcept {

    }


    Rational& operator+=(const Rational& other)

    

};


std::ostream operator<<(std::ostream& os, const Rational& rational);


#endif
