CXXFLAGS=-Wall -O3
main: main.o
	g++ $^ -o $@ ${LDFLAGS}
main.o: main.cpp
	g++ $^ -c ${CXXFLAGS}

clean:
	rm -f main.o main
