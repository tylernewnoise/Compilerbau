%define parse.error verbose
%define parse.trace

%code requires {
	#include <stdio.h>
	#include <stdlib.h>


	extern void yyerror(const char*);
	extern FILE* yyin;
}

%code {
	extern int yylex();
	extern int yylineno;
}

%union {
	char* string;
	double floatValue;
	int intValue;
}

%token AND           "&&"
%token OR            "||"
%token EQ            "=="
%token NEQ           "!="
%token LEQ           "<="
%token GEQ           ">="
%token LSS           "<"
%token GRT           ">"
%token KW_BOOLEAN    "bool"
%token KW_DO         "do"
%token KW_ELSE       "else"
%token KW_FLOAT      "float"
%token KW_FOR        "for"
%token KW_IF         "if"
%token KW_INT        "int"
%token KW_PRINTF     "printf"
%token KW_RETURN     "return"
%token KW_VOID       "void"
%token KW_WHILE      "while"
%token CONST_INT     "integer literal"
%token CONST_FLOAT   "float literal"
%token CONST_BOOLEAN "boolean literal"
%token CONST_STRING  "string literal"
%token ID            "identifier"

%nonassoc						 LOWER_THAN_ELSE
%nonassoc						 KW_ELSE

%%

program								: declassignment ';'program
											|	functiondefinition program
											| /*epsilon*/
											;
functiondefinition		: type id '(' parameterlist ')' '{' statementlist '}'
											|	type id '(' ')' '{' statementlist '}'
											;
parameterlist					:	type id parameterlist_s
											;
parameterlist_s				: ',' type id parameterlist_s
											| /*epsilon*/
											;
functioncall					: id '(' ')'
											| id '(' assignment assignment_s ')'
											;
assignment_s					: ',' assignment assignment_s
											| /*epsilon*/
											;
statementlist					: block statementlist
											|	/*epsilon*/
											;
block									: '{' statementlist '}'
											| statement
											;
statement							: ifstatement
											| forstatement
											| whilestatement
											| returnstatement ';'
											| dowhilestatement ';'
											| printf ';'
											| declassignment ';'
											| statassignment ';'
											| functioncall ';'
											;
statblock							: '{' statementlist '}'
											| statement
											;
ifstatement 	        : KW_IF '(' assignment ')' statblock 	%prec LOWER_THAN_ELSE
											;
											| KW_IF '(' assignment ')' statblock KW_ELSE statblock
											;
forstatement          : KW_FOR '(' statassignment ';' expr ';' statassignment ')' statblock
											|	KW_FOR '(' declassignment ';' expr ';' statassignment ')' statblock
											;
dowhilestatement      : KW_DO statblock KW_WHILE '(' assignment ')'
											;
whilestatement				: KW_WHILE '(' assignment ')' statblock
											;
returnstatement				: KW_RETURN assignment
											|	KW_RETURN
											;
printf								: KW_PRINTF '(' assignment ')'
											|	KW_PRINTF '(' CONST_STRING ')'
											;
declassignment        : type id
											| type id '=' assignment
											;
type 	                : KW_BOOLEAN
                    	| KW_FLOAT
											| KW_INT
											| KW_VOID
											;
statassignment 	      : id '=' assignment
											;
assignment 	          : id '=' assignment
											| expr
											;
expr 	                : simpexpr
											| simpexpr EQ simpexpr
											| simpexpr NEQ simpexpr
											| simpexpr LEQ simpexpr
											| simpexpr GEQ simpexpr
											| simpexpr LSS simpexpr
											| simpexpr GRT simpexpr
											;
simpexpr 	            : '-' term term_s
											|	term term_s
											;
term_s                : '+' term term_s
											| '-' term term_s
											| OR term term_s
                      | /*epsilon*/
											;
term 	                : factor factor_s
											;
factor_s              : '*' factor factor_s
											| '/' factor factor_s
											|	AND factor factor_s
											| /*epsilon*/
											;
factor 	              : CONST_INT
                      | CONST_FLOAT
                    	| CONST_BOOLEAN
                    	| functioncall
                    	| id
                    	| '(' assignment ')'
											;
id                    : ID
											;

%%

int main(int argc, char *argv[]) {
	if (argc != 2)
		yyin = stdin;
	else {
		yyin = fopen(argv[1], "r");
		if (yyin == 0)
		{
				fprintf(stderr, "Fehler: Konnte Datei %s nicht zum lesen oeffnen.\n", argv[1]);
				exit(1);
		}
	}
	//yydebug=1;
	return yyparse();
}

void yyerror(const char* msg) {
		fprintf(stderr, "Line %d: %s\n",yylineno, msg);
		exit(2);
}
