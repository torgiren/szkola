#include "silniacz.h"
#include <iostream>
using namespace std;
Silniacz::Silniacz()
{
	itsWartosci[0]=1;
	itsWartosci[1]=1;
	itsWartosci[2]=2;
};
long long Silniacz::Policz(int n)
{
//	cout<<"Policz: "<<n<<endl;
	if(!itsWartosci[n]) itsWartosci[n]=Wylicz(n);
	return itsWartosci[n];
};
long long Silniacz::Wylicz(int n)
{
//	cout<<"Wylicz: "<<n<<endl;
	return n*Policz(n-1);
};
