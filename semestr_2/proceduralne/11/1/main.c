#include <stdio.h>
#include "drzewo.h"
int main()
{
	struct tnode *drzewo=NULL;
	int tab[]={15,5,16,20,3,12,18,23,10,13,6,7};
	int size=12;
	int x=0;
	for(x=0;x<size;x++)
	{
		AddLeaf(tab[x],&drzewo);
	};
	print_post(drzewo);
	printf("Min: %d\n",find_min(drzewo)->value);
	printf("Max; %d\n",find_max(drzewo)->value);
	printf("Znaleziona: %p\n",find(23,drzewo));

	printf("%d\n",Succesor(find(15,drzewo))->value);

	for(x=0;x<size;x++)
	{
//		printf("nastepnikiem %d jest %d\n",tab[x],Succesor(find(tab[x],drzewo))->value);
	};
	
	printf("nastepnikiem %d jest %d\n",tab[x],Succesor(find(16,drzewo))->value);

	del(drzewo);
	printf("koniec");
	return 0;
};
