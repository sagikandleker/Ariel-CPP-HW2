CXX=g++
CXXFLAGS=-std=c++11

all: 
	$(CXX) $(CXXFLAGS) Main.cpp CircularInt.hpp -o a.out
	./a.out
