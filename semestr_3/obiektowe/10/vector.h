#ifndef __VECTOR__
#define __VECTOR__
#include <iostream>
using namespace std;
///Klasa wektor
class Vector
{
	public:
		///Deklaracja przyja≈ni
		friend ostream& operator<<(ostream& out,Vector &co);
		Vector();
		///Deklaracja konstruktora alkujacego wektor
		Vector(int size);
		~Vector();
		int& operator[](int);
		Vector operator+(Vector& co);
		void operator=(Vector co);
		int itsCols;
		///Alokuje pamiec na wektor
		void SetSize(int num);
	private:
		int *itsElements;
};
#endif
