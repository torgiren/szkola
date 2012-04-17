#include <iostream>
#include "reader.h"
int main()
{
	std::cout<<"Hello world"<<std::endl;
	try
	{
		Reader::ReadMap("map.ini");
	}
	catch(FileOpenError e)
	{
		std::cerr<<"Blad otwarcia pliku: "<<e.itsPath<<std::endl;
	};
	return 0;
};
