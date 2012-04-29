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
	int cities;
		eng.LoadMap("map.ini");
	std::cout<<"Hello world"<<std::endl;
	int i;
	for(i=0;i<10000;i++)
	{
		eng.NewAnt();
		while(eng.Step());
		eng.Parowanie();
		std::cout<<"Najlepsza droga: "<<eng.RetBest()<<std::endl;
	};
//	+=eng.PrintKontener();

	return 0;
};
