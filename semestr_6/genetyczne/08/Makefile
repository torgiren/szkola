CXX=g++
CC=gcc
CXXFLAGS=-Wall -Wextra -g 
LDFLAGS=-g -lga -lm
all: main analiza opis
main: main.o
	$(CXX) $^ StaticLib.o -o $@ $(LDFLAGS)
main.o: main.cpp
	$(CXX) $^ -c $(CXXFLAGS)
analiza: analiza.o
	$(CXX) $^ StaticLib.o -o $@ ${LDFLAGS}
analiza.o: analiza.c
	${CXX} $^ -c ${CXXFLAGS}
opis: opis.tex
	pdflatex $^

clean:
	rm -rf `ls *.o|grep -v StaticLib.o`

.PHONY: clean opis
