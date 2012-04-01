C=mpicc.mpich
RUN=mpirun.mpich
CFLAGS=-Wall
LDFLAGS=
hello: hello.o
	$C $^ -o $@ ${LDFLAGS}
hello.o: hello.c
	$C $^ -c ${CFLAGS}
run:
	${RUN} -np 6 -machinefile machines ./hello
clean:
	rm -f hello *.o
