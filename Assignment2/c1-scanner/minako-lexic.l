%option yylineno
%option noyywrap

%{

#include "minako.h"
yystype yylval;

%}

/* Constants */

WHITESPACE [ \t\n\r]
INTEGER [[:digit:]]+
FLOAT [[:digit:]]+
ALNUM [[:alnum:]]

/* States */

%x COMMENT_FIELD
%x COMMENT_LINE
%s INT

%%

<COMMENT_FIELD>.|"\n"   {}
<COMMENT_FIELD>"*/"     {BEGIN(INITIAL);}
<COMMENT_LINE>.         {}
<COMMENT_LINE>"\n"      {BEGIN(INITIAL);}
<INT>{INTEGER}          {yylval.intValue = atoi(yytext); return CONST_INT;}

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
int             {BEGIN(INT); return KW_INT;}
printf          {return KW_PRINTF;}
return          {return KW_RETURN;}
void            {return KW_VOID;}
while           {return KW_WHILE;}
"const float"   {return CONST_FLOAT;}
"const bool"    {return CONST_BOOLEAN;}
"const string"  {return CONST_STRING;}
{ALNUM}*        {yylval.string = yytext; return ID;}
[(),\{\}=\+-]   {return (char)*yytext;}
;               {BEGIN(INITIAL); return (char)*yytext;}
{WHITESPACE}    {}



%%

int main() {
int token;
while ((token = yylex())) {
printf("Line: %3d\t", yylineno);
switch (token)
{
case ID:
printf("ID:     %s\n", yylval.string);
break;

case CONST_BOOLEAN:
printf("BOOL:   %s\n", yylval.intValue ? "true" : "false");
break;

case CONST_INT:
printf("INT:    %d\n", yylval.intValue);
break;

case CONST_FLOAT:
printf("FLOAT:  %g\n", yylval.floatValue);
break;

case CONST_STRING:
printf("STRING: %s\n", yylval.string);
break;

default:
if (token <= 255)
printf("Token: '%c'\n", token);
else
printf("Token: %d\n", token);
}
}
return 0;
}
