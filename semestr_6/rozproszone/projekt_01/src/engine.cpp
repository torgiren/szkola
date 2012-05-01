#include "engine.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "reader.h"
using namespace std;
Engine::Engine()
{
	itsKontener=NULL;
	itsMrowki=NULL;
	itsBest=99999999;
	itsAntNumber=0;

};
void Engine::NewAnt(int number)
{
	unsigned int i;
	if(itsAntNumber)
	{
		for(i=0;i<itsAntNumber;i++)
		{
			delete itsMrowki[i];
			itsMrowki[i]=NULL;
		};
	};
	delete itsMrowki;
	itsAntNumber=number;
	itsMrowki=new Mrowka*[itsAntNumber];
	for(i=0;i<itsAntNumber;i++)
	{
		int start=rand()%itsKontener->itsMiasta.size();
		itsMrowki[i]=new Mrowka();
		itsMrowki[i]->itsMiasto=start;
		itsMrowki[i]->itsStart=start;
		itsMrowki[i]->itsOdwiedzone.insert(start);
	}
};
bool Engine::Step()
{
	static Mrowka* LocalBestAnt=0;
	static int LocalBestDist=999999999;
	unsigned int i;
	int pozostalo=itsAntNumber;
	for(i=0;i<itsAntNumber;i++)
	{
		std::vector<Droga*> drogi=RetMozliweDrogi(itsMrowki[i]);
		if(drogi.size()==0)
		{
			if(itsMrowki[i]->itsOdwiedzone.size()==itsKontener->itsMiasta.size())
			{
				if(itsMrowki[i]->itsPowrocila)
					break;
				int domkniecie=itsKontener->FindRoadId(itsMrowki[i]->itsStart,itsMrowki[i]->itsMiasto);
				itsMrowki[i]->itsDroga.push_back(domkniecie);
				itsMrowki[i]->itsDlugosc+=itsKontener->itsDrogi[domkniecie].itsDl;
				itsMrowki[i]->itsPowrocila=true;
				int droga=itsMrowki[i]->itsDlugosc;
				cout<<"droga: "<<droga<<endl;
//				ZostawFeromony(droga);	
				if(droga<itsBest)
				{
					itsBest=droga;
				};
				if(droga<LocalBestDist)
				{
					LocalBestDist=droga;
					LocalBestAnt=itsMrowki[i];
				};
			};
			pozostalo--;
			cout<<i<<endl;
			continue;
		};
		int selected=PickRoad(drogi);
		int roadID=itsKontener->FindRoadId(drogi[selected]);
		itsMrowki[i]->IdzDroga(roadID,drogi[selected]);
	};
	if(pozostalo==0)
	{
		ZostawFeromony(LocalBestAnt);
		LocalBestDist=99999;
	};
	return pozostalo>0;
};
int Engine::RetBest() const
{
	return itsBest;
};
Drogi Engine::RetMozliweDrogi(Mrowka* mrowka)
{
	int start=mrowka->itsMiasto;
	Drogi drogi;
	drogi=itsKontener->RetDrogi(start);
//Usuwanie odwiedzony dróg
	Drogi::iterator iter;
	for(iter=drogi.begin();iter!=drogi.end();)
	{
		if(mrowka->itsOdwiedzone.find((*iter)->itsMiasta[0])!=mrowka->itsOdwiedzone.end()&&
		mrowka->itsOdwiedzone.find((*iter)->itsMiasta[1])!=mrowka->itsOdwiedzone.end())
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
/*
int Engine::RetDlugosc(Mrowka* mrowka)
{
	unsigned int i;
	int droga=0;
	for(i=0;i<mrowka->itsDroga.size();i++)
	{
		droga+=itsKontener->RetDroga(mrowka->itsDroga[i])->itsDl;
	};
	return droga;
};
*/
int Engine::PickRoad(Drogi drogi)
{
	Drogi::iterator iter;
	double sum=0;
	int size=drogi.size();
	double *tab=new double[size];
	int i=0;
	double max=0;
	int maxID=0;
	for(i=0,iter=drogi.begin();iter!=drogi.end();iter++,i++)
	{
		double tmp=1.0f/((double((*iter)->itsDl)*(double)(*iter)->itsDl));
//		double tmp=double(itsKontener->itsMaxLen-(*iter)->itsDl)/(double)(itsKontener->itsMaxLen);
//		cout<<(itsKontener->itsMaxLen)<<" "<<(*iter)->itsDl<<" "<<tmp<<endl;
//		cout<<(*iter)->itsFeromony<<" "<<tmp<<endl;
		double tmp2=((*iter)->itsFeromony*tmp);
		sum+=tmp2;
		tab[i]=sum;
		if(tmp2>max)
		{
			max=tmp2;
			maxID=i;
		};
	};
	if(((double)rand()/(double)RAND_MAX )<0.5)
		return maxID;
	double los=((double)rand()/(double)(RAND_MAX))*tab[size-1];
	for(i=0;i<size;i++)
	{
		if(los<tab[i]) break;
	};
	return i;
};
void Engine::ZostawFeromony(Mrowka* mrowka)
{
	Drogi trasa=RetTrasa(mrowka);
	Drogi::iterator iter;
	for(iter=trasa.begin();iter!=trasa.end();iter++)
	{
		(*iter)->itsFeromony*=0.9f;
		(*iter)->itsFeromony+=(0.1f/(double)mrowka->itsDlugosc);
//		(*iter)->itsFeromony+=itsBest*(itsBest/((double)droga));
//		if(droga<itsBest)
//			(*iter)->itsFeromony+=0.5;
//		(*iter)->itsFeromony+=(0.1f);
//		if((*iter)->itsFeromony>5.0f)
//			(*iter)->itsFeromony=5.0f;

	};
};
Drogi Engine::RetTrasa(Mrowka* mrowka)
{
	Drogi wynik;	
	std::vector<int>::iterator iter;
	for(iter=mrowka->itsDroga.begin();iter!=mrowka->itsDroga.end();iter++)
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
		(*iter).itsFeromony*=0.8f;
//		if((*iter).itsFeromony<0.0001f)
//			(*iter).itsFeromony=0.0001f;
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
