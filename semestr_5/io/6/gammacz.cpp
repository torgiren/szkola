#include "gammacz.h"
#include "silniacz.h"
#include <math.h>
#include <iostream>
using namespace std;
double Gammacz::Policz(float n)
{
	Silniacz* sil=Silniacz::GetInstance();
	if((n-(int)n)==0.5)
	{
		if(!itsWartosci[n]) itsWartosci[n]=(float)((float)sil->Policz(2*(int)n)/sil->Policz((int)n))/pow(4,(int)n)*sqrt(M_PI);
		return itsWartosci[n];
	}
	if(!(n-(int)n))
	{
		if(!itsWartosci[n]) itsWartosci[n]=sil->Policz(n-1);
	return itsWartosci[n];
	};
	return 0;
};
