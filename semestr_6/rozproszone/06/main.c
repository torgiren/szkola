/* ======================================================================== */
/*   mc_pi_serv.c                                                                */
/*   MPI program for calculating Pi by Monte Carlo estimation               */
/* ======================================================================== */
/***
 * Fatcat MPICH compilation: 
 *    mpicc.mpich -o mcpi mcpi.c -lm
 * Fatcat MPICH example execution:
 *    mpirun.mpich -machinefile machines.txt -np 3 ./mcpi 0.000001
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"
#include <mpe.h>
#include <mpe_graphics.h>
#define WINDOW_SIZE 400
#define CHUNKSIZE 10000
/* We'd like a value that gives the maximum value returned by the function
   random, but no such value is *portable*.  RAND_MAX is available on many 
   systems but is not always the correct value for random (it isn't for 
   Solaris).  The value ((unsigned(1)<<31)-1) is common but not guaranteed */
#define INT_MAX   1000000000
#define THROW_MAX 100000000
#define PI        3.141592653589793238462643
/* message tags */
#define REQUEST   1
#define REPLY     2

int main( int argc, char *argv[] )
{
	int numprocs, myid, server, workerid, ranks[1], 
		request, i, iter, ix, iy, done;
	long rands[CHUNKSIZE], max, in, out, totalin, totalout;
	double x, y, Pi, error, epsilon;
	MPI_Comm world, workers;
	MPI_Group world_group, worker_group;
	MPI_Status status;

	MPI_Init( &argc, &argv );
	world  = MPI_COMM_WORLD;
	MPI_Comm_size( world, &numprocs );
	MPI_Comm_rank( world, &myid );
	server = numprocs-1;	// Last process is a random server 

	/***
	 * Now Master should read epsilon from command line
	 * and distribute it to all processes.
	 */
	if (myid == 0)  // Read epsilon from command line 
		sscanf( argv[1], "%lf", &epsilon );
	MPI_Bcast( &epsilon, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD );

	/***
	 * Create new process group called world_group containing all 
	 * processes and its communicator called world
	 * and a group called worker_group containing all processes
	 * except the last one (called here server) 
	 * and its communicator called workers.
	 */
	MPI_Comm_group( world, &world_group );
	ranks[0] = server;
	MPI_Group_excl( world_group, 1, ranks, &worker_group );
	MPI_Comm_create( world, worker_group, &workers );
	MPI_Group_free( &worker_group );

	MPE_XGraph graph;
	MPE_Open_graphics(&graph,MPI_COMM_WORLD,(char*)0, -1,-1,WINDOW_SIZE,WINDOW_SIZE,MPE_GRAPH_INDEPENDENT);




	/***
	 * Server part
	 *
	 * Server should loop until request code is 0, in each iteration:
	 * - receiving request code from any slave
	 * - generating a vector of CHUNKSIZE randoms <= INT_MAX
	 * - sending vector back to slave 
	 */
	if (myid == server) {	// I am the random generator server

		do {
			MPI_Recv( &request, 1, MPI_INT, MPI_ANY_SOURCE, REQUEST,
					world, &status );
			if (request) {
				for (i = 0; i < CHUNKSIZE; ) {
					rands[i] = rand();
					if ( rands[i] <= INT_MAX ) i++;
				}
				MPI_Send( rands, CHUNKSIZE, MPI_LONG,
						status.MPI_SOURCE, REPLY, world );
			}
		}
		while( request > 0 );

	}
	/***
	 * Workers (including Master) part
	 *
	 * Worker should send initial request to server.
	 * Later, in a loop worker should:
	 * - receive vector of randoms
	 * - compute x,y point inside unit square
	 * - check (and count result) if point is inside/outside 
	 *   unit circle
	 * - sum both counts over all workers
	 * - calculate pi and its error (from "exact" value)
	 * - test if error is within epsilon limit
	 * - test continuation condition (error and max. points limit)
	 * - print pi by master only
	 * - send a request to server (all if more or master only if finish)
	 * Before finishing workers should free their communicator.
	 */ 
	else {			// I am a worker process

		request = 1;
		done = 0; 
		in = out = 0;
		max  = INT_MAX;         // max int, for normalization
		MPI_Send( &request, 1, MPI_INT, server, REQUEST, world );
		MPI_Comm_rank( workers, &workerid );
		iter = 0;
		while (!done) {
			iter++;
			request = 1;
			MPI_Recv( rands, CHUNKSIZE, MPI_LONG, server, REPLY,
					world, &status );
			for (i = 0; i < CHUNKSIZE - 1; )
			{
				x = (((double) rands[i++])/max) * 2 - 1;
				y = (((double) rands[i++])/max) * 2 - 1;
				if ( x*x + y*y < 1.0 )
				{
					MPE_Draw_point(graph,(int)(WINDOW_SIZE/2+x*WINDOW_SIZE/2),(int)(WINDOW_SIZE+y*WINDOW_SIZE/2),MPE_RED);
					in++;
				}
				else
					out++;
			}
			MPI_Allreduce( &in, &totalin, 1, MPI_LONG, MPI_SUM, workers );
			MPI_Allreduce( &out, &totalout, 1, MPI_LONG, MPI_SUM, workers );
			Pi = ( 4.0 * totalin ) / ( totalin + totalout );
			error = fabs( Pi - PI );
			done = ( error < epsilon || (totalin + totalout) > THROW_MAX );
			request = (done) ? 0 : 1;
		
			MPE_Update(graph);

			if (myid == 0)
			{
				printf( "\rpi = %23.20f", Pi );
				MPI_Send( &request, 1, MPI_INT, server, REQUEST, world );
			}
			else {
				if (request)
					MPI_Send( &request, 1, MPI_INT, server, REQUEST, world );
			}
		}
		MPI_Comm_free( &workers );
	}

	/***
	 * Master should print final point counts.
	 */
	if (myid == 0) {
		printf( "\npoints: %ld\nin: %ld, out: %ld, <ret> to exit\n",
				totalin+totalout, totalin, totalout );
		getchar();
	}

	MPE_Close_graphics(graph);
	MPI_Finalize();

	return 0;
}
