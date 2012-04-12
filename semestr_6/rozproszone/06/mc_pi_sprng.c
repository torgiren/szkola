/* ======================================================================== 
 *   mc_pi_sprng.c                                                         
 *   MPI program for calculating Pi by Monte Carlo estimation               
 *   TEST VERSTON !
 *           ____Demonstrates the use of make_seed with MPI____            
 * 'make_sprng_seed' is called to produce a new seed each time the program 
 * is run. The same seed is produced on each process.                      
 * ======================================================================== */
/***
   * Fatcat MPICH compilation: 
   *    mpicc.mpich -o mc_pi_sprng mc_pi_sprng.c -lm
   * Fatcat MPICH example execution:
   *    mpirun.mpich -machinefile machines.txt -np 3 ./mc_pi_sprng 0.000001
   */

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "mpi.h"
/* Uncomment the following line to get the interface with pointer checking */
/*#define CHECK_POINTERS                                                   */
#define USE_MPI                 /* SPRNG makes MPI calls                   */
#include "sprng.h"              /* SPRNG header file                       */
#define SEED 	  985456376
#define THROW_MAX 1.0E+10 
#define PI        3.141592653589793238462643
#define CHUNKSIZE 10000

int main( int argc, char *argv[] )
{
    int numprocs, myid, i, iter, done, seed, nstreams, *stream;
    double in, out, totalin, totalout;
    double x, y, Pi, error, epsilon;
    MPI_Comm world, workers;
    MPI_Group world_group, worker_group;
    MPI_Status status;

    MPI_Init( &argc, &argv );
    world  = MPI_COMM_WORLD;
    MPI_Comm_size( world, &numprocs );
    MPI_Comm_rank( world, &myid );

/***
   * Now Master should read epsilon from command line
   * and distribute it to all processes.
   */
    if (myid == 0)  // Read epsilon from command line 
        sscanf( argv[1], "%lf", &epsilon );
    MPI_Bcast( &epsilon, 1, MPI_DOUBLE, 0, world );

/* Demonstrates sprng use with one stream per process */
    nstreams = numprocs;		/* one stream per processor                */
    seed = make_sprng_seed();	/* make new seed each time program is run  */
//    MPI_Bcast( &seed, 1, MPI_INT, 0, world );
/* Seed should be the same on all processes                              */
    printf("Process %d: seed = %16d\n", myid, seed);
    stream = init_sprng(0,myid,nstreams,seed,SPRNG_DEFAULT); // initialize stream 
    if (myid == 0)  // example
              print_sprng(stream);

/***
   * Workers (including Master) part
   *
   * Later, in a loop worker should:
   * - generate vector of randoms
   * - compute x,y point inside unit square
   * - check (and count result) if point is inside/outside 
   *   unit circle
   * - sum both counts over all workers
   * - calculate pi and its error (from "exact" value)
   * - test if error is within epsilon limit
   * - test continuation condition (error and max. points limit)
   * - print pi by master only
   */ 

	done = 0; 
	in = out = 0.0;
	iter = 0;
	while (!done) {
	    iter++;
	    for (i = 0; i < CHUNKSIZE; i++) {
              // generate double precision random number
	      x = ( sprng(stream) ) * 2 - 1;
	      y = ( sprng(stream) ) * 2 - 1;
	      if ( x*x + y*y < 1.0 ) 
	          in++;
              else
    	          out++;
            }
	    MPI_Allreduce( &in, &totalin, 1, MPI_DOUBLE, MPI_SUM, world );
	    MPI_Allreduce( &out, &totalout, 1, MPI_DOUBLE, MPI_SUM, world );
	    Pi = ( 4.0 * totalin ) / ( totalin + totalout );
	    error = fabs( Pi - PI );
	    done = ( error < epsilon || (totalin + totalout) > THROW_MAX );
	    if (myid == 0)  printf( "\riter= %d, pi = %23.20f", iter, Pi );
	}

/***
   * Master should print final point counts.
   */
    if (myid == 0) {
        printf( "\npoints: %lf\nin: %lf, out: %lf, <ret> to exit\n",
	       totalin+totalout, totalin, totalout );
	getchar();
    }

    free_sprng(stream);	 // free memory used to store stream state
    MPI_Finalize();
}
