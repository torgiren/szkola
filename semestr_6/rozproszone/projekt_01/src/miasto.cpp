#include "miasto.h"
#include <stdio.h>
#include <string.h>
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
void Miasto::Load(char* data)
{
	
};
