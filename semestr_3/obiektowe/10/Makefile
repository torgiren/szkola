program: main.o vector.o matrix.o
	g++ main.o vector.o matrix.o -o main
main.o:	main.cpp
	g++ -c main.cpp -g
vector.o: vector.cpp
	g++ -c vector.cpp -g
matrix.o: matrix.cpp
	g++ -c matrix.cpp -g
clean:
	rm -f *.o
