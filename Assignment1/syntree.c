#include "syntree.h"

extern int syntreeInit(syntree_t *syntree) {
    return 0;
}

extern void syntreeRelease(syntree_t *syntree) {
}

extern syntree_nid syntreeNodeNumber(syntree_t *syntree, int number) {
    struct nid tmp;
    return tmp;
}

extern syntree_nid syntreeNodeTag(syntree_t *syntree, syntree_nid id) {
    struct nid tmp;
    return tmp;
}

extern syntree_nid syntreeNodePair(syntree_t *syntree, syntree_nid id1, syntree_nid id2) {
    struct nid tmp;
    return tmp;
}

extern syntree_nid syntreeNodeAppend(syntree_t *self, syntree_nid list, syntree_nid elem) {
    struct nid tmp;
    return tmp;
}

extern void syntreePrint(const syntree_t *self, syntree_nid root) {
}