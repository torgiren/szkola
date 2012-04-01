#include<iostream>
#include<cmath>

using namespace std;

/* Pozostawic bez zmian! */
class CPunkt {
protected:
	double mX;
	double mY;
public:
	CPunkt(double x, double y) : mX(x),mY(y) {}
	void print() {
		cout << "(" << mX << "," << mY << ") ";
	}
};


/* CPunktKolor ...
 ... */
/**
klasa CPunkKolor
dziedzicy z CPunkt
*/
class CPunktKolor :public CPunkt
{
	///deklaracja przyjaznni operatora dodawania
	friend CPunktKolor operator+(CPunktKolor& a,CPunktKolor& b);
	public:
		CPunktKolor(double x,double y,double kolor):
			CPunkt(x,y),itsKolor(kolor)
		{
		};
		///wypisaniu punktu na ekran
		void print()
		{
			cout<<"("<<mX<<","<<mY<<","<<itsKolor<<")"<<endl;
		};
	protected:
		double itsKolor;
};

CPunktKolor operator+(CPunktKolor& a,CPunktKolor& b)
{
	CPunktKolor tmp(0,0,0);
	tmp.mX=a.mX+b.mX;
	tmp.mY=a.mY+b.mY;
	tmp.itsKolor=(a.itsKolor+b.itsKolor)/2;
	if(tmp.itsKolor!=(int)tmp.itsKolor)
	{
		tmp.itsKolor=(int)tmp.itsKolor+1;
	};
	return tmp;
};

int main() {
 CPunktKolor p1(1.2,3.4,5),p2(1.0,1.0,2),w(0.0,0.0,0);

 p1.print();
 p2.print();
 w=p1+p2;
 w.print();
 return 0;
}

/*

(1.2,3.4,5)
(1,1,2)
(2.2,4.4,4)

*/

