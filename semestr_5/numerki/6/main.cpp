#include <iostream>
#include <stdio.h>
using namespace std;
float f(float x);
float w(float x, float** tab, int k);
float W(float x,float **tab,int k);
void printTab(float** tab,int w,int h);
int main()
{
	int ileWezlow;
	cout<<"Podaj ilosc wezlow: ";
	cin>>ileWezlow;
	int i;
	float **tab=(float**)new float[ileWezlow+1];
	for(i=0;i<ileWezlow+1;i++)
	{
		tab[i]=new float[ileWezlow];
	};
	for(i=0;i<ileWezlow;i++)
	{
		cout<<"Podaj wezel nr: "<<i<<": ";
		cin>>tab[0][i];
	};
	for(i=0;i<ileWezlow;i++)
	{
		tab[1][i]=f(tab[0][i]);
	};
	int j;
	cout<<"\t"<<endl;
//	for(j=2;j<3;j++)
	for(j=2;j<ileWezlow+1;j++)
	{
		for(i=0;i<ileWezlow+1-j;i++)
		{
//			tab[j][i]=(tab[i+1][j-1]-tab[i][j-1])/(tab[i+j-1][0]-tab[i][0]);
//			tab[j][i]=(tab[j][i+1]-tab[j][i])/(tab[0][i+j+1]-tab[0][i]);
//			cout<<tab[j-1][i+1]<<"\t"<<tab[j-1][i]<<endl;
//			cout<<tab[0][i+j-1]<<"\t"<<tab[0][i]<<endl;
			float tmp1=tab[j-1][i+1]-tab[j-1][i];
			float tmp2=tab[0][i+j-1]-tab[0][i];
//			cout<<tmp1<<"\t"<<tmp2<<endl;
//			cout<<"*****"<<endl;
			tab[j][i]=tmp1/tmp2;
		};
	};
	printf("\n");
	printTab(tab,ileWezlow+1,ileWezlow);

	float m;
	FILE* plik;
	plik=fopen("w.dat","w");
	for(m=-5;m<5;m+=0.1)
	{
		fprintf(plik,"%f %f %f\n",m,W(m,tab,ileWezlow),W(m,tab,1));
	};
	fclose(plik);


};
float f(float x)
{
	return 1/(1+x*x);
};
void printTab(float** tab,int w,int h)
{
	int x,y;
	for(x=0;x<h;x++)
	{
		for(y=0;y<w;y++)
		{
			printf("%.3f\t",tab[y][x]);
		};
		printf("\n");
	};
};
float w(float x, float** tab, int k)
{
	float w=1;
	int i;
	for(i=0;i<k;i++)
	{
//		cout<<x<<"\t"<<tab[0][i]<<endl;
		w*=(x-tab[0][i]);
	};
	return w;
};

float W(float x,float** tab,int k)
{
	int i=0;
	float wynik=0;
	for(i=1;i<=k;i++)
	{
	//	cout<<w(x,tab,i-1)<<endl;
	//	cout<<tab[i][0]<<endl;
	//	cout<<"******"<<endl;
		
		wynik+=tab[i][0]*w(x,tab,i-1);
	};
	return wynik;
};
