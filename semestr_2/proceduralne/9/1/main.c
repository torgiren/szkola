#include <stdio.h>
struct zespolona
{
	double a,b;
};
int main()
{
	struct zespolona z1,z2;
	printf("Z=a+ib\n");
	printf("Z1:\npodaj a: ");
	scanf("%lf",&z1.a);
	printf("podaj b: ");
	scanf("%lf",&z1.b);

	printf("Z2:\npodaj a: ");
	scanf("%lf",&z2.a);
	printf("podaj b: ");
	scanf("%lf",&z2.b);

	printf("Z1= %lf + i%lf\n",z1.a,z1.b);
	printf("Z2= %lf + i%lf\n",z2.a,z2.b);

	return 0;
};
