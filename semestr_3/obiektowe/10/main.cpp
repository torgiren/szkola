#include <iostream>
#include "vector.h"
#include "matrix.h"
///Funkcja main
///Wiecej dokumentacji zrobic sie nie da...
int main()
{
	Vector a(2),b(2),c(2);
	a[0]=1; a[1]=2;
	b[0]=2; b[1]=3;
	c=a+b;
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;

	Matrix d(2,2),e(2,2),f(2,2);
	d[0][0]=1; d[0][1]=2; d[1][0]=3; d[1][1]=3;
	e[0][0]=3; e[0][1]=5; e[1][0]=2; e[1][1]=1;
	
	cout<<d<<endl;
	cout<<e<<endl;

	f=d+e;
	cout<<f<<endl;

};
