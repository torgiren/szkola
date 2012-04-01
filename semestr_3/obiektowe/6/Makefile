CXXFLAGS=-Wall -pipe -fomit-frame-pointer
obiektowe: main.o figura.o kwadrat.o prostokat.o kolo.o trojkat.o
	g++ ${CXXFLAGS} $^ -o main
main.o: main.cpp
	g++ -c ${CXXFLAGS} main.cpp
figura.o: figura.cpp
	g++ -c ${CXXFLAGS} figura.cpp
kwadrat.o: kwadrat.cpp
	g++ -c ${CXXFLAGS} kwadrat.cpp
prostokat.o: prostokat.cpp
	g++ -c ${CXXFLAGS} prostokat.cpp
kolo.o: kolo.cpp
	g++ -c ${CXXFLAGS} kolo.cpp
trojkat.o: trojkat.cpp
	g++ -c ${CXXFLAGS} trojkat.cpp

clean:
	rm -f *.o
