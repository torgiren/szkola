#include <iostream>
#include <cstdlib>
#include <cstring>
#include <mpi.h>
#include "kontener.h"
#include "reader.h"
#include "engine.h"
int main(int argc, char* argv[])
{
/*
	Engine eng;
	eng.LoadMap("map.ini");
	char* data=new char[0xfffff];
	eng.DumpContainer(data);
	std::cout<<data<<std::endl;
*/
	MPI_Init(&argc,&argv);
	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	srand(time(NULL)*rank);
	Engine eng(rank);
	char* data=new char[0xfffff];
	printf("%p\n",data);
	memset(data,0,0xfffff);
	int len=0;
	int cities=0;
	if(rank==0)
	{
		eng.LoadMap("map.ini");
		len=eng.DumpContainer(data);
//		std::cout<<data<<std::endl;
//		std::cout<<"Wysylam dane o dl: "<<len<<std::endl;
		cities=eng.Cities();
	}

	MPI_Bcast(&cities,1,MPI_INT,0,MPI_COMM_WORLD);
//	std::cout<<eng.Cities()<<" miast w rank= "<<rank<<std::endl;
	MPI_Bcast(&len,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Bcast(data,len,MPI_CHAR,0,MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
//	std::cout<<eng.Cities()<<" miast w rank= "<<rank<<std::endl;
	if(rank!=0)
	{
//		std::cout<<"Len="<<len<<std::endl;
//		std::cout<<"strlen="<<strlen(data)<<std::endl;
//		std::cout<<"Loaded="<<
		eng.CreateContainer(cities);
		eng.LoadContainer(data);
//		<<std::endl;
//		std::cout<<"Data="<<data<<std::endl;
	};
	std::cout<<eng.Cities()<<" miast w rank= "<<rank<<std::endl;
	int i;
	delete [] data;
	data=new char[1024];
//	eng.DumpContainer(data);
//	std::cout<<"rank "<<rank<<": "<<data<<std::endl;
	int quit=0;
	for(i=0;i<50|!quit;i++)
	{
//		std::cout<<"NewAnt dla "<<eng.Cities()<<" miast w rank= "<<rank<<std::endl;
		int dystans=0;
//		if(rank!=0)
		{
			if(rank==0)
				eng.NewAnt(eng.Cities()/size+eng.Cities()%size);
			else
				eng.NewAnt(eng.Cities()/size);

			while(eng.Step());
			eng.Parowanie();

			dystans=eng.RetBestAnt()->itsDlugosc;

//			printf("rank %d wysyla dystans=%d\n",rank,dystans);
			MPI_Send(&dystans,1,MPI_INT,0,0,MPI_COMM_WORLD);
		}
		int bestRank=0;
		if(rank==0)
		{
			int i;
			int best=99999999;
			MPI_Status status;
			int recv;

			for(i=0;i<size;i++)
			{
//				printf("recv id=%d rank=%d\n",i,rank);
				MPI_Recv(&recv,1,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
//				printf("recv=%d best=%d od=%d ",recv,best,status.MPI_SOURCE);
				if(recv<best)
				{
//					printf("*");

					best=recv;
					bestRank=status.MPI_SOURCE;	
				};
//				printf("\n");
			};
		};
//		std::cout<<"Najlepsza mrowka jest w ranku: "<<bestRank<<std::endl;

		MPI_Bcast(&bestRank,1,MPI_INT,0,MPI_COMM_WORLD);
		memset(data,0,1024);
		if(rank==bestRank)
		{
			eng.RetBestAnt()->PartialDump(data);
//			std::cout<<"rank: "<<rank<<": Rozmiar mrowki: "<<strlen(data)<<std::endl;
			len=strlen(data);
		};
		MPI_Bcast(&len,1,MPI_INT,bestRank,MPI_COMM_WORLD);
//		printf("Bcast mrowki w rank=%d a bestRank=%d\n",rank,bestRank);
		MPI_Bcast(data,len,MPI_CHAR,bestRank,MPI_COMM_WORLD);
		MPI_Barrier(MPI_COMM_WORLD);
//		printf("rank %d: odebrana mrowka: %s\n",rank,data);
		Mrowka bestAnt;
		bestAnt.PartialLoad(data);
		bestAnt.PartialDump(data);
//		printf("rank %d: zredumpowana mrowka: %s\n",rank,data);


// znajdz najlepsza mrówke i uczyń ją pracownicą miesiąca
		eng.ZostawFeromony(&bestAnt);

//		printf("rank %d: Finished: %d\n",rank,eng.IsFinished());


		int finished=eng.IsFinished();
		MPI_Send(&finished,1,MPI_INT,0,0,MPI_COMM_WORLD);
		MPI_Barrier(MPI_COMM_WORLD);
		if(rank==0)
		{
			int i;
			int recv;
			int koniec=1;
			for(i=0;i<size;i++)
			{
				MPI_Recv(&recv,1,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,NULL);
				if(!recv)
				{
					koniec=0;
				};
			};
			quit=koniec;
		};
		MPI_Bcast(&quit,1,MPI_INT,0,MPI_COMM_WORLD);

		std::cout<<"i="<<i<<"\tNajlepsza droga: "<<eng.RetBest()<<std::endl;
	};
	MPI_Barrier(MPI_COMM_WORLD);
	std::cout<<"rank="<<rank<<"\tNajlepsza droga: "<<eng.RetBest()<<std::endl;

	MPI_Finalize();
	return 0;
};
