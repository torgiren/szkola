prog: main.o cwym.o ctabwym.o
	g++ main.o cwym.o ctabwym.o -o main
main.o: main.cpp
	g++ main.cpp -c
cwym.o: cwym.cpp cwym.h
	g++ cwym.cpp -c
ctabwym.o: ctabwym.cpp ctabwym.h
	g++ ctabwym.cpp -c
clean:
	rm -f *.o
