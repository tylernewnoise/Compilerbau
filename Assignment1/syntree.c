#include "syntree.h"
#include <stdlib.h>
#include <mhash.h>

// Definition vom Knoten. Der Knoten kann entweder einen Wert enthalten oder aber
// weitere Knoten (Kapselung) und somit eine Liste von Knoten (list_of_nodes).
struct Node {
    union {
        int value;
        struct list_of_nodes *kid;
    } content;
};

// Klassische einfach verkettete Liste. Der Inhalt sind die Knoten und ein Zeiger auf das nächste Element.
struct list_of_nodes {
    struct Node *element;
    struct list_of_nodes *next;
};

// Das erste Element der id_Liste.
syntree_nid *first = NULL;

extern int syntreeInit(syntree_t *syntree) {
    if (!syntree) {
        return 1;
    }
    syntree->nodes = NULL;
    return 0;
}

extern void syntreeRelease(syntree_t *syntree) {
    // TODO
}

// Die Node_IDs sind Zeiger, welche direkt auf den Knoten zeigen. Diese sind in einer einfach verketteten Liste
// organisiert.
syntree_nid setNodeID(syntree_t *syntree, struct Node *node) {
    syntree_nid *tmp = malloc(sizeof(syntree_nid));
    if (tmp == NULL) {
        fprintf(stderr, "Error: out of Memory!\n");
        exit(EXIT_FAILURE);
    }
    tmp->next_id = NULL;
    tmp->node_id = node;
    printf("yay");
    // Checken ob es der allererste Knoten der Liste ist.
    if (first == NULL) {
        first = tmp;
        return *first;
    }
    syntree_nid *new_id = first;
    while (new_id != NULL) {
        if (new_id->next_id == NULL) {
            new_id->node_id = node;
            tmp->next_id = new_id->next_id;
            new_id->next_id = tmp;
            return *new_id;
        }
        new_id = new_id->next_id;
    }
    return *first;
}


extern syntree_nid syntreeNodeNumber(syntree_t *syntree, int number) {
    // Erstmal einen neuen Knoten erstellen.
    struct Node *tmp_new_value_node = malloc(sizeof(struct Node));
    //struct list_of_nodes *tmp_list = malloc(sizeof(struct list_of_nodes));
    //Aif (!tmp_new_value_node || !tmp_list) {
    if (!tmp_new_value_node) {
        fprintf(stderr, "Error: out of Memory!\n");
        exit(EXIT_FAILURE);
    }
    tmp_new_value_node->content.value = number;
    //printf("yay\n");
    return setNodeID(syntree, tmp_new_value_node);
}

extern syntree_nid syntreeNodeTag(syntree_t *syntree, syntree_nid id) {
    // Erstmal einen neuen Knoten erstellen.
    struct Node *temp_new_tag_node = malloc(sizeof(struct Node));
    if (temp_new_tag_node == NULL) {
        fprintf(stderr, "Error: out of Memory!\n");
        exit(EXIT_FAILURE);
    }
    temp_new_tag_node->content.kid->next = NULL;
    temp_new_tag_node->content.kid->element = id.node_id;

    return setNodeID(syntree, temp_new_tag_node);
}

extern syntree_nid syntreeNodePair(syntree_t *syntree, syntree_nid id1, syntree_nid id2) {
    struct Node *temp_new_tag_node = malloc(sizeof(struct Node));
    if (temp_new_tag_node == NULL) {
        fprintf(stderr, "Error: out of Memory!\n");
        exit(EXIT_FAILURE);
    }
    return setNodeID(syntree, temp_new_tag_node);
}

extern syntree_nid syntreeNodeAppend(syntree_t *syntree, syntree_nid list, syntree_nid elem) {
    struct Node *temp_new_tag_node = malloc(sizeof(struct Node));
    if (temp_new_tag_node == NULL) {
        fprintf(stderr, "Error: out of Memory!\n");
        exit(EXIT_FAILURE);
    }
    return setNodeID(syntree, temp_new_tag_node);
}

extern void syntreePrint(const syntree_t *self, syntree_nid root) {
}