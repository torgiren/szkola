#include "ctext.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
CText::CText(string path)
{
	ifstream plik(path.c_str());
	if(!plik) return;
	char tmp[1024];
	while(!plik.eof())
	{
		plik.getline(tmp,1024);
		itsText.push_back(tmp);
	};
}
CText CText::operator+(CText& elem)
{
	CText tmp;
	tmp.itsText.reserve(itsText.size()+elem.itsText.size());
	unsigned int x;
	for(x=0;x<itsText.size();x++)
	{
		tmp.itsText.push_back(itsText[x]);
	};
	for(x=0;x<elem.itsText.size();x++)
	{
		tmp.itsText.push_back(elem.itsText[x]);
	};
	return tmp;
};
void CText::WypiszN()
{
	unsigned int x;
	for(x=0;x<itsText.size();x++)
	{
		cout<<itsText[x]<<endl;
	};
};
void CText::WypiszW()
{
	int line,x;
	char tmp[1024];
	char *p;
	for(line=0;line<itsText.size();line++)
	{
		strcpy(tmp,itsText[line].c_str());
		p=strtok(tmp," ");
		if(p) 
			x=1;
		else
			x=0;
		while(strtok(NULL," "))
		{
			x++;
		};
		cout<<line<<"|\t"<<x<<"|\t"<<itsText[line]<<endl;
	};
};
