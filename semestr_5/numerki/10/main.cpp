#include <iostream>
#include <cmath>
using namespace std;
float f1(float x);
float f2(float x);
float f3(float x);
float (*f)(float x);
int main()
{
	int n=7;
	f=f1;
	float** tab=new float*[n];
	int i;
	int j;
	for(i=0;i<n;i++)
	{
		tab[i]=new float[n];
	};
	float a=0;
	float b=1;
	tab[0][0]=f(b)/2+f(a)/2;
	for(i=1;i<n;i++)
	{ 
		tab[i][0]=tab[i-1][0]/2;
		float tmp=0;
		float max=pow(2,i-1);
		float h=(b-a)/(max*2);
		for(j=1;j<=max;j++)
		{
			tmp+=f(a+(2*j-1)*h);
		};
		tmp*=h;
		tab[i][0]+=h;
		for(j=1;j<=i;j++)
		{
			tab[i][j]=(pow(4,j)*tab[i][j-1]-tab[i-1][j-1])/	(pow(4,j)-1);
		};
	};
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			cout<<tab[i][j]<<"\t";
		};
		cout<<endl;
	};
};
float f1(float x)
{
	if(x==0) x=0.0000001;
	float wynik=sin(x)/x;
	cout<<"x="<<x<<": "<<wynik<<endl;
	return wynik;
};
float f2(float x)
{
	if(x==0) x=0.0000001;
	return (cos(x)-exp(x))/(sin(x));
};
float f3(float x)
{
	if(x==0) x=0.0000001;	
	return 1/(x*exp(x));
};

