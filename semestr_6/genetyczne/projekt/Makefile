CXX=g++
CXXFLAGS=-Wall -O3
LDFLAGS=
LDFLAGS_main=-l ga
LDFLAGS_rys=-l gd
all: main rys

main: main.o
	$(CXX) $^ -o $@ $(LDFLAGS_main) $(LDFLAGS)
main.o: main.cpp
	$(CXX) $^ -c $(CXXFLAGS)
rys: rys.o
	$(CXX) $^ -o $@ ${LDFLAGS} $(LDFLAGS_rys)
rys.o: rys.cpp
	$(CXX) $^ -c $(CXXFLAGS)
