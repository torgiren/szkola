#include "matrix.h"
#include <iostream>
using namespace std;
ostream& operator<<(ostream& out,Matrix &co)
{
	int x,y;
	for(x=0;x<co.itsRows;x++)
	{
		out<<"|";
		for(y=0;y<co[x].itsCols;y++)
		{
			out<<co[x][y]<<" ";
		};
		out<<"\b|"<<endl;
	};
	return out;
};
Matrix::Matrix()
{
	itsRows=0;
};
Matrix::~Matrix()
{
//	delete []itsVect;
};
Matrix::Matrix(int X,int Y)
{
	itsVect=new Vector[Y];	
	int x;
	for(x=0;x<Y;x++)
	{
		itsVect[x].SetSize(X);
	};
	itsRows=Y;
};
Vector& Matrix::operator[](int num)
{
	if(num>itsRows) return itsVect[itsRows-1];
	if(num<0) return itsVect[0];
	return itsVect[num];
};
Matrix Matrix::operator+(Matrix &co)
{
	if(this->itsRows!=co.itsRows)
	{
		Matrix zero(0,0);
		return zero;
	};
	int x;
	Matrix tmp((*this)[0].itsCols,this->itsRows);
	for(x=0;x<this->itsRows;x++)
	{
		tmp[x]=(*this)[x]+co[x];
	};
	return tmp;
};
void Matrix::operator=(Matrix co)
{
	itsVect=new Vector[co.itsRows];
	itsRows=co.itsRows;
	int x;
	for(x=0;x<itsRows;x++)
	{
		(*this)[x]=co[x];
	};
	
};
