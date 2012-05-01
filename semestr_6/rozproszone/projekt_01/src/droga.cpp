#include "droga.h"
#include <math.h>
#include <stdio.h>
Droga::Droga(int src,int dst, int len):
itsDl(len),itsFeromony(1)
{
	itsMiasta[0]=src;
	itsMiasta[1]=dst;
};
bool Droga::operator==(const Droga& droga) const 
{
	return ((itsDl==droga.itsDl)&&(fabs(itsFeromony-droga.itsFeromony)<0.000001)&&(itsMiasta[0]==droga.itsMiasta[0])&&(itsMiasta[1]==droga.itsMiasta[1]));
};
bool Droga::operator!=(const Droga& droga) const 
{
	return !((*this)==droga);
};
char* Droga::Dump()
{
	char *wynik=new char[255];
	sprintf(wynik,"%d %lf %d %d ",itsDl,itsFeromony,itsMiasta[0],itsMiasta[1]);
	return wynik;
};
void Droga::Load(char* data)
{
	sscanf(data,"%d %f %d %d",&itsDl, &itsFeromony,&itsMiasta[0],&itsMiasta[1]);
};
