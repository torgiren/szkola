#include "reader.h"
#include <fstream>
#include <iostream>
Kontener* Reader::ReadMap(std::string path)
{
	std::ifstream plik(path.c_str());
	if(!plik)
		throw FileOpenError(path);

	Kontener* wynik=new Kontener;
	while(!plik.eof())
	{
		char tmp[255];
		plik.getline(tmp,255);
		if(tmp[0]=='#')
			continue;
		std::cout<<tmp<<std::endl;
	};
	return wynik;
};
