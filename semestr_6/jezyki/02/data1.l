
%{
/* data1.l
   Program analizuje strumien wejsciowy 
   i wypisuje na wyjscie date w postaci rrrr-mm-dd */
%}

D	[1-9]
D0	[0-9]

%%

(0?{D}|[1-2]{D}|3[0-1])"."(0?{D}|1[0-2])"."[0-9]{4}	printf("%s\n",yytext); 

. 	|
\n	;




