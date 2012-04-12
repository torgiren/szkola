C=mpicc.mpich
RUN=mpirun.mpich
CFLAGS=-Wall
LDFLAGS=-lmpe -lX11 -lm
main: main.o
	$C $^ -o $@ ${LDFLAGS}
main.o: main.c
	$C $^ -c ${CFLAGS}
run:
	${RUN} -np 4 -machinefile machines ./main 0.0001
clean:
	rm -f main *.o
xnest:
	Xnest -ac -scrns 1 :1
