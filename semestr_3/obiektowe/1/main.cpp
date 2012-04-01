/// \file main.cpp
/// \brief a to jest proba
/// \author Fabrykowski
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "drugi.h"
#include "trzeci.h"
using namespace std;
/**
*funkcja dodaje 2 liczny.
@param a pierwsza liczba
@param b druga liczba
@return suma liczb
@todo do zrobienia
*/
int dodaj(int a,int b);
/// funkcja main
int main()
{
	cout<<"Hello World"<<endl;
	cout<<"A 2+2 to "<<dodaj(2,2)<<endl;
	drugi();
	trzeci();
	int x,y,z;
	x=2;
	y=3;
	z=x/y;
	cout<<x<<" "<<y<<" "<<z<<endl;
	int *a=(int*)malloc(20);
	return 0;
};
int dodaj(int a,int b)
{
	return a+b;
};
