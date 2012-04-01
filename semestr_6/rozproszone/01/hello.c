#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
int main(int argc, char *argv[])
{
	MPI_Init(&argc,&argv);
	int nproc;
	MPI_Comm_size(MPI_COMM_WORLD,&nproc);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	char *name=(char*)malloc(255);
	int length;

	int a=0;
	int b=0;
	if(rank==0)
	{
		printf("Wezlow: %d\n",nproc);
	};
	if(rank==1)
	{
		a=100;
	}
	if(rank==2)
	{
		a=200;
	};
	MPI_Get_processor_name(name,&length);
//	printf("Hello World\t%d/%d\t name=%s\n",rank,nproc,name);
	printf("%d:%s:\tHello World\n",rank,name);

	char* buf=(char*)malloc(255);
	sprintf(buf,"%d",a);

	printf("a=%d\n",a);
	MPI_Bcast(&a, 1,MPI_INT,1,MPI_COMM_WORLD);
	printf("a=%d\n",a);

	MPI_Finalize();
	free(name);
	free(buf);
	return 0;
};
