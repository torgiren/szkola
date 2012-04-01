lab07: main.o lab06.o
	g++ lab06.o main.o -o main
main.o: main.cpp
	g++ -g -c -Wall $^
lab06.o: lab06.cpp
	g++ -g -c -Wall $^
clean:
	rm -f *.o
