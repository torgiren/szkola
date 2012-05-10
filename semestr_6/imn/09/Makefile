LDFLAGS=
CFLAGS=-Wall -O2 
all: main

main: main.o
	gcc $^ -o $@ $(LDFLAGS)
main.o: main.c
	gcc -c $^ $(CFLAGS)
clean:
	rm -rf main.o
distclean: clean
	rm -rf main

.PHONY: clean distclean
