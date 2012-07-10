CXX=g++
CXXFLAGS=-Wall -O2
LDFLAGS=-l ga
all: main

main: main.o
	$(CXX) $^ -o $@ $(LDFLAGS)
main.o: main.cpp
	$(CXX) $^ -c $(CXXFLAGS)
