LDFLAGS=-pthread -g
CXXFLAGS=-Wall -O2 -g
main:	main.o logger.o client.o kaziu.o strzelnica.o
	g++ $^ -o main ${LDFLAGS}
main.o: main.cpp
	g++ main.cpp -c ${CXXFLAGS}
logger.o: logger.h logger.cpp
	g++ logger.cpp -c ${CXXFLAGS}
client.o: client.h client.cpp
	g++ client.cpp -c ${CXXFLAGS}
kaziu.o: kaziu.h kaziu.cpp
	g++ kaziu.cpp -c ${CXXFLAGS}
strzelnica.o: strzelnica.cpp strzelnica.h
	g++ strzelnica.cpp -c ${CXXFLAGS}
docs:
	doxygen -g
	doxygen Doxyfile
clean:
	rm -f *.o
