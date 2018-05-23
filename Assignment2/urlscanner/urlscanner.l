/* Options */

%option yylineno
%option noyywrap
%option nodefault

/* C - Code */

%{
#include "urlscanner.h"
%}

/* Constants */

WHITESPACE [ \t\n\r]

/* States */

%s ANKER
%s TEXT

%%

<TEXT>">"[^\<]*/\<          {yylval = yytext+1; BEGIN(INITIAL); return TOKEN_TEXT;}
<ANKER>href=\"[^\"]*/\"     {yylval = yytext+6; BEGIN(TEXT); return TOKEN_URL;}
<ANKER>">"                  {BEGIN(INITIAL);}
"<a"                        {BEGIN(ANKER);}
.|\n                        {}
<<EOF>>                     {return MYEOF;}

%%
