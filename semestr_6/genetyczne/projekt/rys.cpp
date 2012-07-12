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
	float posX=50;
	float posY=size*20;
	gdImagePtr im=gdImageCreate(100,size*20);
	int white=gdImageColorAllocate(im,255,255,255);
	int color[3];
	color[0]=gdImageColorAllocate(im,255,0,0);
	color[1]=gdImageColorAllocate(im,0,255,0);
	color[2]=gdImageColorAllocate(im,0,0,255);
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
