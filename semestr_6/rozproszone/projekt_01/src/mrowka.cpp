#include "mrowka.h"
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
