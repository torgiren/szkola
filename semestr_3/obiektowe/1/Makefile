proba: main.o drugi.o trzeci.o
	g++ -g $^ -o main
main.o: main.cpp
	g++ -c -g main.cpp
drugi.o: drugi.cpp drugi.h
	g++ -c -g drugi.cpp 
trzeci.o: trzeci.cpp trzeci.h
	g++ -c -g trzeci.cpp

clean:
	rm *.o
