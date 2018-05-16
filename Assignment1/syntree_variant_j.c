#include "syntree_variant_j.h"
#include <stdio.h>
#include <stdlib.h>

void addToList(syntree_t *self, syntree_nid *nid) {
    struct linked_list *new_element = malloc(sizeof(struct linked_list));
    if (!new_element) {
        fprintf(stderr, "Error: out of memory!\n");
        syntreeRelease(self);
        exit(EXIT_FAILURE);
    }
    new_element->ptr_value = nid;
    new_element->next = NULL;

    if (!self->root) {
        self->root = new_element;
    } else {
        struct linked_list *element = self->root;
        while (element->next != NULL) {
            element = element->next;
        };
        element->next = new_element;
    }
}

int syntreeInit(syntree_t *self) {
    if (!self)
        return 1;
    self->root = NULL;
    return 0;
}

void syntreeRelease(syntree_t *self) {
    struct linked_list *next_element;
    struct linked_list *element = self->root;
    while (element) {
        next_element = element->next;
        free(element->ptr_value);
        free(element);
        element = next_element;
    }
}

syntree_nid syntreeNodeNumber(syntree_t *self, int number) {
    syntree_nid *child = malloc(sizeof(syntree_nid));
    if (!child) {
        fprintf(stderr, "Error: out of memory!\n");
        syntreeRelease(self);
        exit(EXIT_FAILURE);
    }
    addToList(self, child);
    child->value = number;
    child->self_ptr = child;
    child->next = NULL;
    child->capsuled = NULL;
    return *child;
}

syntree_nid syntreeNodeTag(syntree_t *self, syntree_nid id) {
    syntree_nid *parent = malloc(sizeof(syntree_nid));
    if (!parent) {
        fprintf(stderr, "Error: out of memory!\n");
        syntreeRelease(self);
        exit(EXIT_FAILURE);
    }
    addToList(self, parent);
    parent->self_ptr = parent;
    parent->capsuled = id.self_ptr;
    parent->next = NULL;
    return *parent;
}

syntree_nid syntreeNodePair(syntree_t *self, syntree_nid id1, syntree_nid id2) {
    syntree_nid *parent = malloc(sizeof(syntree_nid));
    if (!parent) {
        fprintf(stderr, "Error: out of memory!\n");
        syntreeRelease(self);
        exit(EXIT_FAILURE);
    }
    addToList(self, parent);
    parent->self_ptr = parent;
    parent->capsuled = id1.self_ptr;
    parent->next = NULL;
    (id1.self_ptr)->next = id2.self_ptr;
    (id2.self_ptr)->next = NULL;
    return *parent;
}

syntree_nid syntreeNodeAppend(syntree_t *self, syntree_nid list, syntree_nid elem) {
    if (!list.capsuled) {
        fprintf(stderr, "Error: you're trying to append to a non-list node!\n");
        syntreeRelease(self);
        exit(EXIT_FAILURE);
    }
    syntree_nid *tmp = (list.self_ptr)->capsuled;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = elem.self_ptr;
    return list;
}

syntree_nid syntreeNodePrepend(syntree_t *self, syntree_nid elem, syntree_nid list) {
    if (!list.capsuled) {
        fprintf(stderr, "Error: you're trying to prepend to a non-list node!\n");
        syntreeRelease(self);
        exit(EXIT_FAILURE);
    }
    (elem.self_ptr)->next = (list.self_ptr)->capsuled;
    (list.self_ptr)->capsuled = elem.self_ptr;
    return list;
}


void syntreePrint(const syntree_t *self, syntree_nid root) {
    if (root.capsuled) {
        printf("{");
        syntreePrint(self, *root.capsuled);
        printf("}");
    } else {
        printf("(%i)", root.value);
    }
    if (root.next) {
        syntreePrint(self, *root.next);
    }
}