#include <gd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct __klocek
{
	float itsW;
	float itsH;
	int itsObrot;
	float itsX;
} klocek;
typedef struct __wejscie
{
	int itsNr;
	int itsObr;
	float itsX;
} wejscie;
klocek *tab;
int main(int argc, char* argv[])
{
	if(argc<3)
	{
		fprintf(stderr,"Blad wywolania. TODO opis bledu\n");
		return 1;
	};
	FILE* plik;
	plik=fopen(argv[1],"r");
	if(!plik)
	{
		fprintf(stderr,"Can't open file %s\n",argv[1]);
		return 2;
	};
	int size;
	fscanf(plik,"%d",&size);
	if(!(size>0))
	{
		fprintf(stderr,"Data error. Wrong number of blocks\n");
		return 3;
	};
	tab=(klocek*)malloc(size*sizeof(klocek));
	memset(tab,0,sizeof(klocek)*size);
	int i;
	for(i=0;i<size;i++)
	{
		int nr;
		float w,h;
		fscanf(plik,"%d %f %f",&nr,&w,&h);
		tab[nr].itsW=w;
		tab[nr].itsH=h;
//		printf("Mam klocka z parametrow: %f %f %d %f\n",tab[nr].itsW,tab[nr].itsH,tab[nr].itsObrot,tab[nr].itsX);
	};
	fclose(plik);
	plik=fopen(argv[2],"r");
	wejscie* data=(wejscie*)malloc(size*sizeof(wejscie));
	for(i=0;i<size;i++)
	{
		fscanf(plik,"%d %d %f",&data[i].itsNr,&data[i].itsObr,&data[i].itsX);
	};
	fclose(plik);
	float posX=50;
	float posY=size*20;
	int j=0;
	int color[4];
	gdImagePtr im;
	for(j=1;j<size;j++)
	{
		for(i=j;i>0;i--)
		{
			float posX=50;
			float posY=0;
			float srodek=0;
			float srodek_suma=0;
			im=gdImageCreate(100,j*10+100);
			int white=gdImageColorAllocate(im,255,255,255);
			color[0]=gdImageColorAllocate(im,255,0,0);
			color[1]=gdImageColorAllocate(im,0,255,0);
			color[2]=gdImageColorAllocate(im,0,0,255);
			color[3]=gdImageColorAllocate(im,255,0,255);
			int num=0;
			int k;
			for(k=j,num=0;k>=i;k--,num++)
			{
				float w=data[k].itsObr?tab[data[k].itsNr].itsH:tab[data[k].itsNr].itsW;
				float h=data[k].itsObr?tab[data[k].itsNr].itsW:tab[data[k].itsNr].itsH;
				h=10;
				gdImageFilledRectangle(im,posX,posY,posX+w,posY+h,color[k%3]);
				srodek_suma+=posX+w/2.0;
				posX-=data[k].itsX;
				posY+=h;
			};
			srodek=srodek_suma/(float)(num);	
			float w=data[k].itsObr?tab[data[k].itsNr].itsH:tab[data[k].itsNr].itsW;
			float h=data[k].itsObr?tab[data[k].itsNr].itsW:tab[data[k].itsNr].itsH;
			gdImageFilledRectangle(im,posX,posY,posX+w,posY+h,color[k%3]);


			gdImageFilledEllipse(im,srodek,posY+2.5,2,2,color[3]);
			char nazwa[255];
			sprintf(nazwa,"details/rys_%03d_%03d.png",j,k);
			printf("Nazwa: %s\n",nazwa);
			plik=fopen(nazwa,"w");
			if(!plik)
			{
				printf("problem otwarci pliku\n");
			};
			gdImagePng(im,plik);
			fclose(plik);
			gdImageDestroy(im);
				
		};




	};
	im=gdImageCreate(100,size*20);
	int white=gdImageColorAllocate(im,255,255,255);
	color[0]=gdImageColorAllocate(im,255,0,0);
	color[1]=gdImageColorAllocate(im,0,255,0);
	color[2]=gdImageColorAllocate(im,0,0,255);
	color[3]=gdImageColorAllocate(im,0,255,255);
	
	plik=fopen(argv[2],"r");
	for(i=0;i<size;i++)
	{
		int nr;
		int obr;
		float dx;
		fscanf(plik,"%d %d %f",&nr,&obr,&dx);
		float w=obr?tab[nr].itsH:tab[nr].itsW;
		float h=obr?tab[nr].itsW:tab[nr].itsH;
		posX+=dx;
		posY-=h;
		gdImageFilledRectangle(im,posX,posY,posX+w,posY+h,color[i%3]);
	};
	fclose(plik);
	plik=fopen("rys.png","w");
	gdImagePng(im,plik);
	fclose(plik);
	gdImageDestroy(im);

};
