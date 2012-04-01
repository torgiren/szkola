#include "lab02.h"
void Liczby::pop()
{
	itsLista.pop_back();
};
void Liczby::push(int co)
{
	itsLista.push_back(co);
};
void Liczby::push(int tab[],int size)
{
	int x=0;
	for(x=0;x<size;x++)
	{
		push(tab[x]);
	};
};
int Liczby::size()
{
	return itsLista.size();
};
void Liczby::print_to_cout()
{
	list<int>::iterator iter;
	cout<<"[";
	for(iter=itsLista.begin();iter!=itsLista.end();iter++)
	{
		cout<<*iter<<" ";
	};
	cout<<"]"<<endl;
};
void Liczby::sort()
{
	itsLista.sort();
};
