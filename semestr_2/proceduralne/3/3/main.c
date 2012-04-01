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
int main()
{
	int x=0;
	for(x=0;x<10;x++)
	{
		printf("Liczba liczb pierwszych w %d setce to: %d\n",x+1,pierwsze(x*100,(x+1)*100));
	};
};
