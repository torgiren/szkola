CXX=g++
CXXFLAGS=-Wall -g
LDFLAGS=-lga -g
all: main

main: main.o
	${CXX} $^ -o $@ ${LDFLAGS}
main.o: main.cpp
	${CXX} $^ -c ${CXXFLAGS}
