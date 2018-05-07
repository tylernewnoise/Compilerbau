#include "syntree.h"
#include <stdlib.h>

// definition vom knoten. der knoten kann entweder einen wert enthalten, oder aber
// weitere knoten (kapselung) und somit eine liste
struct Node {
    syntree_nid node_id; //id vom knoten
    union {
        int value;
        struct list_of_nodes *kid;
    } content;
};

// klassische einfach verkettete Liste. Die Elemente sind die Knoten und ein Zeiger auf das nächste Element.
struct list_of_nodes {
    struct Node *element;
    struct list_of_nodes *next;
};

extern int syntreeInit(syntree_t *syntree) {
    syntree->nodes = NULL;
    return 0;
}

extern void syntreeRelease(syntree_t *syntree) {
    // TODO
}

extern syntree_nid syntreeNodeNumber(syntree_t *syntree, int number) {
    // get new id - how?!
    struct nid *tmp;
    return tmp;
}

extern syntree_nid syntreeNodeTag(syntree_t *syntree, syntree_nid id) {
    struct nid tmp;
    return *tmp;
}

extern syntree_nid syntreeNodePair(syntree_t *syntree, syntree_nid id1, syntree_nid id2) {
    struct nid tmp;
    return *tmp;
}

extern syntree_nid syntreeNodeAppend(syntree_t *self, syntree_nid list, syntree_nid elem) {
    struct nid tmp;
    return *tmp;
}

extern void syntreePrint(const syntree_t *self, syntree_nid root) {
}