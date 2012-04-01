#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
vector<float> rozniczkuj(vector<float> wsp);
float oblicz(vector<float>,float x1);
void zapisz(string path,vector<float>,float a, float b,float krok);
float znajdz(string path,vector<float> wsp,float a, float b,float eps);
int main()
{
/*
	int stopien;
	cout<<"Podaj stopien wielomianu: ";
	cin>>stopien;
	vector<float> wsp;
	if(stopien>20)
	{
		cout<<"Za duzo"<<endl;
		return 1;
	};
	int x=0;
	for(x=0;x<stopien;x++)
	{
		cout<<"Podaj wspolczynnik "<<(char)('a'+x)<<": ";
		float tmp;
		cin>>tmp;
		wsp.push_back(tmp);
	};
*/
	int stopien=5;
	vector<float> wsp;
	wsp.push_back(1);
	wsp.push_back(-9);
	wsp.push_back(29);
	wsp.push_back(-39);
	wsp.push_back(18);

	cout<<"Mamy "<<stopien-1<<" pierwiastki/ow"<<endl;

	rozniczkuj(wsp);
	cout<<"rysowanie funkcji"<<endl;
	zapisz("f.dat",wsp,0,4,0.0001);
	cout<<"wyznaczanie pierwszego pierwiastka..."<<endl;
	cout<<znajdz("1.dat",wsp,0.8,1.2,0.000001)<<endl;
	cout<<"wyznaczanie drugiego pierwiastka..."<<endl;
	cout<<znajdz("2.dat",wsp,01.8,2.2,0.000001)<<endl;
	cout<<"wyznaczanie trzeciego pierwiastka..."<<endl;
	cout<<znajdz("3.dat",wsp,2.8,3.2,0.000001)<<endl;
};
vector<float> rozniczkuj(vector<float> wsp)
{
	vector<float> wynik;
	unsigned int x;
	for(x=0;x<wsp.size()-1;x++)
	{
	//	cout<<"Przed: "<<wsp[x]<<endl;
		wynik.push_back(wsp[x]*(wsp.size()-x-1));
	//	cout<<"Po: "<<wynik[x]<<endl;
	};
	return wynik;	
};
float oblicz(vector<float> wsp,float x1)
{
	float wynik=0;
	unsigned int x;
	for(x=0;x<wsp.size();x++)
	{
		wynik+=wsp[x]*pow(x1,wsp.size()-x-1);
	};
	return wynik;
};
void zapisz(string path,vector<float> wsp,float a, float b,float krok)
{
	ofstream plik;
	plik.open(path.c_str());
	float x;
	for(x=a;x<b;x+=krok)
	{
		plik<<x<<" "<<oblicz(wsp,x)<<endl;
	};
	plik.close();
};
float znajdz(string path,vector<float> wsp,float a, float b,float eps)
{
	ofstream plik;
	plik.open(path.c_str());
	int x=0;
	while(true)
	{
		float f=oblicz(wsp,b);
		float fp=oblicz(rozniczkuj(wsp),b);
		float x1=b-f/fp;
//		float tmp=oblicz(wsp,x1);
		float tmp=fabs(b-x1);
		plik<<setw(8)<<x++<<"\t";
		plik<<setw(8)<<x1<<"\t";
		plik<<setw(8)<<f<<"\t";
		plik<<setw(8)<<fp<<"\t";
		plik<<setw(8)<<tmp<<endl;
		b=x1;
		if(tmp<eps)
			break;
	};
	plik.close();
	return b;
};
