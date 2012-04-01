%{
/* passwd.l
   Analiza zawartosci pliku passwd */
%}

%%

^ewa		printf("uzytkownik ewa ma konto w systemie\n");
:$		printf("uzytkownik nie ma zdefiniowanego shell-a\n");
.|\n		;
