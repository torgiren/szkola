main: main.c
	gcc main.c -o main -I/usr/include/postgresql/ -lecpg
main.c: main.pgc
	ecpg main.pgc
clean:
	rm *.c
