CFLAGS=-Wall -g
CC=gcc
LDFLAGS=-g
all: main

main: main.o
	${CC} $^ -o $@ ${LDFLAGS}
main.o: main.c
	${CC} $^ -c ${CFLAGS}
