#include <stdio.h>
int fib_iter();
int fib_rek(int liczba,int depth);
int main()
{
	int liczba;
	printf("Podaj liczbe: \n");
	scanf("%d",&liczba);
	printf("liczba= %d\n",liczba);
	printf("rekurencyjnie to: %d\n",fib_rek(liczba,0));
//	printf("interacyjnie to: %d\n",fib_iter(liczba));
	return 0;
};
int fib_rek(int liczba,int depth)
{
	static int l=0;
	l++;
	int x=0;
	printf("%d",depth);
	for(x=0;x<depth-1;x++)
	{
		printf(".");
	};
	printf(", ");
	if(liczba==1)
	{
		printf("Zwracam f(%d), l=%d\n",1,l);
		return 1;
	};
	if(liczba==2)
	{
		printf("Zwrafam f(%d), l=%d\n",2,l);
		return 1;
	};
/*
if(liczba==3)
	{
		printf("Zwracam f(%d), l=%d\n",2,l);
		return 2;
	};
*/
	printf("Obliczam f(%d), l=%d\n",liczba,l);
	return fib_rek(liczba-1,depth+1)+fib_rek(liczba-2,depth+1);
};
int fib_iter(int liczba)
{
	int x;
	int first=1,sec=1,tmp=0;;
	for(x=2;x<liczba;x++)
	{
		sec+=first;
		first=sec-first;
	};
	return sec;
};
