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
	eng.Step();
	eng.Step();
	eng.Step();
	eng.Step();
	return 0;
};
