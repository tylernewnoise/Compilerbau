#include "syntree.h"
#include <stdlib.h>
#include <stdio.h>

// Liste für die Knoten. Erstmal nur single-linked.
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
    // Neuen Knoten erschaffen.
    syntree_nid *new_value_node = malloc(sizeof(syntree_nid));
    // Neue Liste erschaffen.
    struct nodes_list *new_nodes_list = malloc(sizeof(struct nodes_list));
    if (!new_value_node || !new_nodes_list) {
        fprintf(stderr, "Error: out of Memory!\n");
        exit(EXIT_FAILURE);
    }
    // 1. Dem neuen Knoten Wert und Typ zuweisen.
    new_value_node->type = value;
    new_value_node->content.data = number;
    // 2. Den Knoten in die neue Liste hängen.
    new_nodes_list->element = new_value_node;
    // 3. Den next-Zeiger vom Baum übernehmen.
    new_nodes_list->next = syntree->next;
    // 4. Die Liste an den next-Zeiger vom Baum hängen, also die Liste an den
    // Baum hängen.
    syntree->next = new_nodes_list;
    // 5. Die Adresse des neu erstellten Knotens, also seine ID zurückgeben.
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
*/

extern void syntreePrint(const syntree_t *self, syntree_nid root) {
    syntree_nid *tmp = &root;
    if (tmp->type == value) {
        printf("this is a value node\n");
        printf("value: %i\n", tmp->content.data);
    }
    if (tmp->type == list) {
        printf("this is a list node\n");

    }
}

