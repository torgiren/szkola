#include <iostream>
#include <cstdlib>
#include "kontener.h"
#include "reader.h"
#include "engine.h"
int main()
{
	srand(time(NULL));
	std::cout<<"Hello world"<<std::endl;
	Engine eng;
	int i;
	for(i=0;i<10;i++)
	{
		eng.NewAnt();
		while(eng.Step());
		std::cout<<"Najlepsza droga: "<<eng.RetBest()<<std::endl;
	}
	return 0;
};
