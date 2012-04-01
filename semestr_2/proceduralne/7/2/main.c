#include <stdio.h>
void sort(int *a, int *b,int *c);
int main()
{
	printf("Podaj: a b c\n");
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("a=%d\tb=%d\tc=%d\n",a,b,c);
	sort(&a,&b,&c);
	printf("a=%d\tb=%d\tc=%d\n",a,b,c);

	return 0;
};
void sort(int *a, int *b, int *c)
{
	int tmp;
	if(*a>*b)
	{
		tmp=*b;
		*b=*a;
		*a=tmp;
	};
	if(*b>*c)
	{
		tmp=*b;
		*b=*c;
		*c=tmp;
	};
	if(*a>*b)
	{
		tmp=*b;
		*b=*a;
		*a=tmp;
	};
};
