#include "syntree.h"
#include <stdlib.h>
#include <stdio.h>

struct nodes_list {
    syntree_nid *element;
    struct nodes_list *next;
};

extern int syntreeInit(syntree_t *syntree) {
    if (!syntree) {
        return 1;
    }
    return 0;
}

extern syntree_nid syntreeNodeNumber(syntree_t *syntree, int number) {
    syntree_nid *new_value_node = malloc(sizeof(syntree_nid));
    struct nodes_list *new_nodes_list = malloc(sizeof(struct nodes_list));
    if (!new_value_node || !new_nodes_list) {
        fprintf(stderr, "Error: out of Memory!\n");
        exit(EXIT_FAILURE);
    }
    new_value_node->content.value = number;
    new_nodes_list->element = new_value_node;
    new_nodes_list->next = syntree->next;
    syntree->next = new_nodes_list;
    return *new_value_node;
}


/*
extern void syntreeRelease(syntree_t *syntree) {
}

extern syntree_nid syntreeNodeTag(syntree_t *syntree, syntree_nid id) {
}

extern syntree_nid syntreeNodePair(syntree_t *syntree, syntree_nid id1, syntree_nid id2) {
}

extern syntree_nid syntreeNodeAppend(syntree_t *syntree, syntree_nid list, syntree_nid elem) {
}

extern void syntreePrint(const syntree_t *self, syntree_nid root) {
}
*/

