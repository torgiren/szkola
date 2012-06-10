CXX=g++
CXXFLAGS=-Wall
LDFLAGS=-lga
all: main
	
main: main.o
	${CXX} $^ -o $@ ${LDFLAGS}
main.o: main.cpp
	${CXX} $^ -c ${CXXFLAGS}

clean:
	rm -f *.o
.PNONY: clean
