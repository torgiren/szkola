#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <pthread.h>
#include <cmath>
#include <cstring>
using namespace std;
class Osobnik
{
public:
	friend ostream& operator<<(ostream& out,Osobnik& osob);
	Osobnik(int dlugosc=6)
	{
		itsDlugosc=dlugosc;
		if(itsDlugosc<1) itsDlugosc=1;
//		itsWartosci.reserve(itsDlugosc);
		itsWartosci=new int[itsDlugosc];
		int x;
		for(x=0;x<itsDlugosc;x++)
		{
			itsWartosci[x]=rand()%2;
		};
	};
	int RetDlugosc() {return itsDlugosc;};
	int* RetValues()
	{
//		int x;
//		val.clear();
//		for(x=0;x<itsDlugosc;x++)
//		{
//			val.push_back(itsWartosci[x]);
//		};
		return itsWartosci;
	};
private:
	int itsDlugosc;
	int* itsWartosci;
};
class Schemat
{
public:
	friend ostream& operator<<(ostream& out,const Schemat& schema);
	Schemat(int* values,int dl)
	{
		itsWartosci=0;
//		itsWartosci=values;
		itsDlugosc=dl;
		itsWartosci=new int[itsDlugosc];
		memcpy(itsWartosci,values,dl*sizeof(int));
	};
	Schemat(const Schemat& schema)
	{
		itsDlugosc=schema.itsDlugosc;
//		itsWartosci.clear();
//		int x;
//		if(itsWartosci)
//			delete itsWartosci;
		itsWartosci=new int[itsDlugosc];
//		itsWartosci.reserve(itsDlugosc);
		memcpy(&(itsWartosci[0]),&(schema.itsWartosci[0]),itsDlugosc*sizeof(int));
//		for(x=0;x<itsDlugosc;x++)
//		{
//			itsWartosci.push_back(schema.itsWartosci[x]);
//		};
	};
	int RetDlugosc() const {return itsDlugosc;};
	bool operator<(const Schemat & schema) const
	{
		int x;
		for(x=0;x<itsDlugosc;x++)
		{
			if(itsWartosci[x]<schema.itsWartosci[x])
			{
				return true;
			};
		};
		return false;
	};
	bool operator==(const Schemat& schema) const
	{
		if(itsDlugosc!=schema.itsDlugosc)
		{
			cout<<itsDlugosc<<"\t"<<schema.itsDlugosc<<endl;
			cout<<"nie powinno wystapic w operator=="<<endl;
			return false;
		};
		int x;
		for(x=0;x<itsDlugosc;x++)
		{
			if(itsWartosci[x]!=schema.itsWartosci[x])
			{
				return false;
			};
		};
		return true;
	};
	bool operator!=(const Schemat& schema) const
	{
		return !(*this==schema);
	};
	void operator=(const Schemat& schema)
	{
		itsDlugosc=schema.itsDlugosc;
//		itsWartosci.clear();
//		int x;
//		for(x=0;x<itsDlugosc;x++)
//		{
//			itsWartosci.push_back(schema.itsWartosci[x]);
//		};
		if(itsWartosci)
			delete [] itsWartosci;
		itsWartosci=new int[itsDlugosc];
		memcpy(itsWartosci,schema.itsWartosci,itsDlugosc*sizeof(int));
	};
private:
	int itsDlugosc;
//	vector<int> itsWartosci;
	int* itsWartosci;
};
ostream& operator<<(ostream& out,Osobnik& osob)
{
	int x;
	for(x=0;x<osob.itsDlugosc;x++)
	{
		out<<osob.itsWartosci[x];
	};
	return out;
};
ostream& operator<<(ostream& out,const Schemat& schema)
{
	int x;
	for(x=0;x<schema.itsDlugosc;x++)
	{
		out<<schema.itsWartosci[x];
	};
	return out;
};
void inc(int* tab,int dl,vector<Schemat>& schema,int start=0)
{
	register int x;
	for(x=start;x<dl;x++)
	{
		int tmp=tab[x];
		tab[x]=5;
		Schemat a(tab,dl);
		schema.push_back(a);
		inc(tab,dl,schema,x+1);
		tab[x]=tmp;
	};
};
vector<Schemat> WyznaczSchematy(Osobnik& osob)
{
	vector<Schemat> wynik;

//	vector<int> tab;
//	osob.RetValues(tab);
//	int* tab=osob.RetValues();
	wynik.push_back(Schemat(osob.RetValues(),osob.RetDlugosc()));

	inc(osob.RetValues(),osob.RetDlugosc(),wynik);
	return wynik;
};
class Parametry
{
public:
	Parametry(int population, int size):
	itsPopulation(population),itsSize(size)
	{
	};
	int itsPopulation;
	int itsSize;
};
void* LiczbaSchematow(void* ptr)
{
	Parametry* param=(Parametry*)ptr;
	register int x=0;
//	set<Schemat> schematy;
	register vector<Schemat> schematy;
//	vector<Schemat>::iterator iter2;
	schematy.reserve(pow(3,param->itsSize+1));
	vector<Schemat>::iterator iter;
	for(x=0;x<param->itsPopulation;x++)
	{
		Osobnik a(param->itsSize);
		vector<Schemat> schema;
		schema=WyznaczSchematy(a);
		for(iter=schema.begin();iter!=schema.end();iter++)
		{
		
//			if(!binary_search(schematy.begin(),schematy.end(),*iter))
			if(find(schematy.begin(),schematy.end(),*iter)==schematy.end())
//			if(schematy.find(*iter)==schematy.end())
			{
				schematy.push_back(*iter);
//				schematy.insert(*iter);
//				sort_heap(schematy.begin(),schematy.end());
			};
		};
//		cout<<schema.size()<<"\t"<<schematy.size()<<endl;
	};
//	for(iter2=schematy.begin();iter2!=schematy.end();iter2++)
	{
//		cout<<*iter<<endl;
	};
//	stable_sort(schematy.begin(),schematy.end());
//	unique(schematy.begin(),schematy.end());
//	cout<<schematy.size()<<endl;
	return (void*)schematy.size();
};
int main(int argc, char* argv[])
{

	int seed;
	FILE* f = fopen("rand.dat", "r");
	int x=fscanf(f,"%d",&seed);
	fclose(f);
	srand(seed);
	
	if(argc<4)
	{
		cerr<<"Usage: "<<argv[0]<<" <rozmiar_ciagu> <liczba_ciagow> <liczba_powtorzen>"<<endl;
		return -1;
	};
	int size=atoi(argv[1]);
	int population=atoi(argv[2]);
	int tries=atoi(argv[3]);

	Parametry param(population,size);

	int* wyniki=new int[tries];
	pthread_t* watki=new pthread_t[tries];
	for(x=0;x<tries;x++)
	{
		pthread_create(&watki[x],NULL,LiczbaSchematow,(void*)&param);
	};
	for(x=0;x<tries;x++)
	{
		pthread_join(watki[x],(void**)&wyniki[x]);
	};
	float srednia=0;
	for(x=0;x<tries;x++)
	{
		srednia+=wyniki[x];
	};
	srednia/=tries;
	cout<<srednia<<endl;

	f=fopen("rand.dat","w");
	fprintf(f,"%d",rand());
	fclose(f);

	return 0;
};
