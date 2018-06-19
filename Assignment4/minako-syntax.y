%define parse.error verbose
%define parse.trace

%code requires {
	#include <stdio.h>

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

%%

program								: program_s
											;
program_s							: program_c program_s
											| /*epsilon*/
											;
program_c							: functiondefinition
											| declassignment ';'
											;
functiondefinition		: type id '(' parameterlist_p ')' '{' statementlist '}'
											;
parameterlist_p				: parameterlist
											| /*epsilon*/
											;
parameterlist					:	type id parameterlist_s
											;
parameterlist_s				: ',' type id parameterlist_s
											| /*epsilon*/
											;
functioncall					: id '(' functioncall_s ')'
											;
functioncall_s				: functioncall_c
											| /*epsilon*/
											;
functioncall_c				: assignment assignment_s
											;
assignment_s					: ',' assignment assignment_s
											| /*epsilon*/
											;
statementlist					: statementlist_s
											;
statementlist_s				: block statementlist_s
											| /*epsilon*/
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
ifstatement 	        : KW_IF '(' assignment ')' statblock statblock_p
											;
statblock_p           : KW_ELSE statblock
											| /*epsilon*/
											;
forstatement          : KW_FOR '(' forstatement_o ';' expr ';' statassignment ')' statblock
											;
forstatement_o				: statassignment
                      | declassignment
											;
dowhilestatement      : KW_DO statblock KW_WHILE '(' assignment ')'
											;
whilestatement				: KW_WHILE '(' assignment ')' statblock
											;
returnstatement				: KW_RETURN returnstatement_p
											;
returnstatement_p			: assignment
											| /*epsilon*/
											;
printf								: KW_PRINTF '(' printf_o ')'
											;
printf_o              : assignment
                      | CONST_STRING
											;
declassignment        : type id declassignment_p
											;
declassignment_p      : '=' assignment
											| /*epsilon*/
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
expr 	                : simpexpr simpexpr_p
											;
simpexpr_p            : simpexpr_o
											| /*epsilon*/
											;
simpexpr_o            : EQ simpexpr
                      | NEQ simpexpr
                      | LEQ simpexpr
                      | GEQ simpexpr
                      | LSS simpexpr
                      | GRT simpexpr
											;
simpexpr 	            : term_o term_s
											;
term_o                : '-' term
                      | term
											;
term_s                : term_o2 term_s
                      | /*epsilon*/
											;
term_o2               : '+' term
                      | '-' term
                      | OR term
											;
term 	                : factor factor_s
											;
factor_s              : factor_o factor_s
											| /*epsilon*/
											;
factor_o              : '*' factor
                      | '/' factor
                      | AND factor
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

int main() {
	yydebug=1;
	return yyparse();
}

void yyerror(const char* msg) {
		fprintf(stderr, "%s\n",msg);
}
