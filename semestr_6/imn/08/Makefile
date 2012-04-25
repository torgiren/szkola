CFLAGS=-Wall -g
all: main
	
main: main.o
	gcc $^ -o $@ $(LDDFLAGS)
main.o: main.c
	gcc $^ -c $(CFLAGS)
clean:	
	rm -f main.o
.PHONY: clean
