
# C++ compiler
CXX = g++

# compiler flags
# CXXFLAGS = -std=c++11

# target file - the file of our program
TARGET = main

# source c++ files
SOURCES = main.cpp Rational.hpp Rational.cpp

# object files (.o format)
OBJECTS = $(SOURCES:.cpp=.o)

# default makefile rule
all: $(TARGET)

# build program from .o object-files
# actually .o files are already compiled
# so, we link .o files into the executable file
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# build object files from .cpp
# $< means first file of the dependency
# $@ means target file .o
# g++ flag -c means only compilation, without linking
%.o %.cpp Rational.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# if we clean project, we delete all the .o files and executable-file
clean:
	rm -rf $(OBJECTS) $(TARGET)

# .PHONY means that these targets are not files
.PHONY all clean

# usage:
# make 
# make clean
