#include <iostream>
using namespace std;
#include "wyjatki.h"
#include "ctabwym.h"
CTabWym::CTabWym(int i):
itsSize(i),itsTab(0)
{
	itsTab=new CWym[i];
};
CTabWym::~CTabWym()
{
	if(itsTab)
	{
		delete [] itsTab;
		itsTab=0;
	};
};
CWym& CTabWym::operator[](int i)
{
	if(i>=itsSize) throw EPozaTab();
	return itsTab[i];
};
double CTabWym::toDouble(int i)
{
	if(i>=itsSize) throw EPozaTab();
	if(i<0) throw EPozaTab();
	return (double)itsTab[i].itsL/itsTab[i].itsM;
};
void CTabWym::Print(int i)
{
	cout<<"Wym("<<i<<")="<<toDouble(i-1)<<endl;
};
CWym CTabWym::Calc()
{
	int x;
	CWym tmp=itsTab[0];
	for(x=1;x<itsSize;x++)
	{
		tmp=tmp+itsTab[x];		
	};
	return tmp;
};
