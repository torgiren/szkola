#include "engine.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "reader.h"
using namespace std;
Engine::Engine()
{
	itsKontener=NULL;
	itsMrowka=NULL;
	itsBest=99999999;

};
void Engine::NewAnt()
{
	if(itsMrowka)
	{
		delete itsMrowka;
		itsMrowka=NULL;
	};
	itsMrowka=new Mrowka();
	int start=rand()%itsKontener->itsMiasta.size();
	itsMrowka->itsMiasto=start;
	itsMrowka->itsStart=start;
	itsMrowka->itsOdwiedzone.insert(start);
};
bool Engine::Step()
{
	std::vector<Droga*> drogi=RetMozliweDrogi();
	if(drogi.size()==0)
	{
		if(itsMrowka->itsOdwiedzone.size()==itsKontener->itsMiasta.size())
		{
			int domkniecie=itsKontener->FindRoadId(itsMrowka->itsStart,itsMrowka->itsMiasto);
			cout<<"domkniecie: "<<domkniecie<<endl;
			itsMrowka->itsDroga.push_back(domkniecie);
			int droga=RetDlugosc();
			cout<<"droga: "<<droga<<endl;
			if(droga<itsBest)
				itsBest=droga;
			ZostawFeromony(droga);	
		};
		return false;
	};
	int selected=PickRoad(drogi);
	itsMrowka->itsDroga.push_back(std::distance(itsKontener->itsDrogi.begin(),std::find(itsKontener->itsDrogi.begin(),itsKontener->itsDrogi.end(),*drogi[selected])));
	int nextCity=
		(drogi[selected]->itsMiasta[0]
		==itsMrowka->itsMiasto)?
		drogi[selected]->itsMiasta[1]:
		drogi[selected]->itsMiasta[0];
	itsMrowka->itsOdwiedzone.insert(nextCity);
	itsMrowka->itsMiasto=nextCity;
	return true;
};
int Engine::RetBest() const
{
	return itsBest;
};
Drogi Engine::RetMozliweDrogi()
{
	int start=itsMrowka->itsMiasto;
	Drogi drogi;
	drogi=itsKontener->RetDrogi(start);
//Usuwanie odwiedzony dróg
	Drogi::iterator iter;
	for(iter=drogi.begin();iter!=drogi.end();)
	{
		if(itsMrowka->itsOdwiedzone.find((*iter)->itsMiasta[0])!=itsMrowka->itsOdwiedzone.end()&&
		itsMrowka->itsOdwiedzone.find((*iter)->itsMiasta[1])!=itsMrowka->itsOdwiedzone.end())
		{

			drogi.erase(iter);
			iter=drogi.begin();
		}
		else
		{
			++iter;
		};
	};
	return drogi;
};
int Engine::RetDlugosc()
{
	unsigned int i;
	int droga=0;
	for(i=0;i<itsMrowka->itsDroga.size();i++)
	{
		droga+=itsKontener->RetDroga(itsMrowka->itsDroga[i])->itsDl;
	};
	return droga;
};
int Engine::PickRoad(Drogi drogi)
{
	Drogi::iterator iter;
	double sum=0;
	int size=drogi.size();
	double *tab=new double[size];
	int i=0;
	for(i=0,iter=drogi.begin();iter!=drogi.end();iter++,i++)
	{
		double tmp=1.0f/((double((*iter)->itsDl)*(double)(*iter)->itsDl));
		sum+=((*iter)->itsFeromony+tmp);
		tab[i]=sum;
	};
	double los=((double)rand()/(double)(RAND_MAX))*tab[size-1];
	for(i=0;i<size;i++)
	{
		if(los<tab[i]) break;
	};
	return i;
};
void Engine::ZostawFeromony(int droga)
{
	Drogi trasa=RetTrasa();
	Drogi::iterator iter;
	for(iter=trasa.begin();iter!=trasa.end();iter++)
	{
//		(*iter)->itsFeromony*=0.9f;
		(*iter)->itsFeromony+=2*itsBest*(2*itsBest/((double)droga));
//		(*iter)->itsFeromony+=(0.5f);
	};
};
Drogi Engine::RetTrasa()
{
	Drogi wynik;	
	std::vector<int>::iterator iter;
	for(iter=itsMrowka->itsDroga.begin();iter!=itsMrowka->itsDroga.end();iter++)
	{
		wynik.push_back(itsKontener->RetDroga(*iter));
	};
	return wynik;
};
void Engine::Parowanie()
{
	std::vector<Droga>::iterator iter;
	for(iter=itsKontener->itsDrogi.begin();iter!=itsKontener->itsDrogi.end();iter++)
	{
		(*iter).itsFeromony*=0.5f;
		if((*iter).itsFeromony<1)
			(*iter).itsFeromony=1;
	};
};
void Engine::LoadMap(std::string path)
{
	try
	{
		itsKontener=Reader::ReadMap("map.ini");
	}
	catch(FileOpenError e)
	{
		std::cerr<<"Blad otwarcia pliku: "<<e.itsPath<<std::endl;
		exit(1);
	}
	catch(FileSyntaxError e)
	{
		std::cerr<<"Blad składni pliku "<<e.itsPath<<": "<<e.itsLine<<"\n\t"<<e.itsDesc<<std::endl;
		exit(2);
	};
};
int Engine::Cities()
{
	return itsKontener->itsMiasta.size();
};
void Engine::CreateContainer(int cities)
{
	if(itsKontener)
	{
		delete itsKontener;
		itsKontener=new Kontener(cities);
	};
};
