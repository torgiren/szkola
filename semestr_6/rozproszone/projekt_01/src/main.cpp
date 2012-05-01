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
	for(i=0;i<200;i++)
	{
		eng.NewAnt(eng.Cities());
		while(eng.Step());
		eng.Parowanie();
		std::cout<<"i="<<i<<"\tNajlepsza droga: "<<eng.RetBest()<<std::endl;
	};
//	+=eng.PrintKontener();

	return 0;
};
