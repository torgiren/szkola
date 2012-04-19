C=mpicc.mpich
RUN=mpirun.mpich
CFLAGS=-Wall
LDFLAGS=-lmpe
main: main.o
	$C $^ -o $@ ${LDFLAGS}
main.o: main.c
	$C $^ -c ${CFLAGS}
run:
	${RUN} -np 4 -machinefile machines ./main 0.00001
clean:
	rm -f main *.o
