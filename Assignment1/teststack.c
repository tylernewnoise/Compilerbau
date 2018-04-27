#include <stdio.h>
#include "stack.h"

int main() {
    intstack_t stack;

    stackInit(&stack);

    if (stackIsEmpty(&stack))
        printf("STACK IS EMPTY\n");

    stackPush(&stack, 1);
    printf("%i ist das letzte Element\n", stackTop(&stack));
    stackPush(&stack, 2);
    printf("%i ist das letzte Element\n", stackTop(&stack));
    stackPush(&stack, 3);
    printf("%i ist das letzte Element\n", stackTop(&stack));

    stackPrint(&stack);
    printf("Letztes Element %i gepoppt\n", stackPop(&stack));
    printf("%i ist das letzte Element\n", stackTop(&stack));

/*    while (!stackIsEmpty(&stack))
        printf("%i\n", stackPop(&stack));

    stackPop(&stack);*/

    stackPrint(&stack);
    stackRelease(&stack);
    stackRelease(&stack);
    stackPrint(&stack);
    return 0;
}


/* Erwartete Ausgabe:
3
2
1
<<Fehlermeldung, da intstack_t leer>>
*/
