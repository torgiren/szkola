#include <stdio.h>
int comparator(const void *a,const void *b);
int main()
{
	srand(time(NULL));
	float tab[20];
	int x=0;
	for(x=0;x<20;x++)
	{
		tab[x]=rand()%(98-7)+7;
	};
	for(x=0;x<20;x++)
	{
		printf("tab[%d]=%f\n",x,tab[x]);
	};

	qsort(tab,20,sizeof(float),comparator);
	
	printf("\n");

	for(x=0;x<20;x++)
	{
		printf("tab[%d]=%f\n",x,tab[x]);
	};

	return 0;
};
int comparator(const void *a,const void *b)
{
	return (*(float*)a<*(float*)b)?(-1):(*(float*)a>*(float*)b?1:0);
};

