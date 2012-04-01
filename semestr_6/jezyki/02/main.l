%{
#include <math.h>
%}

DIGIT	[0-]
ID	[a-z][a-z0-9]*

%%

{DIGIT}+ {
		printf("DIGIT: %s -> %d\n",yytext,atoi(yytext));
	}
{DIGIT}+"."{DIGIT}* {
		printf("Float: %s -> %d\n",yytext,atoi(yytext));
	}
if|then|begin|end|procedure|function 	{
		printf("keyword: %s\n",yytext);
	}
{ID} {
		printf("identifier %s\n",yytext);
	}
"+"|"-"|"*"|"/" {
		printf("operator; %s\n",yytext);
	}
"{"[^}\n]*"}" 	/* comment	*/
[ \t\n]+ 	/* spaces*/
. 	{
	printf("Unknow command\n");
	}

%%

int main( int argc, char* argv[])
{
	yylex();
};
