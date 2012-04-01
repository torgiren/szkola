#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
//float calk(float (*f)(float),float start, float stop, float dt);
int main(int argc, char* argv[])
{
	MPI_Init(&argc,&argv);
	int nproc;
	MPI_Comm_size(MPI_COMM_WORLD,&nproc);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	int *tab=(int*)malloc(sizeof(int)*nproc);
	int i;
	int n=nproc;
	for(i=0;i<n;i++)
	{
		tab[i]=0;
	}
	if(rank==2)
	{
		for(i=0;i<n;i++)
		{
			tab[i]=2*i;
		}
	};
	printf("**********\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",tab[i]);
	};
	printf("\n");
	int val;
	MPI_Scatter(tab,1,MPI_INT,&val,1,MPI_INT,2,MPI_COMM_WORLD);
	printf("proc %d: %d\n",rank,val);
//	printf("**********\n");
		


	MPI_Finalize();
	return 0;
};
/*
float calk(float (*f)(float),float start, float stop,float dt)
{
	float t=0;
	float wynik=0;
	for(t=start;t<stop;t+=dt)
	{
		wynik+=(f(t)+f(t+dt))/2*dt;
	};
	return wynik;	
};
*/
