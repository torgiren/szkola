#include "lab06.h"
#include <string.h>
#include <iostream>
using namespace std;
IntTab::IntTab(int size):
itsSize(size),itsTab(0)
{
	if(size>0)
	{
		itsTab=new int[size+1];
	};
};

IntTab::IntTab(const IntTab& clone)
{
	itsSize=clone.itsSize;
	itsTab=new int[itsSize];
	int x;
	for(x=0;x<itsSize;x++)
	{
		itsTab[x]=clone.itsTab[x];
	};
};

IntTab::~IntTab()
{
	if(itsTab) delete [] itsTab;
	itsTab=0;
};
int& IntTab::operator()(int num) const
{
	if(num>=itsSize)
	{
		cout<<"Out of bound"<<endl;
		return itsTab[itsSize];
	}
	else
		return itsTab[num];
};
void IntTab::operator=(const IntTab& b)
{
	if(itsSize!=b.itsSize)
	{
		cout<<"Diffrent sizes in operator="<<endl;
		return;
	};
	memcpy(itsTab,b.itsTab,sizeof(int)*itsSize);
};
IntTab IntTab::operator-() const
{
	IntTab tmp(itsSize);
	int x=0;
	for(x=0;x<itsSize;x++)
	{
		tmp.itsTab[x]=itsTab[x]*(-1);
	};
	return tmp;
};
IntTab IntTab::operator-(IntTab& a) const
{
	if(itsSize!=a.itsSize)
	{
		IntTab tmp;
		cout<<"Diffrent sizes in operator-"<<endl;
		return tmp;
	};
	IntTab tmp(itsSize);
	int x=0;
	for(x=0;x<itsSize;x++)
	{
		tmp.itsTab[x]=itsTab[x]-a.itsTab[x];
	};
	return tmp;

};
void IntTab::print() const
{
	if(!itsSize)
	{
		cout<<"Nothing to print"<<endl;
		return;
	};
	int x=0;
	for(x=0;x<itsSize;x++)
	{
		cout<<itsTab[x]<<",";
	};
	cout<<endl;
};
