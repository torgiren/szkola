main: random.o SGA_01.o SGA_Facade.o mysga.o
	g++ $^ -o $@ -O3
random.o: random.cpp random.h
	g++ -c random.cpp
SGA_01.o: SGA_01.cpp
	g++ -c SGA_01.cpp
SGA_Facade.o: SGA_Facade.cpp SGA_Facade.h
	g++ -c SGA_Facade.cpp
SGA_mysga.o: mysga.h mysga.cpp
	g++ -c mysga.cpp
rozklad: rozklad.o
	g++ $^ -o $@
rozklad.o: rozklad.cpp
	g++ -c $^ -Wall
clean:
	rm -f *.o main
