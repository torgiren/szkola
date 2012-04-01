#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *file;
	file=fopen("input.txt","r");
	if(!file)
	{
		printf("file error...\n");
		return 1;
	};
	int wiersze=0;
	int tmp;
	while(!feof(file))
	{
		fscanf(file,"%d",&tmp);
		wiersze++;
	};
	wiersze--;
	printf("%d\n",wiersze);
	int *tab=(int*)calloc(sizeof(int),wiersze);
	if(!tab)
	{
		printf("mem error\n");
		return 1;
	};
	rewind(file);
	int x=0;
	for(x=0;x<wiersze;x++)
	{
		fscanf(file,"%d",&tab[x]);
	};
	for(x=0;x<wiersze;x++)
	{
		printf("%d\n",tab[x]);
	};
	printf("O ile chcesz zwiekszyc? ");
	int resize;
	scanf("%d",&resize);
	wiersze+=resize;
	printf("wiersze=%d\n",wiersze);
	tab=(int*)realloc(tab,sizeof(int)*(wiersze));
	if(!tab)
	{
		printf("mem error\n");
		return 1;
	};
	printf("****");
	for(x=resize;x>0;x--)
	{
		tab[wiersze-x]=5+rand()%2;
	};
	printf("$$$$");
	for(x=0;x<wiersze;x++)
	{
		printf("%d\n",tab[x]);
//		printf("%d\n",x);
	};
	printf("@@@@");
	fclose(file);
	file=fopen("wynik.dat","wb");
	if(!file)
	{
		printf("file error\n");
		return 1;

	};
	for(x=0;x<wiersze;x++)
	{
//		fwrite(tab[x],sizeof(int),1,file);
	};
	fwrite(tab,sizeof(int),wiersze,file);
	fclose(file);
	if(tab)
	{
		free(tab);
		tab=NULL;
	};
	return 0;
};
