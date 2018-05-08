#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

extern int stackInit(intstack_t *stack) {
    stack->current_element = NULL;
    return 0;
}

extern void stackRelease(intstack_t *stack) {
    while (stack->current_element != NULL) {
        struct node *tmp;
        tmp = stack->current_element;
        stack->current_element = tmp->previous_element;
        free(tmp);
    }
}

extern void stackPush(intstack_t *stack, int i) {
    struct node *new_element = malloc(sizeof(struct node));
    if (new_element == NULL) {
        fprintf(stderr, "Out of Memory!\n");
        stackRelease(stack);
        exit(EXIT_FAILURE);
    }
    new_element->value = i;
    new_element->previous_element = stack->current_element;
    stack->current_element = new_element;
}

extern int stackTop(const intstack_t *stack) {
    return stack->current_element->value;
}

extern int stackPop(intstack_t *stack) {
    if (stack->current_element == NULL) {
        fprintf(stderr, "No more elements on the stack!\n");
        stackRelease(stack);
        exit(EXIT_FAILURE);
    }
    struct node *tmp;
    int ret = stack->current_element->value;
    tmp = stack->current_element;
    stack->current_element = tmp->previous_element;
    free(tmp);
    return ret;
}

extern int stackIsEmpty(const intstack_t *stack) {
    if (stack->current_element == NULL)
        return 1;
    else
        return 0;
}

extern void stackPrint(const intstack_t *stack) {
    if (stackIsEmpty(stack)){
        printf("Stack is empty.\n");
        return;
    }
    struct node *tmp;
    tmp = stack->current_element;
    while (tmp != NULL) {
        printf("%i \n", tmp->value);
        tmp = tmp->previous_element;
    }
}
