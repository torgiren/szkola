#include <iostream>
#include <cstdlib>
#include <mpi.h>
#include "kontener.h"
#include "reader.h"
#include "engine.h"
int main(int argc, char* argv[])
{

	srand(time(NULL));
	Engine eng;
		eng.LoadMap("map.ini");
	std::cout<<"Hello world"<<std::endl;
	int i;
	for(i=0;i<50;i++)
	{
		eng.NewAnt(eng.Cities());
		while(eng.Step());
		eng.Parowanie();
		std::cout<<"i="<<i<<"\tNajlepsza droga: "<<eng.RetBest()<<std::endl;
	};
//	+=eng.PrintKontener();

	char* data=new char[0xffff];
	int size;
	size=eng.DumpContainer(data);
	printf("%s\n",data);
	printf("Size: %d\n",size);
	Engine eng2;
	eng2.CreateContainer(eng.Cities());
	eng2.LoadContainer(data);
	eng2.DumpContainer(data);
	printf("%s\n",data);
	return 0;
};
