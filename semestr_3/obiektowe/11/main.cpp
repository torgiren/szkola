#include <iostream>
#include <stdlib.h>
#include "wyjatki.h"
#include "ctabwym.h"
#include "cwym.h"
using namespace std;
int main()
{
	char input[255];
	cout<<"Podaj ile liczb: ";
	int ile;
	cin>>input;
	ile=atoi(input);
	while(ile<=0)
	{
		cout<<"Za malo. Podaj jeszcze raz"<<endl;
		cin>>input;
		ile=atoi(input);
	};
	CTabWym tab(ile);
	int i;
	for(i=0;i<ile;i++)
	{
		int l,m;
//		cin>>l>>m;
		cin>>input;
		l=atoi(input);
		cin>>input;
		m=atoi(input);
		try
		{
		tab[i]=CWym(l,m);
		}
		catch(EDzielZero)
		{
			cout<<"Dzielenie przez zero. Podaj liczby jeszcze raz"<<endl;
			i--;
		};
	};
	CWym wynik;
	wynik=tab.Calc();
	cout<<wynik<<endl;
	cout<<"Ktora liczbe chcesz zobaczyc (0 konczy dzialanie)"<<endl;
	int tmp;
	cin>>input;
	tmp=atoi(input);
	while(tmp)
	{
		try
		{
			tab.Print(tmp);
		}
		catch(EPozaTab)
		{
			cout<<"Liczba poza tablica..."<<endl;
		};
		cin>>input;
		tmp=atoi(input);
	};
};
