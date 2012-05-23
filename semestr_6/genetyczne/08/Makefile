CXX=g++
CC=gcc
CXXFLAGS=-Wall -Wextra -g 
LDFLAGS=-g -lga -lm
all: main analiza
main: main.o
	$(CXX) $^ StaticLib.o -o $@ $(LDFLAGS)
main.o: main.cpp
	$(CXX) $^ -c $(CXXFLAGS)
analiza: analiza.o
	$(CXX) $^ StaticLib.o -o $@ ${LDFLAGS}
analiza.o: analiza.c
	${CXX} $^ -c ${CXXFLAGS}

clean:
	rm -rf `ls *.o|grep -v StaticLib.o`

.PHONY: clean
