#include "droga.h"
#include <math.h>
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
