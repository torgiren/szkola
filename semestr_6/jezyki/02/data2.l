
%{
/* data2.l
   Program analizuje strumien wejsciowy 
   i wypisuje na wyjscie date w postaci rrrr-mm-dd */


%}

C 	[0-9]


%%

{C}{2}"."{C}{2}"."{C}{4}	printf("%s\n",yytext);

.	 			|
\n				;

