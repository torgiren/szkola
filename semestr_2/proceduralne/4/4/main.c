#include <stdio.h>
int main(void)
{
	char a[10]={'\0'},b[10]="123456789";
	int x=0;
	printf("a->%s\t,b->%s\n",a,b);
	while(a[x]=b[x++]);
	printf("a->%s\t,b->%s\n",a,b);
	return 0;
}
