#include <iostream>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
using namespace std;
int main(int argc,char* argv[] )
{
	if(argc<6)
	{
		cout<<"Usage: ./main n h B F0 Omega"<<endl;
		return -1;
	};
	float *d0,*d1,*d2,*x,*b;
	float h=atof(argv[2]);
	int n=atoi(argv[1]);
	float w=1;
	float B=atof(argv[3]),F=atof(argv[4]),Omega=atof(argv[5]);
	float a1=1;
	float a2=w*w*h*h-B*h-2;
	float a3=(1+B*h);
	d0=new float[n];
	d1=new float[n];
	d2=new float[n];
	b=new float[n];
	x=new float[n];
	memset(d0,0,n);
	memset(d1,0,n);
	memset(d2,0,n);
	memset(x,0,n);
	memset(b,0,n);
	int i;
	for(i=0;i<n;i++)
	{
		d0[i]=a3;
		d1[i]=a2;
		d2[i]=a1;
		b[i]=F*sin(Omega*h*i)*h*h;
	};
	d0[0]=1.0;
	d1[0]=0.0;
	d2[0]=0.0;

	d0[1]=1.0;
	d1[1]=-1.0;
	d2[1]=0.0;
	
	b[0]=1;
	b[1]=0;
	x[0]=1;
	x[1]=1;

	int j;
	for(i=2;i<n;i++)
	{
		x[i]=1/d0[i]*(b[i]-d2[i]*x[i-2]-d1[i]*x[i-1]);
	};

	FILE* plik=fopen("dane.dat","w");
	for(i=0;i<n;i++)
	{
		fprintf(plik,"%d %f\n",i,x[i]);
	};
	fclose(plik);
	delete [] d0;
	delete [] d1;
	delete [] d2;
	delete [] x;
	delete [] b;
};
