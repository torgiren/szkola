all: main.o cwektor.o
	g++ main.o cwektor.o -o main -Wall
main.o: main.cpp
	g++ -c main.cpp
cwektor.o: cwektor.cpp
	g++ -c cwektor.cpp
clean:
	rm -f *.o
