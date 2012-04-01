#include <stdio.h>
#include <stdlib.h>
int main()
{
	int ilosc;
	printf("Podaj rozmiar: ");
	scanf("%d",&ilosc);
	if(ilosc<1)
	{
		printf("Troche malo...\n");
		return 1;
	};
	float *tab=calloc(sizeof(float),ilosc);
	if(!tab)
	{
		printf("Maly problem z pamietcia...\n");
		return 2;
	};
	int x=0;
	srand(time(NULL));
	for(x=0;x<ilosc;x++)
	{
		tab[x]=rand()%(341-230)+230;
	};
	FILE *plik=fopen("wyjcie.txt","w");
	if(!plik)
	{
		printf("blad pliku...");
		return 3;
	};
	for(x=0;x<ilosc;x++)
	{
		fprintf(plik,"%.2f\n",tab[x]);
	};
	fclose(plik);
	if(tab)
	{
		free(tab);
		tab=NULL;
	};
	return 0;
};
