/* ======================================================================== */
/*   mc_pi_serv.c                                                           */
/*   MPI program for calculating Pi by Monte Carlo estimation               */
/* ======================================================================== */
/***
   * Fatcat MPICH compilation: 
   *    mpicc.mpich -o mcpi mcpi.c -lm
   * Fatcat MPICH example execution:
   *    mpirun.mpich -machinefile machines.txt -np 3 ./mcpi 0.000001
   */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h"
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
	srand(time(NULL));
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

   /* ....Fill in, please.... */
   if(argc<2)
   {
	   printf("Usage: %s epsilon\n",argv[0]);
	   return -1;
   };
   epsilon=atof(argv[1]);
   printf("Wczytalem epsilon= %lf\n",epsilon);
   MPI_Bcast(&epsilon,1,MPI_DOUBLE,0,MPI_COMM_WORLD);


/***
   * Create new process group called world_group containing all 
   * processes and its communicator called world
   * and a group called worker_group containing all processes
   * except the last one (called here server) 
   * and its communicator called workers.
   */

   /* ....Fill in, please.... */

	MPI_Comm_group(MPI_COMM_WORLD,&world);
	ranks[0]=server;
	MPI_Group_excl(world,1,ranks,&worker_group);
	MPI_Comm_create(MPI_COMM_WORLD,worker_group,&workers);
	MPI_Group_free(&worker_group);

/*
    MPI_Comm_group( ... );
    ranks[0] = server;
    MPI_Group_excl( ... );
    MPI_Comm_create( ... );
    MPI_Group_free( ... );
*/


/***
   * Server part
   *
   * Server should loop until request code is 0, in each iteration:
   * - receiving request code from any slave
   * - generating a vector of CHUNKSIZE randoms <= INT_MAX
   * - sending vector back to slave 
   */
    if (myid == server) {	// I am the random generator server

   /* ....Fill in, please.... */

	while(fabs(Pi-PI)>epsilon)
	{

//		MPI_Status* status;
		int code;
		MPI_Recv(&code,1,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
		int tab[CHUNKSIZE];			
		int i;
		for(i=0;i<CHUNKSIZE;i++)
		{
			tab[i]=rand();
		};
		MPI_Send(tab,CHUNKSIZE,MPI_INT,status.MPI_SOURCE,0,MPI_COMM_WORLD);
/*
	    MPI_Recv( &request, ... );
	    
	    ...
	    
	    MPI_Send( rands, ... );
*/
	}
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
   * - calculate Pi and its error (from "exact" value) in all workers
   * - test if error is within epsilon limit
   * - test continuation condition (error and max. points limit)
   * - print Pi by master only
   * - send a request to server (all if more or master only if finish)
   * Before finishing workers should free their communicator.
   */ 
    else {			// I am a worker process


	while(fabs(Pi-PI)>epsilon)
	{
		printf("%lf\n",Pi);
		int tab[CHUNKSIZE];
		int code=0;
		MPI_Send(&code,1,MPI_INT,server,0,MPI_COMM_WORLD);
		MPI_Recv(tab,CHUNKSIZE,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,NULL);
		printf("dostalem tablice randow\n");
		int i;
		int in=0,out=0,totalin=0,totalout=0;
		for(i=0;i<CHUNKSIZE/2;i+=2)
		{
			double x=tab[i]/RAND_MAX+1;
			double y=tab[i+1]/RAND_MAX+1;
			if(x*x+y*y<1)
			{
				++in;
			}
			else
			{
				++out;
			};
		};
		printf("Po forze...\n");
		MPI_Allreduce(&in,&totalin,1,MPI_INT,MPI_SUM,workers);
		MPI_Allreduce(&out,&totalout,1,MPI_INT,MPI_SUM,workers);
		Pi=4*(double)totalin/((double)totalin+(double)totalout);
	};


    /* ....Fill in, please.... */
    
/*
            MPI_Send( &request, ... );
                        
            ...
                                                
            MPI_Recv( rands, ... );

        ... throw number of darts 
        ... calculate Pi globally
        ... test epsilon condition
                                                            
	MPI_Comm_free( ... );
*/

	}


/***
   * Master should print final point counts.
   */


/* ....Fill in, please.... */

	printf("PI=%lf\n",Pi);

    MPI_Finalize();
	return 0;
}
