#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct Siatka
{
	double **itsTab;
	int itsSizeX;
	int itsSizeY;
	int itsOffsetX;
	int itsOffsetY;
	//Left,Up,Right,Bottom
	int itsPrzeszkoda[4];
};
void alloc(struct Siatka *tab,int sizeX, int sizeY, int offsetX, int offsetY, int przeszXMin, int przeszXMax, int przeszYMin, int przeszYMax);
void dealloc(struct Siatka *tab);
void poczatkowe(struct Siatka *tab);
void poczatkowe2(struct Siatka *tab);
void oblicz(struct Siatka *tab);
void oblicz2(struct Siatka *tab);
void oblicz3(struct Siatka *tab);
double kwadrat(double liczba);
double ak(struct Siatka *tab);
void zapisz(struct Siatka *tab,char* path);
int in(double val, double min, double max);
//xy=0 dx, xy=1 dy
double pochodna(struct Siatka *tab,int x, int y, int xy);
void zad1();
void zad2();
void zad3();
int main()
{
	zad3();
	return 0;
};
void zad1()
{
	struct Siatka siatka;
	alloc(&siatka,200,100,0,50,95,105,50,70);
	poczatkowe(&siatka);
	zapisz(&siatka,"zad1_pocz.dat");
	oblicz(&siatka);
	zapisz(&siatka,"zad1.dat");
	dealloc(&siatka);
};
void zad2()
{
	struct Siatka siatka;
	alloc(&siatka,200,100,0,50,94,104,50,70);
	poczatkowe2(&siatka);
	oblicz2(&siatka);
	zapisz(&siatka,"zad2.dat");
	dealloc(&siatka);
};
void zad3()
{
	struct Siatka siatka;
	alloc(&siatka,200,100,0,50,94,104,50,70);
	poczatkowe2(&siatka);
	oblicz2(&siatka);
	oblicz3(&siatka);
	zapisz(&siatka,"zad3.dat");
	dealloc(&siatka);
};
void alloc(struct Siatka *tab,int sizeX, int sizeY, int offsetX, int offsetY, int przeszXMin, int przeszXMax, int przeszYMin, int przeszYMax)
{
	tab->itsSizeX=sizeX;
	tab->itsSizeY=sizeY;
	tab->itsOffsetX=offsetX;
	tab->itsOffsetY=offsetY;
	tab->itsPrzeszkoda[0]=przeszXMin-tab->itsOffsetX;
	tab->itsPrzeszkoda[1]=przeszYMin-tab->itsOffsetY;
	tab->itsPrzeszkoda[2]=przeszXMax-tab->itsOffsetX;
	tab->itsPrzeszkoda[3]=przeszYMax-tab->itsOffsetY;
	tab->itsTab=(double**)malloc(tab->itsSizeX*sizeof(double*));
	int i;
	for(i=0;i<tab->itsSizeX;i++)
	{
		tab->itsTab[i]=(double*)malloc(tab->itsSizeY*sizeof(double));
	};
};
void dealloc(struct Siatka *tab)
{
	int i;
	for(i=0;i<tab->itsSizeX;i++)
	{
		free(tab->itsTab[i]);
	};
	free(tab->itsTab);
};
void poczatkowe(struct Siatka *tab)
{
	double u0=1;
	int i,j;
	for(i=0;i<tab->itsSizeX;i++)
	{
		memset(tab->itsTab[i],0,sizeof(double)*tab->itsSizeY);
	};
	for(i=0;i<tab->itsSizeY;i++)
	{
		tab->itsTab[0][i]=u0*(double)(i+tab->itsOffsetY);	
		tab->itsTab[tab->itsSizeX-1][i]=u0*(double)(i+tab->itsOffsetY);	
	};
	for(i=0;i<tab->itsSizeX;i++)
	{
		tab->itsTab[i][0]=u0*50;
		tab->itsTab[i][tab->itsSizeY-1]=u0*((tab->itsSizeY-1)+tab->itsOffsetY);
	};

//	printf("%d %d\n",tab->itsPrzeszkoda[1],tab->itsPrzeszkoda[3]);
	for(i=tab->itsPrzeszkoda[0];i<tab->itsPrzeszkoda[2];i++)
	{
		for(j=tab->itsPrzeszkoda[1];j<tab->itsPrzeszkoda[3];j++)
		{
//			tab->itsTab[i][j]=u0*(double)(u0*(j+tab->itsOffsetY));
//			tab->itsTab[i][j]=u0*(double)(u0*((tab->itsSizeY-1)+tab->itsOffsetY));
			tab->itsTab[i][j]=u0*50;
		};
	};

};
void poczatkowe2(struct Siatka *tab)
{
	double u0=1;
	int i,j;
	for(i=0;i<tab->itsSizeX;i++)
	{
		memset(tab->itsTab[i],0,sizeof(double)*tab->itsSizeY);
	};
	for(i=0;i<tab->itsSizeY;i++)
	{
		tab->itsTab[0][i]=u0;
	};
	for(i=0;i<tab->itsSizeX;i++)
	{
		tab->itsTab[i][tab->itsSizeY-1]=u0*(double)(i+1);
	};
	for(i=0;i<tab->itsSizeY;i++)
	{
		tab->itsTab[tab->itsSizeX-1][i]=u0*(double)(tab->itsSizeX+tab->itsOffsetX);
	};
};
void oblicz(struct Siatka *tab)
{
	int i,j;
	double a=-123;
	double a_prev=123;
	while(fabs(a-a_prev)>0.00000001)
	{
		for(i=1;i<tab->itsSizeX-1;i++)
		{
			for(j=1;j<tab->itsSizeY-1;j++)
			{
				if(i>tab->itsPrzeszkoda[0]&&i<tab->itsPrzeszkoda[2]&&j<tab->itsPrzeszkoda[3]&&j>tab->itsPrzeszkoda[1])
					continue;
				tab->itsTab[i][j]=(tab->itsTab[i-1][j]+tab->itsTab[i+1][j]+tab->itsTab[i][j-1]+tab->itsTab[i][j+1])/4.0f;
			};

		};
		a_prev=a;
		a=ak(tab);
	};

};
void oblicz2(struct Siatka *tab)
{
	int i,j;
	double a=-123;
	double a_prev=123;
	while(fabs(a-a_prev)>0.001)
	{
		
		for(i=0;i<=94;i++)
		{
			tab->itsTab[i][0]=tab->itsTab[i][1];
		};
		for(i=105;i<tab->itsSizeX;i++)
		{
			tab->itsTab[i][0]=tab->itsTab[i][1];
		};
		//Hardcodujemy wartości
		for(i=0;i<=20;i++)
		{
			tab->itsTab[94][i]=tab->itsTab[93][i];
			tab->itsTab[104][i]=tab->itsTab[105][i];
		};
		for(i=94;i<105;i++)
		{
			tab->itsTab[i][20]=tab->itsTab[i][21];
		};

		tab->itsTab[94][20]=(tab->itsTab[93][20]+tab->itsTab[94][21])/2.0f;
		tab->itsTab[104][20]=(tab->itsTab[105][20]+tab->itsTab[104][21])/2.0f;


		for(i=1;i<tab->itsSizeX-1;i++)
		{
			for(j=1;j<tab->itsSizeY-1;j++)
			{
				if(i>=tab->itsPrzeszkoda[0]&&i<=tab->itsPrzeszkoda[2]&&j<=tab->itsPrzeszkoda[3]&&j>=tab->itsPrzeszkoda[1])
					continue;
				tab->itsTab[i][j]=(tab->itsTab[i-1][j]+tab->itsTab[i+1][j]+tab->itsTab[i][j-1]+tab->itsTab[i][j+1])/4.0f;
			};

		};
		a_prev=a;
		a=ak(tab);
	};
};
double kwadrat(double liczba)
{
	return liczba*liczba;
};
double ak(struct Siatka *tab)
{
	int i,j;
	double wynik=0;
	for(i=1;i<tab->itsSizeX-2;i++)
	{
		for(j=1;j<tab->itsSizeY-2;j++)
		{
			wynik+=kwadrat(tab->itsTab[i+1][j]+tab->itsTab[i+1][j+1]-tab->itsTab[i][j]-tab->itsTab[i][j+1]);	
			wynik+=kwadrat(tab->itsTab[i][j+1]+tab->itsTab[i+1][j+1]-tab->itsTab[i][j]-tab->itsTab[i+1][j]);
		};
	}
	wynik/=8.0f;
	return wynik;
};
void zapisz(struct Siatka* tab, char* path)
{
	FILE* plik;
	plik=fopen(path,"w");
	if(!plik)
	{
		printf("Blad otwarcia pliku: %s\n",path);
		exit(1);
	};
	int i,j;
	for(i=0;i<tab->itsSizeX;i++)
	{
		for(j=0;j<tab->itsSizeY;j++)
		{
			fprintf(plik,"%d %d %lf\n",i+tab->itsOffsetX, j+tab->itsOffsetY,tab->itsTab[i][j]);
		};
		fprintf(plik,"\n");
	};

	fclose(plik);
};
int in2(double val, double min, double max)
{
	return (val>min&&val<max);
};
double pochodna(struct Siatka *tab,int x, int y, int xy)
{
	double v1;
	double v2;
	v1=tab->itsTab[x][y];
	v2=xy?tab->itsTab[x][y+1]:tab->itsTab[x+1][y];
	return v2-v1;
};
void oblicz3(struct Siatka *tab)
{
	double r=1;
	double p0=10;
	double u0=1;
		
	int i,j;
	for(i=0;i<tab->itsSizeX-1;i++)
	{
		for(j=0;j<tab->itsSizeY-1;j++)
		{
				if(i>=tab->itsPrzeszkoda[0]&&i<=tab->itsPrzeszkoda[2]&&j<=tab->itsPrzeszkoda[3]&&j>=tab->itsPrzeszkoda[1])
				{
					tab->itsTab[i][j]=p0;
					continue;
				}
			else
			{
				double u=pochodna(tab,i,j,0);
				double v=-pochodna(tab,i,j,1);
				printf("%d %d %lf %lf\n",i,j,u,v);
				tab->itsTab[i][j]=p0+r*kwadrat(u0)-r*(kwadrat(u)+kwadrat(v));
			};
		};
	};
	for(i=0;i<tab->itsSizeX;i++)
	{
		tab->itsTab[i][tab->itsSizeY-1]=p0;
	};
	for(i=0;i<tab->itsSizeY;i++)
	{
		tab->itsTab[tab->itsSizeX-1][i]=p0;
	};
};
