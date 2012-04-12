%%
[a-zA-Z ]	yylval=yytext[0]; return (T_CHAR);
.|\n	return(yytext[0]);
