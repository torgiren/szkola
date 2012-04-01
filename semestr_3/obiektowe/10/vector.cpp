#include "vector.h"
#include <iostream>
using namespace std;
Vector::Vector():
itsElements(0)
{
};
Vector::Vector(int size):
itsElements(0)
{
	SetSize(size);
};
void Vector::SetSize(int num)
{
	itsCols=num;
	itsElements=new int[num];
};
Vector::~Vector()
{
/*
	if(itsElements)
	{
		delete []itsElements;
		itsElements=0;
	};
*/
};
int& Vector::operator[](int num)
{
	if(num>itsCols) return itsElements[itsCols-1];
	if(num<0) return itsElements[0];
	return itsElements[num];
};
Vector Vector::operator+(Vector& co)
{
	if(this->itsCols!=co.itsCols)
	{
		Vector zero(0);
		return zero;
	};
	int x;
	Vector tmp(this->itsCols);
	for(x=0;x<this->itsCols;x++)
	{
		tmp[x]=(*this)[x]+co[x];
	};
	return tmp;
};
void Vector::operator=(Vector co)
{
	itsElements=new int[co.itsCols];
	itsCols=co.itsCols;
	int x;
	for(x=0;x<itsCols;x++)
	{
		(*this)[x]=co[x];
	};
	
};
ostream& operator<<(ostream& out,Vector& co)
{
	out<<"(";
	int x;
	for(x=0;x<co.itsCols;x++)
	{
		out<<co[x]<<",";
	};
	cout<<"\b)"<<endl;
	return out;
};
/*
Vector::Vector(Vector& co)
{
	itsElements=new int[co.itsCols];
	itsCols=co.itsCols;
	int x;
	for(x=0;x<itsCols;x++)
	{
		(*this)[x]=co[x];
	};
};
*/
