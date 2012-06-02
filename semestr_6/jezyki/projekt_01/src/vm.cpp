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
#include "errors.h"
using namespace std;
int* findDst(char *reg);
int findVal(char* val);
void errorHeader(int eip);
int eip=0;
int ax=0;
int bx=0;
int cx=0;
int dx=0;
int zf=0;
vector<int> vars;
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
				errorHeader(eip);
				fprintf(stderr,"Unknow destination %s\n",a);
				exit(UNKNOW_DESTINATION);
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
				errorHeader(eip);
				fprintf(stderr,"Unknow destination %s\n",a);
				exit(UNKNOW_DESTINATION);
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
				errorHeader(eip);
				fprintf(stderr,"Unknow destination %s\n",a);
				exit(UNKNOW_DESTINATION);
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
		}
		else if(!strcmp(tmp,"db"))
		{
			vars.push_back(eip);
		}
		else if(!strcmp(tmp,"int"))
		{
			char nr[16];
			int przerw;
			sscanf(prog[eip].c_str(),"%s %s",tmp,nr);
			przerw=atoi(nr);
			switch(przerw)
			{
				case 1:
					switch(ax)
					{
						case 1:
							if(bx>=vars.size())
							{
								errorHeader(eip);
								fprintf(stderr,"Varible index out of range\n",prog[eip].c_str());
								exit(OUT_OF_RANGE);
								break;
							};
							printf("%s\n",prog[vars[bx]].c_str()+3);
						break;
						case 2:
							if(bx>=vars.size())
							{
								errorHeader(eip);
								fprintf(stderr,"Varible index out of range\n",prog[eip].c_str());
								exit(OUT_OF_RANGE);
							};
							char line[255];
							scanf("%[^\n]",line);
							char result[255];
							strcpy(result,"db ");
							strcat(result,line);
							prog[vars[bx]]=result;
							break;
						default:
							errorHeader(eip);
							fprintf(stderr,"Unknow operation %d in int %d\n",ax,przerw);
							exit(UNKNOW_OPERATION);
					};
					break;
				default:
					errorHeader(eip);
					fprintf(stderr,"Unknow interuption %d\n",przerw);
					exit(UNKNOW_INTERUPTION);
			};
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
int findVal(char* val)
{
	if(!strcmp(val,"[ax]"))
		return vars[ax];
	else if(!strcmp(val,"[bx]"))
		return vars[bx];
	else if(!strcmp(val,"[cx]"))
		return vars[cx];
	else if(!strcmp(val,"[dx]"))
		return vars[dx];
};
void errorHeader(int eip)
{
	fprintf(stderr,"Segmentation fault\n%s\n",prog[eip].c_str());
};
