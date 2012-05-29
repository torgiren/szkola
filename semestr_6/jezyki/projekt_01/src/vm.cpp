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
int* findDst(char *reg);
int eip=0;
int ax=0;
int bx=0;
int cx=0;
int dx=0;
int zf=0;
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
	int step=0;
	while(eip<prog.size())
	{
		printf("\t\tstep=%d\tax=%d\tbx=%d\tcx=%d\tdx=%d\teip=%d\tzf=%d\n",step++,ax,bx,cx,dx,eip,zf);
		printf("%s\n",prog[eip].c_str());
		char tmp[255];
		memset(tmp,0,255);
		sscanf(prog[eip].c_str(),"%s",tmp);
		if(!strcmp(tmp,"mov"))
		{
			char a[16],b[16];
			sscanf(prog[eip].c_str(),"%s %s %s",tmp,a,b);
//			printf("mov %s : %s\n",a,b);
			int* dst=findDst(a);
			if(!dst)
			{
				fprintf(stderr,"Segmentation fault.\n%s\nUnknow destination %s\n",prog[eip].c_str(),a);
				exit(3);
			};
			int *src=findDst(b);
			if(src)
				*dst=*src;
			else
				*dst=atoi(b);
		}
		else if(!strcmp(tmp,"inc"))
		{
			char a[16];
			sscanf(prog[eip].c_str(),"%s %s",tmp,a);
			int* dst=findDst(a);
			if(dst)
			{
				(*dst)++;
				zf=!(*dst);
			}
			else
			{
				fprintf(stderr,"Segmentation fault.\n%s\nUnknow destination %s\n",prog[eip].c_str(),a);
				exit(3);
			};
		}
		else if(!strcmp(tmp,"dec"))
		{
			char a[16];
			sscanf(prog[eip].c_str(),"%s %s",tmp,a);
			int* dst=findDst(a);
			if(dst)
			{
				(*dst)--;
				zf=!(*dst);
			}
			else
			{
				fprintf(stderr,"Segmentation fault.\n%s\nUnknow destination %s\n",prog[eip].c_str(),a);
				exit(3);
			};
		}
		else if(!strcmp(tmp,"jz"))
		{
			char a[16];
			sscanf(prog[eip].c_str(),"%s %s",tmp,a);
			int adr=atoi(a);
			if(zf)
			{
				eip=adr;
//				printf("\tskok do %d=%d\n",adr,eip);
				continue;
			};

		}
		else if(!strcmp(tmp,"jnz"))
		{
			char a[16];
			sscanf(prog[eip].c_str(),"%s %s",tmp,a);
			int adr=atoi(a);
			if(!zf)
			{
				eip=adr;
//				printf("\tskok do %d=%d\n",adr,eip);
				continue;
			};

		}
		else if(!strcmp(tmp,"cmp"))
		{
			char a[16];
			char b[16];
			sscanf(prog[eip].c_str(),"%s %s %s",tmp,a,b);
			int *src=findDst(a);
			int *dst=findDst(b);
			int s,d;
			if(src)
				s=*src;
			else
				s=atoi(a);
			if(dst)
				d=*dst;
			else
				d=atoi(b);
			if(s==d)
				zf=1;
			else
				zf=0;
		};
		++eip;
	};
	return 0;
};
int* findDst(char *reg)
{
	int* dst=NULL;
	if(!strcmp(reg,"ax"))
		dst=&ax;
	else if(!strcmp(reg,"bx"))
		dst=&bx;
	else if(!strcmp(reg,"cx"))
		dst=&cx;
	else if(!strcmp(reg,"dx"))
		dst=&dx;
	return dst;
};
