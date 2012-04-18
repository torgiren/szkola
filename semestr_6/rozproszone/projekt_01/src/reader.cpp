#include "reader.h"
#include <fstream>
#include <iostream>
Kontener* Reader::ReadMap(std::string path)
{
	std::ifstream plik(path.c_str());
	if(!plik)
		throw FileOpenError(path);

	Kontener* wynik=NULL;
	while(!plik.eof())
	{
		char tmp[255];
		char trash;
		plik.getline(tmp,255);
		if(tmp[0]=='#')
			continue;
		if(tmp[0]=='c')
		{
			if(wynik)
				throw FileSyntaxError(path,tmp,"Double definition cities number");
			int size;
			sscanf(tmp,"%c %d",&trash,&size);
			wynik=new Kontener(size);
		}
		else if(tmp[0]=='r')
		{
			if(!wynik)
				throw FileSyntaxError(path,tmp,"Missing cities number definition");
			int src,dst,len;
			sscanf(tmp,"%c %d %d %d",&trash,&src,&dst,&len);
			wynik->AddRoad(new Droga(src-1,dst-1,len));
		};
		std::cout<<tmp<<std::endl;
	};
	return wynik;
};
