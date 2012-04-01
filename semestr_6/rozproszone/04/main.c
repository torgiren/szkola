#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <string.h>
#include <math.h>
#include <time.h>
int main(int argc, char* argv[])
{

	MPI_Init(&argc, &argv);
	int nproc;
	MPI_Comm_size(MPI_COMM_WORLD,&nproc);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);


	srand(time(NULL)*rank);
	int n=0;
	int N=0;
	double x;
	double y;

	if(rank!=0)
	{
		while(1)
		{
			n=0;
			N=0;
			int opt;
			MPI_Recv(&opt,1,MPI_INT,0,MPI_ANY_TAG,MPI_COMM_WORLD,NULL);
			if(opt==0)
				break;	
			int i;
			for(i=0;i<1000;i++)
			{
				x=(double)rand()/(double)(RAND_MAX);
				y=(double)rand()/(double)(RAND_MAX);
	//			printf("%f\t%f\n",x,y);
				if((x*x+y*y)<=1)
					n++;
				else
					N++;
			};
//			printf("rank %d: %d %d\n",rank,n,N);
			MPI_Send(&n,1,MPI_INT,0,0,MPI_COMM_WORLD);
			MPI_Send(&N,1,MPI_INT,0,0,MPI_COMM_WORLD);
		};
	};
	if(rank==0)
	{
		double pi=0;
		int i;
		int opt=1;
		int n=0;
		int N=0;
		for(i=1;i<nproc;i++)
		{
			MPI_Send(&opt,1,MPI_INT,i,0,MPI_COMM_WORLD);
		};
		while(fabs(M_PI-pi)>0.00001)
		{
			MPI_Status stat;	
			int tmp;
			MPI_Recv(&tmp,1,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&stat);
			n+=tmp;
			int source=stat.MPI_SOURCE;
			MPI_Recv(&tmp,1,MPI_INT,source,MPI_ANY_TAG,MPI_COMM_WORLD,&stat);
			N+=tmp;
			MPI_Send(&opt,1,MPI_INT,source,0,MPI_COMM_WORLD);
			pi=4*(double)n/(double)(N+n);
			printf("PI: %lf\t %lf\n",M_PI,pi);
		};
		opt=0;
		for(i=1;i<nproc;i++)
		{
			MPI_Send(&opt,1,MPI_INT,i,0,MPI_COMM_WORLD);
		};
		printf("PI: %lf\t %lf\n",M_PI,pi);


	};

		
	MPI_Finalize();
	return 0;
};
