#include <iostream>
#include <cmath>
using namespace std;
float f1(float x);
float f2(float x);
int main()
{
	cout.precision(5);
	float (*f)(float);
	f=f2;
	int N=10;
	float a=0;
	float b=3.14;
	float** tab=new float*[N];
	int i;
	int j;
	for(i=0;i<N;i++)
	{
		tab[i]=new float[N];
	};
	tab[0][0]=(f(a)+f(b))/2;
	int n;
	int k;
	for(n=1;n<N;n++)
	{
		float h=(b-a)/pow(2,n);
		tab[n][0]=tab[n-1][0]/2;
		float sum=0;
		for(i=1;i<=pow(2,n-1);i++)
		{
			sum+=f(a+(2*i-1)*h);
		};
		sum*=h;
		tab[n][0]+=sum;
	};
	for(n=1;n<N;n++)
	{
		for(k=1;k<=n;k++)
		{
			tab[n][k]=(float)(pow(4,k)*tab[n][k-1]-tab[n-1][k-1])/(pow(4,k)-1);
		};
	};
	for(n=0;n<N;n++)
	{
		for(k=0;k<=n;k++)
		{
			cout<<tab[n][k]<<"\t";
		};
		cout<<endl;
	};
};
float f1(float x)
{
	return sin(x)/(x+0.00000001);
};
float f2(float x)
{
	return sin(5*x)*x*x;
};
