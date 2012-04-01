#include <stdio.h>
int fib_iter();
int fib_rek(int liczba);
int main()
{
	int liczba;
	printf("Podaj liczbe: \n");
	scanf("%d",&liczba);
	printf("liczba= %d\n",liczba);
	printf("rekurencyjnie to: %d\n",fib_rek(liczba));
	printf("interacyjnie to: %d\n",fib_iter(liczba));
	return 0;
};
int fib_rek(int liczba)
{
	if(liczba==1 || liczba==2) return 1;
	if(liczba==3) return 2;
	return fib_rek(liczba-1)+fib_rek(liczba-2);
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
