#include "engine.h"
#include <iostream>
#include <cstdlib>
#include "reader.h"
using namespace std;
Engine::Engine()
{
	itsKontener=NULL;
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
	itsMrowka=new Mrowka();
	int start=rand()%itsKontener->itsMiasta.size();
	itsMrowka->itsMiasto=start;
};
void Engine::Step()
{
//	int start=rand()%itsKontener->itsMiasta.size();
	int start=itsMrowka->itsMiasto;
	std::vector<Droga*> drogi=itsKontener->RetDrogi(start);

	unsigned int i;
	cout<<"Startujemy z miasta "<<start+1<<endl;
	cout<<"Mozliwe drogi..."<<endl;
	int suma=0;
	for(i=0;i<drogi.size();i++)
	{
		suma+=drogi[i]->itsDl;
	};
	for(i=0;i<drogi.size();i++)
	{
		drogi[i]->itsDl=suma-drogi[i]->itsDl;
	};
	suma*=(drogi.size()-1);
	int act_suma=0;
	int select=rand()%suma;
	int selected=-1;
	cout<<"select: "<<select<<endl;
	for(i=0;i<drogi.size();i++)
	{
		cout<<drogi[i]->itsMiasta[0]+1<<" ";
		cout<<drogi[i]->itsMiasta[1]+1<<" ";
		cout<<drogi[i]->itsDl<<" ";
		cout<<((float)drogi[i]->itsDl/suma*100)<<"%"<<" ";
		if((select>=act_suma) && (select < act_suma+drogi[i]->itsDl))
		{
			cout<<"*";
			selected=i;
		};
		act_suma+=drogi[i]->itsDl;
		cout<<endl;
	};
	itsMrowka->itsDroga.push_back(selected);
	int nextCity=(drogi[selected]->itsMiasta[0]==itsMrowka->itsMiasto)?drogi[selected]->itsMiasta[1]:drogi[selected]->itsMiasta[0];
	itsMrowka->itsOdwiedzone.insert(nextCity);
	itsMrowka->itsMiasto=nextCity;

};
