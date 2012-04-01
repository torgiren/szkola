#include <stdio.h>
void printTab(char *prefix,int num,float tab[],int kropka)
{
	printf("%s|",prefix);
	int x=0;
	for(x=0;x<num;x++)
	{
		if(kropka)
			printf("%5.1f|",tab[x]);
		else
			printf("%5.0f|",tab[x]);
	};
	printf("\n");
};
float srednia(int num,float tab[])
{
	float wynik=0;
	int x=0;
	for(x=0;x<num;x++)
	{
		wynik+=tab[x];
	};
	return wynik/num;
};
int main()
{
	float tabx[15];
	float taby[]={109.4,110.1,112.0,114.7,116.0,118.1,119.5,121.8,123.1,124.9,127.6,129.4,130.6,131.9,134.1};
	int x;

	for(x=1,tabx[0]=25;x<15;x++)
	{
		tabx[x]=tabx[x-1]+5;
	};
	printf("   i|");
	for(x=0;x<15;x++)
	{
		printf("%5d|",x);
	};
	printf("\n");
	printTab("x[i]",15,tabx,0);
	printTab("y[i]",15,taby,1);

	float srX=srednia(15,tabx);
	float srY=srednia(15,taby);
	printf("srednia dla x: %.0f\nsrednia dla y: %.2f\n",srX,srY);
	

	return 0;
};
