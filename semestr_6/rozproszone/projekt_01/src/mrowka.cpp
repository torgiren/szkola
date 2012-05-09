#include "mrowka.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Mrowka::Mrowka()
{
	itsDlugosc=0;
	itsPowrocila=false;
};
void Mrowka::IdzDroga(int roadID, Droga* droga)
{
	itsDroga.push_back(roadID);
	int nextCity=
		(droga->itsMiasta[0]==itsMiasto)?
		droga->itsMiasta[1]:
		droga->itsMiasta[0];
	itsOdwiedzone.insert(nextCity);
	itsMiasto=nextCity;
	itsDlugosc+=droga->itsDl;
};
void Mrowka::PartialDump(char*& data)
{
	int i;
	sprintf(data,"%d ",itsDroga.size());
	for(i=0;i<itsDroga.size();i++)
	{
		sprintf(data+strlen(data),"%d ",itsDroga[i]);
	};
	sprintf(data+strlen(data),"%d ",itsDlugosc);
	return;
};
void Mrowka::PartialLoad(char* data)
{
	itsDroga.clear();
	int size;
	int i;
	char a[16];
	sscanf(data,"%s",a);
	data+=strlen(a)+1;
	size=atoi(a);
	for(i=0;i<size;i++)
	{
		sscanf(data,"%s",a);
		data+=strlen(a)+1;
		itsDroga.push_back(atoi(a));
	};
	sscanf(data,"%s",a);
	data+=strlen(a)+1;
	itsDlugosc=atoi(a);
};
