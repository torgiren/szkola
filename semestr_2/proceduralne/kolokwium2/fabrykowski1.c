#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int comp(const void * a,const void *b);
int main()
{
	int *taba,*tabb;
	srand(time(NULL));
	taba=(int*)malloc(40*sizeof(int));
	tabb=(int*)malloc(40*sizeof(int));
	if(!taba || !tabb)
	{
		printf("problem z pamiecia\n");
		return -1;
	};
	int x=0;
	for(x=0;x<40;x++)
	{
		taba[x]=rand()%(95-5)+5;
		tabb[x]=rand()%(95-5)+5;
	};
	for(x=0;x<40;x++)
	{
		printf("%d: %d\t%d\n",x,taba[x],tabb[x]);
	};
	printf("-----------------------\n");
	qsort(taba,40,sizeof(int),comp);
	qsort(tabb,40,sizeof(int),comp);

	for(x=0;x<40;x++)
	{
		printf("%d: %d\t%d\n",x,taba[x],tabb[x]);
	};
	printf("-----------------------\n");

	FILE *plik;
	plik=fopen("wynik.txt","w");
	if(!plik)
	{
		printf("problem z plikiem\n");
		return -1;
	};

	int *wynik;
	for(x=0;x<40;x++)
	{
		wynik=(int*)bsearch(&taba[x],tabb,40,sizeof(int),comp);
		if(wynik)
		{
			fprintf(plik,"%d,%d,%d\n",taba[x],x,(wynik-tabb));
		};
	};
	
	fclose(plik);
	free(taba);
	free(tabb);
	return 0;
};

int comp(const void *a,const void *b)
{
	int *wa=(int*)a;
	int *wb=(int*)b;
	if(*wa<*wb)
	{
		return -1;
	};
	if(*wa>*wb)
	{
		return 1;
	};
	return 0;
};
