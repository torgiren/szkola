#include "kontener.h"
Kontener::Kontener(int cities)
{
	int i;
	for(i=0;i<cities;i++)
	{
		itsMiasta.push_back(new Miasto());
	};
};
Kontener::~Kontener()
{
	unsigned int i;
	for(i=0;i<itsMiasta.size();i++)
	{
		delete itsMiasta[i];
	};
};
void Kontener::AddRoad(Droga* road)
{
	itsDrogi.push_back(road);
	itsMiasta[road->itsMiasta[0]]->AddRoad(itsDrogi.size()-1);
	itsMiasta[road->itsMiasta[1]]->AddRoad(itsDrogi.size()-1);
};
void Kontener::Print()
{
	unsigned int i;
	for(i=0;i<itsMiasta.size();i++)
	{
		std::cout<<i<<": "<<std::endl;
		unsigned int j;
		std::vector<int>* drog=itsMiasta[i]->RetDrogi();
		for(j=0;j<drog->size();j++)
		{
			std::cout<<"\t"<<itsDrogi[(*drog)[j]]->itsMiasta[0]<<" ";
			std::cout<<itsDrogi[(*drog)[j]]->itsMiasta[1]<<" ";
			std::cout<<itsDrogi[(*drog)[j]]->itsDl<<" ";
			std::cout<<itsDrogi[(*drog)[j]]->itsFeromony<<std::endl;
		};
	};
};
std::vector<Droga*> Kontener::RetDrogi(int city)
{
	std::vector<Droga*> wynik;
	unsigned int i;
	std::vector<int>* drog=itsMiasta[city]->RetDrogi();
	for(i=0;i<drog->size();i++)
	{
		wynik.push_back(itsDrogi[(*drog)[i]]);
	};
	return wynik;
};
Droga* Kontener::RetDroga(unsigned int id)
{
	if(id>=itsDrogi.size())
		throw OutOfBound("Kontener::RetDroga: id="+id);
	return itsDrogi[id];
};
