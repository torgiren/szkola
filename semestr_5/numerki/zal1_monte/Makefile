CXXFLAGS=-Wall -I/home/labs/komputerowe_symulacje_numeryczne/numerical_recipes.c -g
main: main.o
	g++ main.o -o main ${CXXFLAGS}
main.o: main.cpp
	g++ -c main.cpp -o main.o ${CXXFLAGS}
clean:
	rm -f *.o
