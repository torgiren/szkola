/**
file main.cpp
@author TORGiren
*/
#include <iostream>
#include <stdio.h>
#include "figura.h"
#include "kwadrat.h"
#include "prostokat.h"
#include "kolo.h"
#include "trojkat.h"
#include "operators.h"
using namespace std;
void printMenu();
int main()
{
	bool quit=0;
//	Figura *ptr=0;
	char opt;
	Kwadrat kw;
	Prostokat pr;
	Kolo ko;
	Trojkat tr;
	while(!quit)
	{
		printMenu();
		cin>>opt;
		switch(opt)
		{
			case '1': 
				cin>>kw;
				cout<<kw;
//				ptr=new Kwadrat;
				break;
			case '2':
//				ptr=new Prostokat;
				cin>>pr;
				cout<<pr;
				break;
			case '3':
//				ptr=new Kolo;
				cin>>ko;
				cout<<ko;
				break;
			case '4':
//				ptr=new Trojkat;
				cin>>tr;
				cout<<tr;
				break;
			case '5':
				quit=1;
				break;
		};
	};

};
void printMenu()
{
	cout<<"1: Kwadrat\n2: Prostokat\n3: Kolo\n4: Trojkat\n5: Wyjdz\n";
};
