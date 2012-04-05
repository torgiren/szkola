C=mpicc.mpich
RUN=mpirun.mpich
CFLAGS=-Wall
LDFLAGS=
main: main.o
	$C $^ -o $@ ${LDFLAGS}
main.o: main.c
	$C $^ -c ${CFLAGS}
run:
	${RUN} -np 6 -machinefile machines ./main
clean:
	rm -f main *.o
