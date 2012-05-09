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
void oblicz(struct Siatka *tab);
double kwadrat(double liczba);
double ak(struct Siatka *tab);
void zapisz(struct Siatka *tab,char* path);
int main()
{
	struct Siatka siatka;
	alloc(&siatka,200,100,0,50,95,105,50,70);
	poczatkowe(&siatka);
	zapisz(&siatka,"zad1_pocz.dat");
	oblicz(&siatka);
	zapisz(&siatka,"zad1.dat");
	dealloc(&siatka);
	return 0;
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
		tab->itsTab[1][i]=u0;
	};
	for(i=0;i<tab->itsSizeX;i++)
	{
		tab->itsTab[i][tab->itsSizeY-1]=u0*(double)(i+tab->itsOffsetX);
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
