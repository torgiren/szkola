C=mpicc.mpich
RUN=mpirun.mpich
CFLAGS=-Wall
LDFLAGS=-lmpe -lX11 -lm -mpianim
main: main.o
	$C $^ -o $@ ${LDFLAGS}
main.o: main.c
	$C $^ -c ${CFLAGS}
run:
	${RUN} -np 6 -machinefile machines ./main 0.0001
clean:
	rm -f main *.o
