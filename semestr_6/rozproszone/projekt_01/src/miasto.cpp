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
void Miasto::Dump(char* data)
{
//	char *data=new char[1024];
//	memset(data,0,1024);
	unsigned int i;
	sprintf(data,"%d ",itsDrogi.size());
	for(i=0;i<itsDrogi.size();i++)
	{
//		strcat(data,itsDrogi[i]);
		sprintf(data+strlen(data),"%d ",itsDrogi[i]);
	};
//	return data;
};
int Miasto::Load(char*& data)
{
	int i;
	int ile;
	int size;
	char a[16];
	size=sscanf(data,"%s",a);
	ile=atoi(a);
	size=strlen(a)+1;
	data+=size;
	for(i=0;i<ile;i++)
	{
		int tmp;
		sscanf(data,"%s",a);
		data+=strlen(a)+1;
		size+=strlen(a)+1;
		tmp=atoi(a);
		itsDrogi.push_back(tmp);
	};
	return size;
};
