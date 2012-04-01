#include <stdio.h>
void tab_print(int tab[],int size,int dir); //dir >= 0 rosnaco, dir<0 malejaco
int main()
{
	srand(time(NULL));
	const int SIZE=10;
	int tab[SIZE];
	int x=0;
	for(x=0;x<SIZE;x++)
	{
		tab[x]=rand()%24+34;
//		printf("%d\n",tab[x]);
	};
	for(x=0;x<SIZE;x++)
	{
		printf("tab[%d]=%d\n",x,tab[x]);
	};
	printf("rekurencyjnie: \n");
	tab_print(tab,SIZE,1);
	return 0;
};
void tab_print(int tab[], int size, int dir)
{
	static int act=0;
	if(act>=size||act<0)
	{
		return;
	};
	int current=dir>=0?act:size-act-1;
	printf("tab[%d]=%d\n",current,tab[current]);
	act++;
	tab_print(tab,size,dir);
};
