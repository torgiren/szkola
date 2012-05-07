%{
#include<stdio.h>
#include <string.h>
	%}
%token CHAR NUM C
%token PLUS MINUS RAZY DZIEL
%nonassoc PLUS MINUS RAZY DZIEL
%%
input:	
		|input exp {
				char stos[255];
				memset(stos,0,255);
				int poz=0;
				char *in=$2;
				int i;
				for(i=0;i<strlen($2);i++)
			{
				if(in[0]=='+'||in[0]=='-'||in[0]=='*'||in[0]=='/'||in[0]=='('||in[0]=='^')
				{
					stos[poz++]=in[0];
				}
				else if(in[0]==')')
				{
					while(stos[poz-1]!='(')
					{
						printf("%c",stos[--poz]);
					};	
					poz--;
				}
				else
				{
					printf("%c",in[0]);
				};
				in++;
			}
				for(i=poz-1;i>=0;i--)
				{
					printf("%c",stos[i]);
				};
			}

				
		;
exp:
		CHAR

/*
		| CHAR RAZY CHAR {
							char *znak,*znak2;
							znak=strtok((char*)$1,"*");
							znak2=strtok(NULL,"*");
							printf("%s %s *",znak,znak2);}
		| exp RAZY CHAR { 
							char *znak,*znak2;
							znak=strtok((char*)$1,"*");
							znak2=strtok(NULL,"*");
							printf("%s %s *","",$3);}
		| CHAR PLUS CHAR {
							char *znak,*znak2;
							znak=strtok((char*)$1,"+");
							znak2=strtok(NULL,"+");
							printf("%s %s +",znak,znak2);}
		| exp PLUS CHAR  {
							char *znak,*znak2;
							znak=strtok((char*)$1,"+");
							znak2=strtok(NULL,"+");
							printf("%s %s +","",$3);}
		| CHAR MINUS CHAR {
							char *znak,*znak2;
							znak=strtok((char*)$1,"-");
							znak2=strtok(NULL,"-");
							printf("%s%s-",znak,znak2);}
		| CHAR
*/
		;
%%
#include "lex.yy.c"
int main()
{
	yyparse();
};
int yyerror(char *s) {
	   printf("%s-->%d\n", s, yylineno);
}

