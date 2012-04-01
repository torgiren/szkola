#include <iostream>
#include <nrutil.h>
#include <nrutil.c>
#include <gaussj.c>
using namespace std;
int main()
{
	float h=0.1,v=0,A=1.0,w=1,tm;	
	tm=2*3.14*3.0;
	int n=(int)tm/h;
	float **a,**b;
	a=matrix(1,n,1,n);
	b=matrix(1,n,1,1);
	int i,j;
	cout<<"n="<<n<<endl;
	for(i=1;i<=n;i++)
	{
		b[i][1]=0.0;
		for(j=1;j<=n;j++)
		{
			a[i][j]=0.0;
			if(i==j) a[i][j]=1.0;
			if((i-1)==j) a[i][j]=w*w*h*h-2.0;
			if((i-2)==j) a[i][j]=1.0;
		}
	}

	a[2][1]=-1.0;
	b[1][1]=A;
	b[2][1]=v*h;

	gaussj(a,n,b,1);
	FILE *file=fopen("dane.dat","w");
	for(i=1;i<n;i++) fprintf(file,"%f %f\n",h*i,b[i][1]);
	fclose(file);
	return 0;
};
