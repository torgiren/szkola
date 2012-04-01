CXXFLAGS=-Wall -O3
LDFLAGS=-lpthread
main: main.o
	g++ $^ -o $@ ${LDFLAGS}
main.o: main.cpp
	g++ -c $^ -o $@ ${CXXFLAGS}
clean:
	rm -f *.o main
leak: main
	valgrind ./$^
