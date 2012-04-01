#include <stdio.h>
#include <stdlib.h>
struct zespolona
{
	double a,b;
};
struct zespolona dodaj(double a1,double b1,double a2,double b2);
void podziel(struct zespolona z1,struct zespolona z2, struct zespolona *z3);
struct zespolona pomnoz(const struct zespolona *z1,const struct zespolona *z2);
int main()
{
	srand(time(NULL));
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

//	struct zespolona z3=dodaj(z1.a,z1.b,z2.a,z2.b);
//	printf("Z3= %lf + i%lf\n",z3.a,z3.b);

//	struct zespolona z4;
//	podziel(z1,z2,&z4);
//	printf("Z4= %lf + i%lf\n",z4.a,z4.b);
	
//	struct zespolona z5=pomnoz(&z1,&z2);
//	printf("Z5= %lf + i%lf\n",z5.a,z5.b);


	int rozmiar;
	printf("Podaj rozmiar tablicy: ");
	scanf("%d",&rozmiar);
	struct zespolona *tab=calloc(sizeof(struct zespolona),rozmiar);
	if(!tab)
	{
		printf("mem error\n");
		return -1;
	};
	FILE *file=fopen("txt","w");
	if(!file)
	{
		printf("File error\n");
		return -1;
	};
	int x=0;
	for(x=0;x<rozmiar;x++)
	{
		tab[x].a=6+rand()%(10-6);
		tab[x].b=5+rand()%(12-5);
		printf("L%d= %lf + i%lf\n",x,tab[x].a,tab[x].b);
		fprintf(file,"L%d= %lf + i%lf\n",x,tab[x].a,tab[x].b);
		
	};
	fclose(file);
	file=fopen("bin","wb");
	if(!file)
	{
		printf("File error\n");
		return -1;
	};
	fwrite(tab,sizeof(struct zespolona),rozmiar,file);
	fclose(file);
	free(tab);
	return 0;
};
struct zespolona dodaj(double a1,double b1,double a2,double b2)
{
	struct zespolona wynik;
	wynik.a=a1+a2;
	wynik.b=b1+b2;
	return wynik;
};
void podziel(struct zespolona z1,struct zespolona z2, struct zespolona *z3)
{
	z3->a=(z1.a*z2.a+z1.b*z2.b)/(z2.a*z2.a+z2.b*z2.b);
	z3->b=(z1.b*z2.a-z1.a*z2.b)/(z2.a*z2.a+z2.b*z2.b);
};
struct zespolona pomnoz(const struct zespolona *z1,const struct zespolona *z2)
{
	struct zespolona wynik;
	wynik.a=z1->a*z2->a-z1->b*z2->b;
	wynik.b=z1->b*z2->a+z1->a*z2->b;
	return wynik;
};
