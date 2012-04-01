%{

/* identyfikatory.l
   Program rozpoznaje identyfikatory, liczby calkowite i liczby rzeczywiste 
   oraz wypisuje na wyjscie informacje, w ktorej linii pliku wejsciowego sie znajduje */

int linia; 
%}

DIGIT    [0-9]
ID       [a-zA-Z][a-zA-Z0-9]*
NUMBER   {DIGIT}+
REAL     {NUMBER}\.{NUMBER}
%%

{ID}			printf("Identyfikator %s w linii %d\n", yytext, linia);
{NUMBER}		printf("Liczbe calkowita %s w linii %d\n", yytext, linia);
{REAL}			printf("Liczba rzeczywista  %s w linii %d\n", yytext, linia);

\n			linia++; 
.  			;

%%

main () {
	linia=1;
	yylex(); 
	printf("---> Przeczytano %d linii\n", linia);
	return 0;
}
