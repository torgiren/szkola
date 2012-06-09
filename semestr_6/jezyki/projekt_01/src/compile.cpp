#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"
using namespace std;
vector<string> prog;
int main(int argc, char* argv[])
{
	if(argc<2)
	{
		fprintf(stderr,"Za mało parametrów.\nUżycie: %s <program>\n",argv[0]);
		exit(NOT_ENOUGH_PARAMS);
	};
	ifstream plik(argv[1]);
//	FILE* plik;
//	plik=fopen(argv[1],"r");
	if(!plik)
	{
		fprintf(stderr,"Blad otwarcia pliku....\n");
		exit(FILE_OPEN_ERROR);
	};
	char *line;
	line=(char*)malloc(sizeof(char*)*255);
	while(!plik.eof())
	{
		plik.getline(line,255);
		prog.push_back(line);
	};
	int i;
	vector<string>::iterator iter;
	for(iter=prog.begin();iter!=prog.end();iter++)
	{
		printf("%s\n",(*iter).c_str());
		char tmp[255];
		sscanf((*iter).c_str(),"%s",tmp);
		if(!strcmp(tmp,"string"))
		{
			
		};
	};
	return 0;
};
