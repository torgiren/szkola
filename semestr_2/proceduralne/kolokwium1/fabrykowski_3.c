#include <stdio.h>
void swap_string(char *tab,int size);
int main()
{
	const int size=20;
	char tab[size+1];
	
		scanf("%s",tab);
	tab[size]='\0';
	printf("%s\n",tab);
	swap_string(tab,size);
	printf("%s\n",tab);
	return 0;
};
void swap_string(char *tab,int size)
{
	int x=0;
	char tmp;
//	printf("przed; size=%d\n",size);
	for(x=0;x<size/2;x++)
	{
		if(tab[x]=='\0') break;
//		printf("%d, %d\n",x,size-x-1);
//		printf("przed:\t%c <-> %c\n",tab[x],tab[size-x-1]);
		tmp=tab[x];
		tab[x]=tab[size-x-1];
		tab[size-x-1]=tmp;
//		printf("po:\t%c <-> %c\n",tab[x],tab[size-x-1]);
//		printf("&\n");
	};
//	printf("po\n");
//	printf("%s\n",tab);
};
