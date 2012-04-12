CXX=g++
CXXFLAGS=-Wall
LDFLAGS=
main: main.o
	${CXX} $^ -o $@ ${LDFLAGS}
main.o: main.cpp
	${CXX} $^ -c ${CXXFLAGS}
run:
	./main
clean:
	rm -rf *.o
