#include "droga.h"
Droga::Droga(int src,int dst, int len):
itsDl(len),itsFeromony(0.0001f)
{
	itsMiasta[0]=src;
	itsMiasta[1]=dst;
};
