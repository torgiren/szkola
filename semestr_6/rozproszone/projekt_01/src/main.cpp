#include <iostream>
#include <cstdlib>
#include <mpi.h>
#include "kontener.h"
#include "reader.h"
#include "engine.h"
int main(int argc, char* argv[])
{
	printf("a");
	MPI_Init(&argc,&argv);
	printf("b");
	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	printf("c");
	srand(time(NULL));
	Engine eng;
	char* data=new char[0xffffff];
	int len=0;
	int cities;
	if(rank==0)
	{
		eng.LoadMap("map.ini");
		len=eng.DumpContainer(data);
		cities=eng.Cities();
	}
	MPI_Bcast(&cities,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Bcast(&len,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Bcast(data,len,MPI_CHAR,0,MPI_COMM_WORLD);
	if(rank!=0)
	{
		eng.CreateContainer(cities);
		eng.LoadContainer(data);
	};
	int i;
	for(i=0;i<200;i++)
	{
		eng.NewAnt(eng.Cities());
		while(eng.Step());
		eng.Parowanie();
			int dystans=eng.RetBestAnt()->itsDlugosc;
			MPI_Send(&dystans,1,MPI_INT,0,0,MPI_COMM_WORLD);
		if(rank==0)
		{
			int i;
			int best=99999999;
			int bestRank=0;
			MPI_Status status;
			int recv;
			for(i=0;i<size;i++)
			{
				MPI_Recv(&recv,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
				if(recv<best)
				{
					best=recv;
					bestRank=status.MPI_SOURCE;	
				};
			};
		};

// znajdz najlepsza mrówke i uczyń ją pracownicą miesiąca
		eng.ZostawFeromony(eng.RetBestAnt());

		std::cout<<"i="<<i<<"\tNajlepsza droga: "<<eng.RetBest()<<std::endl;
	};
//	+=eng.PrintKontener();

/*
	char* data=new char[0xffffff];
	int size;
	size=eng.DumpContainer(data);
//	printf("%s\n",data);
	printf("Size: %d\n",size);
	Engine eng2;
	eng2.CreateContainer(eng.Cities());
	eng2.LoadContainer(data);
	eng2.DumpContainer(data);
//	printf("%s\n",data);
*/
	MPI_Finalize();
	return 0;
};
