#include <stdio.h>
#include <stdlib.h>
#include "minako.h"

/* Prototypes */

void eat();
void isTokenAndEat(int token);
int isToken(int token);
void program();
void A();
void functiondefinition();
void type();
void statementlist();
void B();
void block();
void statement();
void ifstatement();
void returnstatement();
void printfstatement();
void statassignment();
void assignement();
void C();
void expr();
void simpexpr();
void D();
void E();
void term();
void F();
void H();
void factor();
void J();
void I();

/* Global variables */

int currentToken;
int nextToken;


int main(int argc, char *argv[]) {
    if (argc != 2)
        yyin = stdin;
    else
    {
        yyin = fopen(argv[1], "r");
        if (yyin == 0)
        {
            fprintf(stderr, "Fehler: Konnte Datei %s nicht zum lesen oeffnen.\n", argv[1]);
            exit(-1);
        }
    }

    // Init von currentToken, nextToken
    currentToken = yylex();
    nextToken = yylex();

    // Wir beginnen mit der Startregel der Grammatik
    program();

    // keine Fehler gefunden
    return 0;
}

void program(){
    A();
    isTokenAndEat(EOF);
}

void A(){
    if (currentToken == KW_BOOLEAN || currentToken == KW_FLOAT || currentToken == KW_INT || currentToken == KW_VOID) {
        functiondefinition();
        A();
    }
    else return; //epsilon
}

void functiondefinition(){
    type();
    isTokenAndEat(ID);
    isTokenAndEat('(');
    isTokenAndEat(')');
    isTokenAndEat('{');
    statementlist();
    isTokenAndEat('}');
}

void functioncall(){
    isTokenAndEat(ID);
    isTokenAndEat('(');
    isTokenAndEat(')');
}

void statementlist(){
    B();
}

void B(){
    if (currentToken == '{' || currentToken == KW_IF || currentToken == KW_RETURN ||
            currentToken == KW_PRINTF || currentToken == ID) {
        block();
        B();
    }
    else return; //epsilon
}

void block(){
    if (currentToken == '{') {
        isTokenAndEat('{');
        statementlist();
        isTokenAndEat('}');
    }
    else {
        statement();
    }
}

void statement(){
    switch (currentToken){
        case KW_IF: ifstatement(); break;
        case KW_RETURN: returnstatement(); isTokenAndEat(';'); break;
        case KW_PRINTF: printfstatement(); isTokenAndEat(';'); break;
        default:
            if (currentToken == ID && nextToken == '=') {
                statassignment();
                isTokenAndEat(';');
            }
            else {
                functioncall();
                isTokenAndEat(';');
            }
    }
}

void ifstatement(){
    isTokenAndEat(KW_IF);
    isTokenAndEat('(');
    assignement();
    isTokenAndEat(')');
    //block;
}

void returnstatement(){
    isTokenAndEat(KW_RETURN);
    C();
}

void C(){
    if (currentToken != ';') {
        assignement();
    }
    else return; //epsilon
}

void printfstatement(){
    isTokenAndEat(KW_PRINTF);
    isTokenAndEat('(');
    assignement();
    isTokenAndEat(')');
}

void type(){
    switch (currentToken){
        case KW_BOOLEAN: isTokenAndEat(KW_BOOLEAN); break;
        case KW_FLOAT: isTokenAndEat(KW_FLOAT); break;
        case KW_INT: isTokenAndEat(KW_INT); break;
        default: isTokenAndEat(KW_VOID);
    }
}

void statassignment(){
    isTokenAndEat(ID);
    isTokenAndEat('=');
    assignement();
}

void assignement(){
    if (currentToken == ID && nextToken == '=') {
        isTokenAndEat(ID);
        isTokenAndEat('=');
        assignement();
    }
    else {
        expr();
    }
}

void expr(){
    simpexpr();
    D();
}

void D(){
    if (currentToken == ')' || currentToken == ';') {
        return; //epsilon
    } else {
        E();
        simpexpr();
    }
}

void E(){
    switch (currentToken) {
        case EQ: isTokenAndEat(EQ); break;
        case NEQ: isTokenAndEat(NEQ); break;
        case LEQ: isTokenAndEat(LEQ); break;
        case GEQ: isTokenAndEat(GEQ); break;
        case LSS: isTokenAndEat(LSS); break;
        default: isTokenAndEat(GRT);
    }
}

void simpexpr(){
    F();
    term();
    H();
}

void F(){
    if (currentToken == '-'){
        isTokenAndEat('-');
    }
    else return; //epsilon
}

void G() {
    switch (currentToken){
        case '+': isTokenAndEat('+'); break;
        case '-': isTokenAndEat('-'); break;
        default: isTokenAndEat(OR);
    }
}

void H(){
    if (currentToken == '+' || currentToken == '-' || currentToken == OR){
        G();
        term();
        H();
    }
    else return; //epsilon
}

void term(){
    factor();
    J();
}

void J(){
    if (currentToken == '*' || currentToken == '/' || currentToken == AND){
        I();
        factor();
        J();
    }
    else return; //epsilon
}

void I(){
    switch (currentToken){
        case '*': isTokenAndEat('*'); break;
        case '/': isTokenAndEat('/'); break;
        default: isTokenAndEat(AND);
    }
}

void factor(){
    switch(currentToken){
        case CONST_INT: isTokenAndEat(CONST_INT); break;
        case CONST_FLOAT: isTokenAndEat(CONST_FLOAT); break;
        case CONST_BOOLEAN: isTokenAndEat(CONST_BOOLEAN); break;
        case '(': isTokenAndEat('('); assignement(); isTokenAndEat(')'); break;
        default:
            if (currentToken == ID && nextToken == '(') {
                functioncall();
            }
            else isTokenAndEat(ID);
    }
}

void eat() {
    currentToken = nextToken;
    nextToken = yylex();
}

void isTokenAndEat(int token) {
    if (isToken(token)){
        eat();
    }
    else {
        fprintf(stderr, "ERROR: Syntaxfehler in Zeile (%d)\n", yylineno);
        exit(-1);
    }
}

int isToken(int token) {
    if (token == currentToken) {
        return 1;
    }
    return 0;
}