#include "miasto.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Miasto::AddRoad(int num)
{
	itsDrogi.push_back(num);
};
std::vector<int>* Miasto::RetDrogi()
{
	return &itsDrogi;
};
char* Miasto::Dump()
{
	char *data=new char[1024];
	memset(data,0,1024);
	unsigned int i;
	sprintf(data,"%d ",itsDrogi.size());
	for(i=0;i<itsDrogi.size();i++)
	{
		sprintf(data,"%s %d ",data,itsDrogi[i]);
	};
	return data;
};
void Miasto::Load(char*& data)
{
	int i;
	int ile;
	int size;
	char a[16];
	size=sscanf(data,"%s",a);
	ile=atoi(a);
	data+=strlen(a)+2;
	for(i=0;i<ile;i++)
	{
		int tmp;
		size=sscanf(data,"%s",a);
		data+=strlen(a)+2;
		tmp=atoi(a);
		itsDrogi.push_back(tmp);
	};
};
