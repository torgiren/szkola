#include <stdio.h>
#include <stdlib.h>
struct zespolona
{
	double a,b;
};
struct zespolona2
{
	struct zespolona liczba;
	double modul;
};
struct zespolona dodaj(double a1,double b1,double a2,double b2);
void podziel(struct zespolona z1,struct zespolona z2, struct zespolona *z3);
struct zespolona pomnoz(const struct zespolona *z1,const struct zespolona *z2);
void licz_modul(struct zespolona2 *liczba);
int comp(const void *z1,const void *z2);
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

/*
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
*/
	struct zespolona2 *tab2=calloc(sizeof(struct zespolona2),rozmiar);
	if(!tab2)
	{
		printf("mem error\n");
		return -1;
	};
	int x;
	for(x=0;x<rozmiar;x++)
	{
		tab2[x].liczba.a=6+rand()%(10-6);
		tab2[x].liczba.b=5+rand()%(12-5);
		licz_modul(&tab2[x]);
		printf("| L%d= %lf + i%lf | = %lf\n",x,tab2[x].liczba.a,tab2[x].liczba.b,tab2[x].modul);
	};

	qsort(tab2,rozmiar,sizeof(struct zespolona2),comp);
	printf("Sortowanie...");
	for(x=0;x<rozmiar;x++)
	{
		printf("| L%d= %lf + i%lf | = %lf\n",x,tab2[x].liczba.a,tab2[x].liczba.b,tab2[x].modul);
	};
	printf("podaj modul ktorego szukasz: ");
	struct zespolona2 szukana;
	scanf("%lf",&szukana.modul);
	struct zespolona2 *znalezione;
	znalezione=(struct zespolona2*)bsearch(&szukana,tab2,rozmiar,sizeof(struct zespolona2),comp);
	if(!znalezione)
	{
		printf("Nie ma takiego modulu\n");
	}
	else
	{
		printf("Znaleziono:\n");
		printf("| %lf + i%lf | = %lf\n",znalezione->liczba.a,znalezione->liczba.b,znalezione->modul);
	};
	free(tab2);
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
void licz_modul(struct zespolona2 *z1)
{
	z1->modul=sqrt(z1->liczba.a*z1->liczba.a+z1->liczba.b*z1->liczba.b);
};
int comp(const void *z1,const void *z2)
{
	struct zespolona2 *l1,*l2;
	l1=(struct zespolona2*)z1;
	l2=(struct zespolona2*)z2;
	
	if(l1->modul<l2->modul) return -1;
	if(l1->modul>l2->modul) return 1;
	return 0;
};
