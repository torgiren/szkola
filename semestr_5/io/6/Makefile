LDFLAGS= -g
CXXFLAGS=-Wall -O2 -g
main:	main.o dzialanie.o dodaj.o odejmij.o
	g++ $^ -o main ${LDFLAGS}
main.o: main.cpp
	g++ main.cpp -c ${CXXFLAGS}
dzialanie.o: dzialanie.cpp dzialanie.h
	g++ $^ -c ${CXXFLAGS}
dodaj.o: dodaj.cpp dodaj.h
	g++ $^ -c ${CXXFLAGS}
odejmij.o: odejmij.cpp odejmij.h
	g++ $^ -c ${CXXFLAGS}
docs:
	doxygen -g
	doxygen Doxyfile
clean:
	rm -f *.o *.gch
