#include "droga.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void Droga::Dump(char* data)
{
	sprintf(data,"%d %lf %d %d ",itsDl,itsFeromony,itsMiasta[0],itsMiasta[1]);
};
int Droga::Load(char*& data)
{
	int size;
//	printf("Przed: %s\n",data);
	char a[16],b[16],c[16],d[16];
	sscanf(data,"%s %s %s %s ",a,b,c,d);
//	printf("wczytano...\n");
	size=strlen(a)+strlen(b)+strlen(c)+strlen(d)+4;
	itsDl=atoi(a);
	itsFeromony=atof(b);
	itsMiasta[0]=atoi(c);
	itsMiasta[1]=atoi(d);
//	printf("dl=%d, ferm=%lf, mias=%d,%d\n",itsDl,itsFeromony,itsMiasta[0],itsMiasta[1]);
//	printf("Wczytano: %d\n",size);
//	data+=size;
	return size;
//	printf("Po: %s\n",data);
};
