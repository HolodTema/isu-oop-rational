#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

class LongLongOverflowException : public std::exception {
public:

	const char * what() const noexcept override {
		return "Error: long long data type overflow.";
	}

};

class DivisionByZeroException : public std::exception {
public:

	const char * what() const noexcept override {
		return "Error: division by zero.";
	}

};

class NegativeSquareRootException : public std::exception {
public:

	const char * what() const noexcept override {
		return "Error: unable to get sqrt() from negative number.";
	}

};

#endif
