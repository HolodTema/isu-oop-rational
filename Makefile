# C++ compiler
CXX = g++


# compiler flags
# CXXFLAGS = -std=c++11


# target file - the file of our program
TARGET = main


# source c++ files
SOURCES = main.cpp Rational.hpp Rational.cpp gcd.cpp gcd.hpp


# default makefile rule
all: 
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)


# if we clean project, we delete all the .o files and executable-file
clean:
	rm -f $(TARGET)


# .PHONY means that these targets are not files
.PHONY: all clean

