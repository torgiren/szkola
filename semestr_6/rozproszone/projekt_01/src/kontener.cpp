#include "kontener.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
Kontener::Kontener(int cities)
{
	itsMaxLen=0;
	int i;
	for(i=0;i<cities;i++)
	{
		itsMiasta.push_back(Miasto());
	};
};
Kontener::~Kontener()
{
};
void Kontener::AddRoad(Droga road)
{
	itsDrogi.push_back(road);
	itsMiasta[road.itsMiasta[0]].AddRoad(itsDrogi.size()-1);
	itsMiasta[road.itsMiasta[1]].AddRoad(itsDrogi.size()-1);
	if(road.itsDl+1>itsMaxLen)
		itsMaxLen=road.itsDl+1;
};
void Kontener::Print()
{
	unsigned int i;
	for(i=0;i<itsMiasta.size();i++)
	{
		std::cout<<i<<": "<<std::endl;
		unsigned int j;
		std::vector<int>* drog=itsMiasta[i].RetDrogi();
		for(j=0;j<drog->size();j++)
		{
			std::cout<<"\t"<<itsDrogi[(*drog)[j]].itsMiasta[0]<<" ";
			std::cout<<itsDrogi[(*drog)[j]].itsMiasta[1]<<" ";
			std::cout<<itsDrogi[(*drog)[j]].itsDl<<" ";
			std::cout<<itsDrogi[(*drog)[j]].itsFeromony<<" ";
			std::cout<<(1.0f/(double(itsDrogi[(*drog)[j]].itsDl*itsDrogi[(*drog)[j]].itsDl))*itsDrogi[(*drog)[j]].itsFeromony)<<std::endl;
		};
	};
};
std::vector<Droga*> Kontener::RetDrogi(int city)
{
	std::vector<Droga*> wynik;
	unsigned int i;
	std::vector<int>* drog=itsMiasta[city].RetDrogi();
	for(i=0;i<drog->size();i++)
	{
		wynik.push_back(&itsDrogi[(*drog)[i]]);
	};
	return wynik;
};
Droga* Kontener::RetDroga(unsigned int id)
{
	if(id>=itsDrogi.size())
		throw OutOfBound("Kontener::RetDroga: id="+id);
	return &itsDrogi[id];
};
int Kontener::Dump(char* data)
{
	sprintf(data,"%d ",itsDrogi.size());	
	unsigned int i;
	for(i=0;i<itsDrogi.size();i++)
	{
		sprintf(data,"%s %s",data,itsDrogi[i].Dump());		
	};
	sprintf(data,"%s %d ",data,itsMiasta.size());
	for(i=0;i<itsMiasta.size();i++)
	{
		sprintf(data,"%s %s",data,itsMiasta[i].Dump());
	};

	return strlen(data);
};
void Kontener::Load(char*& data)
{
	itsDrogi.clear();
	itsMiasta.clear();
	int ile;
	int size;
	char a[16];
	size=sscanf(data,"%s", a);
	ile=atoi(a);
	data+=strlen(a)+1;
	int i;
	for(i=0;i<ile;i++)
	{
		Droga tmp;
		tmp.Load(data);
		itsDrogi.push_back(tmp);
	};
	size=sscanf(data,"%s",a);
	data+=strlen(a)+1;
	ile=atoi(a);
	for(i=0;i<ile;i++)
	{
		Miasto tmp;
		tmp.Load(data);
		itsMiasta.push_back(tmp);
	};
};
int Kontener::FindRoadId(int miasto0, int miasto1)
{
	unsigned int i;
	for(i=0;i<itsDrogi.size();i++)
	{
		int m1,m0;
		m0=itsDrogi[i].itsMiasta[0];
		m1=itsDrogi[i].itsMiasta[1];
		if(((m0==miasto0)&&(m1==miasto1))||(
			(m1==miasto0)&&(m0==miasto1)))
		{
			return i;
		};
	};
	return -1;
};
int Kontener::FindRoadId(Droga* droga)
{
	unsigned int i;
	for(i=0;i<itsDrogi.size();i++)
	{
		if(itsDrogi[i]==*droga)
			return i;
	};
	throw(ObjectNotFound("FindRoadId(Droga* droga)"));
};
