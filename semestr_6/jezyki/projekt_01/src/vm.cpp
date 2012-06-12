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
//int findVal(char* val);
const char* retVar(int num);
void writeVar(int num,char* var);
void errorHeader(int eip);
template<class T>
void checkRange(int index,vector<T> vec);
int eip=0;
int ax=0;
int bx=0;
int cx=0;
int dx=0;
int zf=0;
//vector<int> vars;
vector<string> prog;
vector<int> stack;
bool debug=false;
int main(int argc, char* argv[])
{
	int args=argc;
	if(args>1)
		if(!strcmp(argv[1],"-g"))
		{
			args--;
			debug=true;
		};
	printf("%d\n",args);
	if(args<2)
	{
		fprintf(stderr,"Za mało parametrów.\nUżycie: %s <program>\n",argv[0]);
		exit(NOT_ENOUGH_PARAMS);
	};
	ifstream plik(argv[argc-1]);
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
	int step=0;
	int skipping_steps=0;
	bool quit=false;
	int exit_value=0;
	while((eip<prog.size())&&(!quit))
	{
//**********************************************************/
// Komunikacja z użytkownikiem...
//*********************************************************/
		char tmp[255];
		char tmp2[255];
		if(skipping_steps==0&&debug)
		{
			printf("%s\n",prog[eip].c_str());
			printf("$ ");
			size_t size;
			memset(tmp,0,255);
			fgets(line,255,stdin);
			sscanf(line,"%s",tmp);
//			scanf("%s %s",tmp,tmp2);
			if(!strcmp(tmp,"reg"))
			{
				printf("\t\tstep=%d\tax=%d\tbx=%d\tcx=%d\tdx=%d\teip=%d\tzf=%d\n",step,ax,bx,cx,dx,eip,zf);
				continue;
			}
			else if(!strcmp(tmp,"step"))
			{
				skipping_steps=1;
				int ile;
				if(strlen(line)!=strlen(tmp)+1)
				{
					sscanf(line,"%s %d",tmp,&ile);
					if(ile==0) ile=1;
					skipping_steps=ile;
				}
				printf("Skipping: %d\n",skipping_steps);
				continue;
			}
			else if(!strcmp(tmp,"stack"))
			{
				int i;
				for(i=stack.size()-1;i>=0;i--)
				{
					printf("%d:\t%d\n",i,stack[i]);
				};
				continue;
			}
			else
				continue;
		}
		--skipping_steps;
		++step;
//**********************************************************/
// Wykonywanie programu
//*********************************************************/
		memset(tmp,0,255);
		sscanf(prog[eip].c_str(),"%s",tmp);
		if(tmp[0]=='%') continue;
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
		else if(!strcmp(tmp,"add"))
		{
			char a[16];
			sscanf(prog[eip].c_str(),"%s %s",tmp,a);
			int* dst=findDst(a);
			if(dst)
			{
				ax+=*dst;
			}
			else
			{
				ax+=atoi(a);
			};
			if(!ax)
				zf=true;
		}
		else if(!strcmp(tmp,"sub"))
		{
			char a[16];
			sscanf(prog[eip].c_str(),"%s %s",tmp,a);
			int* dst=findDst(a);
			if(dst)
			{
				ax-=*dst;
			}
			else
			{
				ax-=atoi(a);
			};
			if(!ax)
				zf=true;
		}
		else if(!strcmp(tmp,"mul"))
		{
			char a[16];
			sscanf(prog[eip].c_str(),"%s %s",tmp,a);
			int* dst=findDst(a);
			if(dst)
			{
				ax*=*dst;
			}
			else
			{
				ax*=atoi(a);
			};
			if(!ax)
				zf=true;
		}
		else if(!strcmp(tmp,"div"))
		{
			char a[16];
			sscanf(prog[eip].c_str(),"%s %s",tmp,a);
			int* dst=findDst(a);
			if(dst)
			{
				ax/=*dst;
			}
			else
			{
				ax/=atoi(a);
			};
			if(!ax)
				zf=true;
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
		else if(!strcmp(tmp,"jmp"))
		{
			char a[16];
			sscanf(prog[eip].c_str(),"%s %s",tmp,a);
			int adr=atoi(a);
			eip=adr;
			continue;
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
//			vars.push_back(eip);
		}
		else if(!strcmp(tmp,"push"))
		{
			char a[16];
			sscanf(prog[eip].c_str(),"%s %s",tmp,a);
			int *src=findDst(a);
			int s;
			if(src)
				s=*src;
			else
				s=atoi(a);
			stack.push_back(s);
		}
		else if(!strcmp(tmp,"pop"))
		{
			char a[16];
			if(strlen(prog[eip].c_str())!=strlen(tmp))
			{
				sscanf(prog[eip].c_str(),"%s %s",tmp,a);
				int *src=findDst(a);
				if(!src)
				{
					errorHeader(eip);
					fprintf(stderr,"Unknow destination %s\n",a);
					exit(UNKNOW_DESTINATION);
				};
				*src=stack.back();
			}
			stack.pop_back();
		}
		else if(!strcmp(tmp,"call"))
		{
			char a[16];
			sscanf(prog[eip].c_str(),"%s %s",tmp,a);
			int b=atoi(a);
			stack.push_back(eip);
			eip=b;
			continue;
		}
		else if(!strcmp(tmp,"ret"))
		{
			eip=stack.back();
			stack.pop_back();
		}
		else if(!strcmp(tmp,"int"))
		{
			char nr[16];
			int przerw;
			sscanf(prog[eip].c_str(),"%s %s",tmp,nr);
			przerw=atoi(nr);
			char line[255];
			switch(przerw)
			{
				case 1:
					switch(ax)
					{
						case 1:
//							checkRange(bx,vars);
							printf("%s\n",retVar(bx));
							break;
						case 2:
//							checkRange(bx,vars);
//							scanf("%[^\n]",line);
							char line[255];
							fgets(line,255,stdin);
							line[strlen(line)-1]='\0';
							writeVar(bx,line);
							break;
						default:
							errorHeader(eip);
							fprintf(stderr,"Unknow operation %d in int %d\n",ax,przerw);
							exit(UNKNOW_OPERATION);
					};
					break;
				case 2:
					switch(ax)
					{
						case 1:
//							checkRange(bx,vars);
							float val;
							val=atof(retVar(bx));	
//							printf("odczytana wartosc: %f\n",val);
							cx=(int)val;
							dx=(val-cx)*100000.0f;
							break;
						case 2:
//							checkRange(bx,vars);
							sprintf(line,"%d.%d",cx,dx);
							writeVar(bx,line);
//							prog[vars[bx]]=line;
							break;
						case 3:
//							checkRange(bx,vars);
//							checkRange(cx,vars);
							char* str1;
							str1=(char*)retVar(bx);
							str1[strlen(str1)-1]='\0';
							sprintf(line,"%s%s",str1,retVar(cx));
							writeVar(bx,line);
							break;
						case 4:
							char *str2;
							str2=(char*)retVar(cx);
							writeVar(bx,str2);
							break;
						default:
							errorHeader(eip);
							fprintf(stderr,"Unknow operation %d in int %d\n",ax,przerw);
							exit(UNKNOW_OPERATION);
					}
					break;
				case 8:
					exit_value=ax;
					quit=true;
					break;
				default:
					errorHeader(eip);
					fprintf(stderr,"Unknow interuption %d\n",przerw);
					exit(UNKNOW_INTERUPTION);
			};
		};
		++eip;

	};
	free(line);
	return exit_value;
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
/*
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
*/
void errorHeader(int eip)
{
	fprintf(stderr,"Segmentation fault\n%s\n",prog[eip].c_str());
};
template<class T>
void checkRange(int index,vector<T> vec)
{
	if(index>=vec.size())
	{
		errorHeader(eip);
		fprintf(stderr,"Varible index out of range\n");
		exit(OUT_OF_RANGE);
	};
};
const char* retVar(int num)
{
	return prog[num].c_str()+3;
};
void writeVar(int num,char* var)
{
	char tmp[255];
	sprintf(tmp,"db %s",var);
	prog[num]=tmp;
};
