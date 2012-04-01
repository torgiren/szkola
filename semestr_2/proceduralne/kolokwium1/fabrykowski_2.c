#include <stdio.h>
int main()
{
	int min,max,suma=0,input,ilosc=0;
	while(1)
	{
		scanf("%d",&input);
		if(!input) break;
		if(!ilosc)
		{
			min=max=input;
		};
		if(input>max) max=input;
		if(input<min) min=input;
		suma+=input;
		ilosc++;
	};
	if(!ilosc)
	{
		printf("Blad\n");
	}
	else
	{
		printf("Max: %d\nMin: %d\nSrednia: %f\n",max,min,(float)suma/ilosc);
	};
	return 0;
};
