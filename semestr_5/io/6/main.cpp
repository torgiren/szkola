#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include "dzialanie.h"
#include "dodaj.h"
#include "odejmij.h"
using namespace std;
bool isFloat(string input[])
{
	return 0;
};
int main()
{
	cout<<atof("123")<<endl;
	cout<<atof("123.13")<<endl;
	cout<<atof("1.2.3")<<endl;
	cout<<atof("123aa")<<endl;
	cout<<atof("aa23")<<endl;

	int opt;
	char input[255];
	float l1,l2;
	while(true)
	{
		cout<<"Podaj pierwsza liczbe: ";
		cin>>input;
		cout<<isFloat(input)<<endl;


	};
};
