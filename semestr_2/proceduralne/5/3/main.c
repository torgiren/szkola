#include <stdio.h>
#include <math.h>
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
float calcD(float sr,int num, float tab[])
{
	float wynik=0;
	int x=0;
	for(x=0;x<num;x++)
	{
		wynik+=(tab[x]-sr)*(tab[x]-sr);
	}
	return wynik;
};
float calcA(float d, float sr,int num,float tabX[],float tabY[])
{
	float wynik=0;
	int x=0;
	for(x=0;x<num;x++)
	{
		wynik+=tabY[x]*(tabX[x]-sr);
	};
	return wynik/d;
	
};
int pierwszeZnaczace(float liczba)
{
	if(liczba)
	{
		int wynik=0;
		while(liczba<1)
		{
			liczba*=10;
			wynik++;
		};
		return wynik;
	}
	return -1;
};
float calcDY(float a,float b,int num,float tabX[],float tabY[])
{
	float wynik=0;
	int x=0;
	float atom;
	for(x=0;x<num;x++)
	{
		
		atom=tabY[x]-(a*tabX[x]+b);
		atom*=atom;
		wynik+=atom;
	};
	wynik/=num-2;
	wynik=sqrt(wynik);
	return wynik;
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
	
	float dX=calcD(srX,15,tabx);
	printf("d dla x: %.0f\n",dX);

	float a=calcA(dX,srX,15,tabx,taby);
	float b=srY-a*srX;
	printf("a: %.3f\nb: %.1f\n",a,b);

	float dY=calcDY(a,b,15,tabx,taby);
	float dA=dY/sqrt(dX);
	float dB=dY*sqrt(1/15+srX*srX/dX);
	printf("dy: %.2f\n", dY);
	printf("da: %.3f\n", dA);
	printf("db: %.1f\n", dB);




	printf("a: %.*f\n",pierwszeZnaczace(dA),a);
	printf("b: %.*f\n",pierwszeZnaczace(dB),b);
	
	printf("pierwsze znaczace dla dB: %d\n",pierwszeZnaczace(dB));


	char formatA[25];
	char formatB[25];
	sprintf(formatA,"wartosc A: %%.%df\n",pierwszeZnaczace(dA));
	sprintf(formatB,"wartosc B: %%.%df\n",pierwszeZnaczace(dB));
	printf(formatA,a);
	printf(formatB,b);
	return 0;
};
