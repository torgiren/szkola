#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct Siatka
{
	double **itsPsi;
	double **itsZeta;
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
double szescian(double liczba);
double ak_psi(struct Siatka *tab);
double ak_zeta(struct Siatka *tab);
void zapiszPsi(struct Siatka* tab, char* path,double i_double);
void zapiszZeta(struct Siatka* tab, char* path,double i_double);
void zapiszU(struct Siatka* tab, char* path,double i_double);
void zad1();
int main()
{
	zad1();
	return 0;
};
void zad1()
{
	struct Siatka siatka;
	alloc(&siatka,250,81,100,40,0,0,0,0);
	poczatkowe(&siatka);
	oblicz(&siatka);
	zapiszPsi(&siatka,"zad1_psi_0.dat",0);
	zapiszPsi(&siatka,"zad1_psi_0.7.dat",0.7);
	zapiszZeta(&siatka,"zad1_zeta_0.dat",0);
	zapiszZeta(&siatka,"zad1_zeta_0.7.dat",0.7);
	zapiszU(&siatka,"zad1_u_0.dat",0);
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
	tab->itsPsi=(double**)malloc(tab->itsSizeX*sizeof(double*));
	tab->itsZeta=(double**)malloc(tab->itsSizeX*sizeof(double*));
	int i;
	for(i=0;i<tab->itsSizeX;i++)
	{
		tab->itsPsi[i]=(double*)malloc(tab->itsSizeY*sizeof(double));
		tab->itsZeta[i]=(double*)malloc(tab->itsSizeY*sizeof(double));
	};
};
void dealloc(struct Siatka *tab)
{
	int i;
	for(i=0;i<tab->itsSizeX;i++)
	{
		free(tab->itsPsi[i]);
		free(tab->itsZeta[i]);
	};
	free(tab->itsPsi);
	free(tab->itsZeta);
};
void poczatkowe(struct Siatka *tab)
{
	double Q=-1;
	double mi=1;
	int i;
	for(i=0;i<tab->itsSizeX;i++)
	{
		memset(tab->itsPsi[i],0,sizeof(double)*tab->itsSizeY);
		memset(tab->itsZeta[i],0,sizeof(double)*tab->itsSizeY);
	};

	for(i=0;i<tab->itsSizeY;i++)
	{
		tab->itsPsi[0][i]=Q/(2*mi)*(szescian(0.01*(i-tab->itsOffsetY))/3.0f-0.4f*0.4f*(float)(i-tab->itsOffsetY)*0.01);
		tab->itsPsi[tab->itsSizeX-1][i]=Q/(2*mi)*(szescian(0.01*(i-tab->itsOffsetY))/3.0f-0.4f*0.4f*(float)(i-tab->itsOffsetY)*0.01);


		tab->itsZeta[0][i]=Q/(2*mi)*(2*(float)(i-tab->itsOffsetY)*0.01f);
		tab->itsZeta[tab->itsSizeX-1][i]=Q/(2*mi)*(2*(float)(i-tab->itsOffsetY)*0.01f);
	};
	for(i=0;i<tab->itsSizeX;i++)
	{
		tab->itsPsi[i][0]=Q/(2*mi)*(szescian(0.01*(0-tab->itsOffsetY))/3.0f-0.4f*0.4f*(float)(0-tab->itsOffsetY)*0.01);
		tab->itsPsi[i][tab->itsSizeY-1]=Q/(2*mi)*(szescian(0.01*(tab->itsSizeY-tab->itsOffsetY))/3.0f-0.4f*0.4f*(float)(tab->itsSizeY-tab->itsOffsetY)*0.01);

		tab->itsZeta[i][0]=Q/(2*mi)*(2*(float)(0-tab->itsOffsetY)*0.01f);
		tab->itsZeta[i][tab->itsSizeY-1]=Q/(2*mi)*(2*(float)(tab->itsSizeY-1-tab->itsOffsetY)*0.01f);
	};
/*
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
*/
};
double kwadrat(double liczba)
{
	return liczba*liczba;
};
double szescian(double liczba)
{
	return liczba*liczba*liczba;
};
void zapiszPsi(struct Siatka* tab, char* path,double i_double)
{
	FILE* plik;
	plik=fopen(path,"w");
	if(!plik)
	{
		printf("Blad otwarcia pliku: %s\n",path);
		exit(1);
	};
	int i,j;
	i_double*=100;
	i=i_double;
	i+=tab->itsOffsetX;
//	int i,j;
//	for(i=0;i<tab->itsSizeX;i++)
	{
		for(j=0;j<tab->itsSizeY;j++)
		{
			fprintf(plik,"%d %d %lf %lf\n",i-tab->itsOffsetX, j-tab->itsOffsetY,tab->itsPsi[i][j],-1.0f/2.0f*(szescian(0.01*(j-tab->itsOffsetY))/3.0f-0.4f*0.4f*(float)(j-tab->itsOffsetY)*0.01));
			
		};
//		fprintf(plik,"\n");
	};

	fclose(plik);
};
void zapiszZeta(struct Siatka* tab, char* path,double i_double)
{
	FILE* plik;
	plik=fopen(path,"w");
	if(!plik)
	{
		printf("Blad otwarcia pliku: %s\n",path);
		exit(1);
	};
	int i,j;
	i_double*=100;
	i=i_double;
	i+=tab->itsOffsetX;
//	for(i=0;i<tab->itsSizeX;i++)
//	{
		for(j=0;j<tab->itsSizeY;j++)
		{
			fprintf(plik,"%d %d %lf %lf\n",i-tab->itsOffsetX, j-tab->itsOffsetY,tab->itsZeta[i][j],-1.0f/2.0f*(2*(float)(j-tab->itsOffsetY)*0.01f));
		};
//		fprintf(plik,"\n");
//	};

	fclose(plik);
};
void zapiszU(struct Siatka* tab, char* path,double i_double)
{
	FILE* plik;
	plik=fopen(path,"w");
	if(!plik)
	{
		printf("Blad otwarcia pliku: %s\n",path);
		exit(1);
	};
	int i,j;
	i_double*=100;
	i=i_double;
	i+=tab->itsOffsetX;
//	for(i=0;i<tab->itsSizeX;i++)
//	{
		for(j=0;j<tab->itsSizeY;j++)
		{
			fprintf(plik,"%d %d %lf\n",i-tab->itsOffsetX, j-tab->itsOffsetY,-1.0f/2.0f*(((float)(j-tab->itsOffsetY)*0.01-0.4)*((float)(j-tab->itsOffsetY)*0.01+0.4)));
		};
//		fprintf(plik,"\n");
//	};

	fclose(plik);
};
void oblicz(struct Siatka *tab)
{
	int i,j;
	int iter=0;
	double a1=-123,a2=-123;
	double a1_prev=123,a2_prev=123;
	while(fabs(a1-a1_prev)>0.0000000001||fabs(a2-a2_prev)>0.0000000001)
	{
		for(i=1;i<tab->itsSizeX-1;i++)
		{
			for(j=1;j<tab->itsSizeY-1;j++)
			{
				tab->itsPsi[i][j]=(tab->itsPsi[i+1][j]+tab->itsPsi[i-1][j]+tab->itsPsi[i][j-1]+tab->itsPsi[i][j+1]-tab->itsZeta[i][j]*0.01*0.01)/4.0f;
				tab->itsZeta[i][j]=(tab->itsZeta[i+1][j]+tab->itsZeta[i-1][j]+tab->itsZeta[i][j-1]+tab->itsZeta[i][j+1])/4.0f-
					((tab->itsPsi[i][j+1]-tab->itsPsi[i][j-1])*(tab->itsZeta[i+1][j]-tab->itsZeta[i-1][j])-
					(tab->itsPsi[i+1][j]-tab->itsPsi[i-1][j])*(tab->itsZeta[i][j+1]-tab->itsZeta[i][j-1]))/16.0f;
			};
		};
		a1_prev=a1;
		a2_prev=a2;
		a1=ak_psi(tab);
		a2=ak_zeta(tab);
		printf("Iter: %d\n",iter++);
		printf("a1=%f\ta2=%f\n",a1,a2);
	};
};
double ak_psi(struct Siatka *tab)
{
	int i,j;
	double wynik=0;
	for(i=1;i<tab->itsSizeX-2;i++)
	{
		for(j=1;j<tab->itsSizeY-2;j++)
		{
			wynik+=kwadrat(tab->itsPsi[i+1][j]+tab->itsPsi[i+1][j+1]-tab->itsPsi[i][j]-tab->itsPsi[i][j+1]);	
			wynik+=kwadrat(tab->itsPsi[i][j+1]+tab->itsPsi[i+1][j+1]-tab->itsPsi[i][j]-tab->itsPsi[i+1][j]);
		};
	}
	wynik/=8.0f;
	return wynik;
};
double ak_zeta(struct Siatka *tab)
{
	int i,j;
	double wynik=0;
	for(i=1;i<tab->itsSizeX-2;i++)
	{
		for(j=1;j<tab->itsSizeY-2;j++)
		{
			wynik+=kwadrat(tab->itsZeta[i+1][j]+tab->itsZeta[i+1][j+1]-tab->itsZeta[i][j]-tab->itsZeta[i][j+1]);	
			wynik+=kwadrat(tab->itsZeta[i][j+1]+tab->itsZeta[i+1][j+1]-tab->itsZeta[i][j]-tab->itsZeta[i+1][j]);
		};
	}
	wynik/=8.0f;
	return wynik;
};
