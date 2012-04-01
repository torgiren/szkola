program: main.o ctext.o
	g++ main.o ctext.o -o main
main.o: main.cpp
	g++ main.cpp -c
ctext.o: ctext.cpp ctext.h
	g++ ctext.cpp -c
