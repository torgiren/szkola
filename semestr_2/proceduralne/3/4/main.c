#include <stdio.h>
#include <math.h>
int pierwsze(int from, int to)
{
	int x;
	int licznik=0;
	for(x=from;x<to;x++)
	{
		int y;
		char pierwsza=1;	
		if(!(x%2) && x!=2 || x==1) continue;
		for(y=3;y<sqrt(x)+1;y=y+2)
		{
//			printf("x= %d\t y= %d\n",x,y);
			if(!(x%y))
			{
				pierwsza=0;
				break;
			};
		};
		if(pierwsza)
		{
			licznik++;
		};
	};
	return licznik;
};
int main(int argc,char *argv[])
{
	if(argc<3)
	{
		printf("Usage: %s <from> <to>\n",argv[0]);
		return -1;
	};
	int first=atoi(argv[1]);
	int sec=atoi(argv[2]);
	if(first>sec)
	{
		printf("Bledny przedzial\n");
		return 1;
	};
	printf("W zadanym przedziale jest: %d liczb pierwszych\n",pierwsze(first,sec));
};
