/* Options */

%option yylineno
%option noyywrap
%option nodefault

/* C - Code */

%{

#include "minako.h"
yystype yylval;

%}

/* Constants */

WHITESPACE [ \t\n\r]
INTEGER [[:digit:]]+
FLOAT {INTEGER}"."{INTEGER}
ALNUM [[:alnum:]]

/* States */

%x COMMENT_FIELD
%x COMMENT_LINE
%x STRING

%%

<COMMENT_FIELD>.|"\n"   {}
<COMMENT_FIELD>"*/"     {BEGIN(INITIAL);}
<COMMENT_LINE>.         {}
<COMMENT_LINE>"\n"      {BEGIN(INITIAL);}
<STRING>[^\"]*          {yylval.string = yytext; return CONST_STRING;}
<STRING>\"              {BEGIN(INITIAL);}

"/*"            {BEGIN(COMMENT_FIELD);}
"//"            {BEGIN(COMMENT_LINE);}
"&&"            {return AND;}
"||"            {return OR;}
"=="            {return EQ;}
"!="            {return NEQ;}
"<="            {return LEQ;}
">="            {return GEQ;}
"<"             {return LSS;}
">"             {return GRT;}
bool            {return KW_BOOLEAN;}
do              {return KW_DO;}
else            {return KW_ELSE;}
float           {return KW_FLOAT;}
for             {return KW_FOR;}
if              {return KW_IF;}
int             {return KW_INT;}
printf          {return KW_PRINTF;}
return          {return KW_RETURN;}
void            {return KW_VOID;}
while           {return KW_WHILE;}
true            {yylval.intValue = 1; return CONST_BOOLEAN;}
false           {yylval.intValue = 0; return CONST_BOOLEAN;}
\"              {BEGIN(STRING);}
{INTEGER}       {yylval.intValue = atoi(yytext); return CONST_INT;}
{FLOAT}         {yylval.floatValue = atof(yytext); return CONST_FLOAT;}
{ALNUM}*        {yylval.string = yytext; return ID;}
[(),\{\}=\+-;]  {return (char)*yytext;}
{WHITESPACE}    {}
.               {printf("Error: '%c' is not part of the language C1\n",*yytext); exit(1);}

%%
