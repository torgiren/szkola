%{
#define YYSTYPE char
%}
%token T_CHAR
%%
input	:
	| input '\n' { YYACCEPT;}
	| input znaki '\n'
	;
znaki	:	znaki T_CHAR { printf("Znaleziono: %c\n",$2);}
	| T_CHAR	{ printf("Znaloziono: %c\n", $1);}
	;
%%
#include "lex.yy.c"
int main()
{
	yyparse();
	return 0;
};
int yyerror(char* s)
{
	printf("blad: %s\n",s);
	return -1;
};

