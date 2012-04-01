#include <stdio.h>
int main()
{
	int a=3;
	int b=17;
	float c;
	c=(float)b/a;
	printf("%f\n",c);
	printf("%d\n",(a=5));
	int d;
	d=2;
	d=d++;
	printf("%d\n",d);
	return 0;
};
