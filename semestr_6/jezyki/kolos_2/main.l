%{
%}
NUM [0-9]+

%%

.* {yylval=yytext; return CHAR;}
[ \t]+

"+" {yylval="+"; return PLUS;}
"-" {return MINUS;}
"*" {return RAZY;}
"/" {return DZIEL;}



%%
