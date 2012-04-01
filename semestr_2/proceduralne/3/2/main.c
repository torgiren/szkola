#include <stdio.h>
#include <math.h>
int main()
{
	int x;
	int licznik=0;
	for(x=0;x<100;x++)
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
			printf("%d\n",x);
			licznik++;
		};
	};
	printf("ich liczba to %d\n",licznik);
	return 0;
};
