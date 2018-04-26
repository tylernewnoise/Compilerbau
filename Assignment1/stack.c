#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int stackInit(intstack_t *stack) {
    intstack_t *tmp = malloc(sizeof(intstack_t));
    if (tmp == NULL) {
        fprintf(stderr, "Out of Memory!");
        return 1;
    }
    tmp->previous_element = NULL;
    tmp->value = 666; //TODO remove
    *stack = *tmp;
    return 0;
}

void stackRelease(intstack_t *stack) {

}

void stackPush(intstack_t *stack, int i) {
    intstack_t *tmp = malloc(sizeof(intstack_t));
    if (tmp == NULL) {
        fprintf(stderr, "Out of Memory!");
        //TODO free all Memory
        exit(0);
    }
    tmp->value = i;
    tmp->previous_element = stack;
    *stack = *tmp;
}

int stackTop(const intstack_t *stack) {
    return stack->value;
}

int stackPop(intstack_t *stack) {
    if (stack->previous_element == NULL) {
        fprintf(stderr, "No more elements on the stack!");
        //TODO free all Memory
        exit(0);
    }

    intstack_t *tmp = malloc(sizeof(intstack_t));
    if (tmp == NULL) {
        fprintf(stderr, "Out of Memory!");
        exit(0);
    }
    //int ret = stack->value;
    *tmp = *stack;
    int ret = tmp->value;
    // ....
    free(tmp);
    return ret;
}

int stackIsEmpty(const intstack_t *stack) {
    if (stack->previous_element == NULL)
        return 1;
    else
        return 0;
}

void stackPrint(const intstack_t *stack) {

}
