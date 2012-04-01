#include "cwektor.h"
#include <iostream>
using namespace std;
#include "math.h"
CWektor::CWektor(int x,int y,int scale):
itsX(x),itsY(y),itsScale(scale)
{
	cout<<"Tworze wektor = ("<<itsX<<","<<itsY<<"), skala= "<<itsScale<<endl;
};
CWektor::CWektor(const CWektor& orig)
{
	itsX=orig.itsX;
	itsY=orig.itsY;
	itsScale=1;
	cout<<"Przy kopiowaniu ustawiamy skale na 1"<<endl;
};
void CWektor::print() const
{
	cout<<"("<<itsX*itsScale<<","<<itsY*itsScale<<")"<<endl;
};
CWektor CWektor::toScaledCWektor() const
{
	CWektor tmp=CWektor(itsX*itsScale,itsY*itsScale);
	return tmp;
};
CWektor::operator double() const
{
	return  sqrt((itsX*itsX+itsY*itsY));
};
