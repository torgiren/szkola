C=mpicc.mpich
RUN=mpirun.mpich
CFLAGS=-Wall
LDFLAGS=-lmpe -lX11 -lm
SPRNG_LDFLAGS=-lsprng -L/usr/local/soft/sprng2.0/lib
SPRNG_CFLAGS=-I/usr/local/soft/sprng2.0/EXAMPLES -I/usr/local/soft/sprng2.0/include
RUN_OPTS=-np 4 -machinefile machines

main: main.o
	$C $^ -o $@ ${LDFLAGS}
main.o: main.c
	$C $^ -c ${CFLAGS}
run:
	${RUN} ${RUN_OPTS} ./main 0.0001
clean:
	rm -f main *.o
xnest:
	Xnest -ac -scrns 1 :1

mc_pi_sprng: mc_pi_sprng.o
	$C $^ -o $@ ${SPRNG_LDFLAGS} ${LDFLAGS}
mc_pi_sprng.o: mc_pi_sprng.c
	$C $^ -c ${SPRNG_CFLAGS} ${CFLAGS}
run_mc_pi_sprng:
	${RUN} ${RUN_OPTS} ./mc_pi_sprng 0.0001

#	mpicc.mpich -o sprng_mpi sprng_mpi.c -I/usr/local/soft/sprng2.0/include -I/usr/local/soft/sprng2.0/EXAMPLES -L/usr/local/soft/sprng2.0/lib -lsprng
