CXX=g++
CXXFLAGS=-Wall -Wextra -g
LDFLAGS=-g -lga
all: main
main: main.o
	$(CXX) $^ -o $@ $(LDFLAGS)
main.o: main.cpp
	$(CXX) $^ -c $(CXXFLAGS)
	
