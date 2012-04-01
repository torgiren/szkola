#include <iostream>
#include "ctext.h"
using namespace std;
int main()
{
	CText text("Makefile");
	CText aa("main.cpp");
	text.WypiszN();
	cout<<"&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	aa.WypiszN();
	
	CText cc=text+aa;
	cout<<"*************************"<<endl;
	cc.WypiszN();
	cout<<"*************************"<<endl;
	cc.WypiszW();
	return 0;
};
