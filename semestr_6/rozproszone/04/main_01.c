#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <string.h>
int main(int argc, char* argv[])
{
	MPI_Init(&argc, &argv);
	int nproc;
	MPI_Comm_size(MPI_COMM_WORLD,&nproc);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	char napis[255];
	if(rank==0)
	{
		strcpy(napis,"Jakis tekst");
		int len=strlen(napis);
		MPI_Send(&len,1,MPI_INT,2,0,MPI_COMM_WORLD);
		MPI_Send(napis,len,MPI_CHAR,2,0,MPI_COMM_WORLD);
		printf("Jestem %d i wyslalem: %s o dl: %d\n",rank,napis, len);
	}
	else
	if(rank==2)
	{
		int len;
		MPI_Status stat;
		MPI_Recv(&len,1,MPI_INT,0,MPI_ANY_TAG,MPI_COMM_WORLD,&stat);
		char* napis=(char*)malloc(len*sizeof(char)+1);
		MPI_Recv(napis,len,MPI_CHAR,0,MPI_ANY_TAG,MPI_COMM_WORLD,&stat);
		napis[len]='\0';
		printf("Jestem %d i odebralem: %s o dl: %d\n",rank,napis,len);
		free(napis);
	}
	else
	{
		printf("Jestem %d i nie robie nic...\n",rank);
	};
		
	MPI_Finalize();
	return 0;
};
