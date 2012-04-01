#include <iostream>
#include <math.h>
#include <nrutil.h>
#include <nrutil.c>
#include <sinft.c>
#include <realft.c>
#include <four1.c>
#include <time.h>
using namespace std;
float omega;
long n;
float y(float i);
int main(int argc, char* argv[])
{
	srand(time(NULL));
	if(argc<2)
	{
		cerr<<"Usage: "<<argv[0]<<" <k>"<<endl;
		return -1;
	};
	int k=atoi(argv[1]);
	n=pow(2,k);
	omega=4*M_PI/(n);
	long x;
	float *data=new float[n];
	FILE *plik=fopen("f.dat","w+");
	FILE *plik2=fopen("f3.dat","w");
	if(!plik)
	{
		cerr<<"File error"<<endl;
		return -2;
	};
	for(x=0;x<n;x++)
	{
		data[x]=y(x);
		fprintf(plik2,"%d %f\n",x,data[x]);
		float r=rand();
		float szum=r/(RAND_MAX+1.0);
		if(((float)rand()/(RAND_MAX+1.0)<0.5))
			szum*=-1;
		data[x]+=szum;
//		cout<<x<<" "<<data[x]<<endl;
		fprintf(plik,"%d %f\n",x,data[x]);
	};
	fclose(plik);
//	cout<<endl;
	sinft(data,n);
	plik=fopen("f2.dat","w+");
	for(x=0;x<n;x++)
	{
		fprintf(plik,"%d %f\n",x,data[x]);
//		cout<<x<<" "<<data[x]<<endl;
	};
	float max=0;
	for(x=0;x<n;x++)
	{
		if(data[x]>max)
			max=data[x];
	};
	for(x=0;x<n;x++)
	{
		if(data[x]<0.25*max)
			data[x]=0;
	};
	sinft(data,n);
	fclose(plik);
	plik=fopen("f4.dat","w+");
	for(x=0;x<n;x++)
	{
		data[x]*=2.0/n;
		fprintf(plik,"%d %f\n",x,data[x]);
//		cout<<x<<" "<<data[x]<<endl;
	};
	fclose(plik);
	fclose(plik2);
	return 0;
};
float y(float i)
{
	return sin(omega*i)+sin(2*omega*i)+sin(3*omega*i);
};
