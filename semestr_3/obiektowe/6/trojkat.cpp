#include <iostream>
#include "trojkat.h"
#include <math.h>
using namespace std;
float Trojkat::RetPole() const
{
	float p=(itsA+itsB+itsC)/2;
	float wynik;
	wynik=p*(p-itsA)*(p-itsB)*(p-itsC);
	wynik=sqrt(wynik);
	return wynik;
};
