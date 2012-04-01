#include <stdio.h>
struct zespolona
{
	double a,b;
};
struct zespolona dodaj(double a1,double b1,double a2,double b2);
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

	struct zespolona z3=dodaj(z1.a,z1.b,z2.a,z2.b);
	printf("Z3= %lf + i%lf\n",z3.a,z3.b);
	
	return 0;
};
struct zespolona dodaj(double a1,double b1,double a2,double b2)
{
	struct zespolona wynik;
	wynik.a=a1+a2;
	wynik.b=b1+b2;
	return wynik;
};

