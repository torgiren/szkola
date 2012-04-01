#include "lab03.h"
Zespolona::Zespolona():
itsRe(0),itsIm(0)
{
};
Zespolona::Zespolona(int Re,int Im):
itsRe(Re),itsIm(Im)
{
};
/**
*funkcja przypisuje
@param liczba Liczba ktora ma zostac przypisana
@return void
*/
void Zespolona::przypisz(const Zespolona &liczba)
{
	itsRe=liczba.itsRe;
	itsIm=liczba.itsIm;
};
void Zespolona::dodaj(const Zespolona &liczba)
{
	itsRe+=liczba.itsRe;
	itsIm+=liczba.itsIm;
};
void Zespolona::odejmij(const Zespolona &liczba)
{
	itsRe-=liczba.itsRe;
	itsIm-=liczba.itsIm;
};
void Zespolona::pomnoz(const Zespolona &liczba)
{
	int x=(itsRe*liczba.itsRe)-(itsIm*liczba.itsIm);
	int y=(itsIm*liczba.itsRe)+(itsRe*liczba.itsIm);
	itsRe=x;
	itsIm=y;
};
void Zespolona::podziel(const Zespolona &liczba)
{
	int x=(itsRe*liczba.itsRe+itsIm*liczba.itsIm)/(liczba.itsRe*liczba.itsRe+liczba.itsIm*liczba.itsIm);
	int y=(itsIm*liczba.itsRe-itsRe*liczba.itsIm)/(liczba.itsRe*liczba.itsRe+liczba.itsIm*liczba.itsIm);
	itsRe=x;
	itsIm=y;
};
void Zespolona::print()
{
	cout<<itsRe<<(itsIm>0?"+":"")<<itsIm<<"i"<<endl;	
};
