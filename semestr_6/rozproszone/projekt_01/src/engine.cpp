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
	try
	{
		itsKontener=Reader::ReadMap("map.ini");
	}
	catch(FileOpenError e)
	{
		std::cerr<<"Blad otwarcia pliku: "<<e.itsPath<<std::endl;
	}
	catch(FileSyntaxError e)
	{
		std::cerr<<"Blad składni pliku "<<e.itsPath<<": "<<e.itsLine<<"\n\t"<<e.itsDesc<<std::endl;
	};
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
	itsMrowka->itsOdwiedzone.insert(start);
};
bool Engine::Step()
{
//	int start=rand()%itsKontener->itsMiasta.size();
	int start=itsMrowka->itsMiasto;
//	cout<<"Startujemy z miasta "<<start+1<<endl;
	std::vector<Droga*> drogi=itsKontener->RetDrogi(start);
//Usuwanie odwiedzony dróg
	std::vector<Droga*>::iterator iter;
	for(iter=drogi.begin();iter!=drogi.end();)
	{
		if(itsMrowka->itsOdwiedzone.find((*iter)->itsMiasta[0])!=itsMrowka->itsOdwiedzone.end()&&
		itsMrowka->itsOdwiedzone.find((*iter)->itsMiasta[1])!=itsMrowka->itsOdwiedzone.end())
		{

//			cout<<"Usuwam... "<<(*iter)->itsMiasta[0]+1<<" "<<(*iter)->itsMiasta[1]+1<<" "<<(*iter)->itsDl<<endl;
//			cout<<drogi.size()<<" -> ";
//			cout.flush();
			drogi.erase(iter);
			iter=drogi.begin();
//			cout<<drogi.size()<<endl;
		}
		else
		{
			++iter;
		};
	};
//	cout<<"size: "<<drogi.size()<<endl;
	if(drogi.size()==0)
	{
//		cout<<"Brak mozliwosci..."<<endl;
		if(itsMrowka->itsOdwiedzone.size()==itsKontener->itsMiasta.size())
		{
//			cout<<"Wszystko odwiedzone :)"<<endl;
			unsigned int i;
			int droga=0;
			for(i=0;i<itsMrowka->itsDroga.size();i++)
			{
//				cout<<"droga="<<droga<<endl;
				droga+=itsKontener->itsDrogi[itsMrowka->itsDroga[i]]->itsDl;
				itsKontener->itsDrogi[itsMrowka->itsDroga[i]]->itsFeromony+=5;
//				itsKontener->Print();
			};
//			cout<<"droga: "<<droga<<endl;
			if(droga<itsBest)
				itsBest=droga;
		};
		return false;
	};
	unsigned int i;
//	cout<<"Mozliwe drogi..."<<endl;
	int suma=0;
	for(i=0;i<drogi.size();i++)
	{
		suma+=drogi[i]->itsDl;
	};

	int suma_nowa=suma;
	if(drogi.size()!=1)
	{
		suma_nowa*=drogi.size()-1;
	}
	else
		suma=2*drogi[0]->itsDl;
			
//	cout<<"suma: "<<suma<<endl;
	int act_suma=0;
	int select=rand()%suma_nowa;
	int selected=-1;
//	cout<<"select: "<<select<<endl;
	for(i=0;i<drogi.size();i++)
	{
		cout<<drogi[i]->itsMiasta[0]+1<<" ";
		cout<<drogi[i]->itsMiasta[1]+1<<" ";
		cout<<drogi[i]->itsDl<<" ";
		cout<<drogi[i]->itsFeromony<<" ";
		cout<<(((float)suma-(float)drogi[i]->itsDl)/(suma_nowa)*100)<<"%"<<" ";
		if((select>=act_suma) && (select < act_suma+(suma-drogi[i]->itsDl)))
		{
			cout<<"*";
			selected=i;
		};
		act_suma+=(suma-drogi[i]->itsDl);
		cout<<endl;
	};
//	cout<<"size="<<drogi.size()<<endl;
//	cout<<"selected: "<<selected<<endl;
	itsMrowka->itsDroga.push_back(std::distance(itsKontener->itsDrogi.begin(),std::find(itsKontener->itsDrogi.begin(),itsKontener->itsDrogi.end(),drogi[selected])));
	int nextCity=
		(drogi[selected]->itsMiasta[0]
		==itsMrowka->itsMiasto)?
		drogi[selected]->itsMiasta[1]:
		drogi[selected]->itsMiasta[0];
	itsMrowka->itsOdwiedzone.insert(nextCity);
	itsMrowka->itsMiasto=nextCity;
	cout<<"---------------------------------"<<endl;
	return true;
};
int Engine::RetBest()
{
	return itsBest;
};
