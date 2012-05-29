CXX=g++
CXXFLAGS=-Wall -g -O3
LDFLAGS=-lga -g
all: main

main: main.o
	${CXX} $^ -o $@ ${LDFLAGS}
main.o: main.cpp
	${CXX} $^ -c ${CXXFLAGS}
clean:
	rm -f *.o
