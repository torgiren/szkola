#include <iostream>
using namespace std;

class Zespolona
{
public:
	Zespolona();
	Zespolona(int Re,int Im);
	void przypisz(const Zespolona &liczba);
	void dodaj(const Zespolona &liczba);
	void odejmij(const Zespolona &liczba);
	void pomnoz(const Zespolona &liczba);
	void podziel(const Zespolona &liczba);
	void print();
private:
	float itsRe;
	float itsIm;
};
