#include "stack.h"
#include <stdlib.h>


int stackInit(intstack_t *stack) {
    stack = NULL;
    return 1;
}

void stackRelease(intstack_t *stack) {
    struct intstack_t *temp = post;

    if (previous == NULL)
        return;
    post = post->previous;
    free(temp);
}

void stackPush(intstack_t *stack, int i){

}

int stackTop(const intstack_t *stack){

    return 1;
}

int stackPop(intstack_t *stack){
    return 1;
}


int stackIsEmpty(const intstack_t *stack){
    return 1;
}

void stackPrint(const intstack_t *stack){

}
