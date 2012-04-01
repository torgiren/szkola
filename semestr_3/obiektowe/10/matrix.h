#ifndef __MATRIX__
#define __MATRIX__
#include "vector.h"
#include <iostream>
using namespace std;
///Klasa macierzy
class Matrix
{
	public:
		///deklaracja przyjazni
		friend ostream& operator<<(ostream& out,Matrix &co);
		Matrix(int X,int Y);
		Matrix();
		~Matrix();
		Vector& operator[](int num);
		Matrix operator+(Matrix& co);
		void operator=(Matrix co);
		int itsRows;
	private:
		Vector* itsVect;
};
#endif
