%{
%}

%%

lex	printf("flex");

flex printf("proba");

%%

int main()
{
	printf("Zmiana lex na flex: \n");
	yylex();
	return 0;
}
