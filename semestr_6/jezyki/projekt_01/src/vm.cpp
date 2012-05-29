/**
 * Wirtualna maszyna
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int main(int argc, char* argv[])
{
	if(argc<2)
	{
		fprintf(stderr,"Za mało parametrów.\nUżycie: %s <program>\n",argv[0]);
		exit(1);
	};
	ifstream plik(argv[1]);
//	FILE* plik;
//	plik=fopen(argv[1],"r");
	if(!plik)
	{
		fprintf(stderr,"Blad otwarcia pliku....\n");
		exit(2);
	};
	vector<string> prog;
	char line[255];
	while(!plik.eof())
	{
		plik.getline(line,255);
		prog.push_back(line);
	};
	int esp=0;
	int ax=0;
	int bx=0;
	int cx=0;
	int dx=0;
	while(esp<prog.size())
	{
		printf("ax=%d\nbx=%d\ncx=%d\ndx=%d\nesp=%d\n\n",ax,bx,cx,dx,esp);
		printf("%s\n",prog[esp].c_str());
		char tmp[255];
		memset(tmp,0,255);
		sscanf(prog[esp].c_str(),"%s",tmp);
		if(!strcmp(tmp,"mov"))
		{
			char a[16],b[16];
			sscanf(prog[esp].c_str(),"%s %s %s",tmp,a,b);
//			printf("mov %s : %s\n",a,b);
			int* dst=NULL;
			if(!strcmp(a,"ax"))
				dst=&ax;
			else if(!strcmp(a,"bx"))
				dst=&bx;
			else if(!strcmp(a,"cx"))
				dst=&cx;
			else if(!strcmp(a,"dx"))
				dst=&dx;
			else
			{
				fprintf(stderr,"Segmentation fault.\n%s\nUnknow destination %s\n",prog[esp].c_str(),a);
				exit(3);
			};
			int src=0;
			if(!strcmp(b,"ax"))
				src=ax;
			else if(!strcmp(b,"bx"))
				src=bx;
			else if(!strcmp(b,"cx"))
				src=cx;
			else if(!strcmp(b,"dx"))
				src=dx;
			else
				src=atoi(b);
			*dst=src;
		}
		else if(!strcmp(tmp,"inc"))
		{
			char a[16];
			sscanf(prog[esp].c_str(),"%s %s",tmp,a);
			if(!strcmp(a,"ax"))
				ax++;
			else if(!strcmp(a,"bx"))
				bx++;
			else if(!strcmp(a,"cx"))
				cx++;
			else if(!strcmp(a,"dx"))
				dx++;
			else
			{
				fprintf(stderr,"Segmentation fault.\n%s\nUnknow destination %s\n",prog[esp].c_str(),a);
				exit(3);
			};
		}
		else if(!strcmp(tmp,"dec"))
		{
			char a[16];
			sscanf(prog[esp].c_str(),"%s %s",tmp,a);
			if(!strcmp(a,"ax"))
				ax--;
			else if(!strcmp(a,"bx"))
				bx--;
			else if(!strcmp(a,"cx"))
				cx--;
			else if(!strcmp(a,"dx"))
				dx--;
			else
			{
				fprintf(stderr,"Segmentation fault.\n%s\nUnknow destination %s\n",prog[esp].c_str(),a);
				exit(3);
			};
		};
		++esp;
	};
	return 0;
};
