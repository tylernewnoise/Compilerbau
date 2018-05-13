#include "syntree.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


extern int syntreeInit(syntree_t *syntree) {
    if (! syntree) {
        return 1;
    }
    syntree->root = NULL;
    return 0;
}

extern syntree_nid syntreeNodeNumber(syntree_t *syntree, int number) {
    syntree_nid *new_node_ptr = malloc(sizeof(syntree_nid));
    if (! new_node_ptr) {
        fprintf(stderr, "Error: out of Memory!\n");
        syntreeRelease(syntree);
        exit(EXIT_FAILURE);
    }
    new_node_ptr->number = number;
    new_node_ptr->nodeType = nodeNumber;
    new_node_ptr->pointer = new_node_ptr;
    new_node_ptr->next = NULL;
    new_node_ptr->capsuled = NULL;
    return *new_node_ptr;
}

extern void syntreeRelease(syntree_t *syntree) {
    releaseHelper(syntree->root);
}

extern void releaseHelper(syntree_nid *node) {
    if (node->next) {
        releaseHelper(node->next);
        node->next = NULL;
    }
    if (node->capsuled) {
        releaseHelper(node->capsuled);
        node->capsuled = NULL;
    }

    if (! node->capsuled && ! node->next) {
        free(node);
        return;
    }
}

extern syntree_nid syntreeNodeTag(syntree_t *syntree, syntree_nid id) {
    syntree_nid *new_node_ptr = malloc(sizeof(syntree_nid));
    if (! new_node_ptr ) {
        fprintf(stderr, "Error: out of Memory!\n");
        syntreeRelease(syntree);
        exit(EXIT_FAILURE);
    }
    new_node_ptr->nodeType = nodeTag;
    new_node_ptr->pointer = new_node_ptr;
    new_node_ptr->next = NULL;
    new_node_ptr->capsuled = id.pointer;
    syntree->root = new_node_ptr;

    return *new_node_ptr;
}

extern syntree_nid
syntreeNodePair(syntree_t *syntree, syntree_nid id1, syntree_nid id2) {
    syntree_nid *new_node_ptr = malloc(sizeof(syntree_nid));
    if (! new_node_ptr /*!new_nodes_list*/) {
        fprintf(stderr, "Error: out of Memory!\n");
        syntreeRelease(syntree);
        exit(EXIT_FAILURE);
    }
    new_node_ptr->nodeType = nodeTag;
    new_node_ptr->pointer = new_node_ptr;
    new_node_ptr->capsuled = id1.pointer;
    id1.pointer->next = id2.pointer;
    syntree->root = new_node_ptr;
    return *new_node_ptr;
}

extern syntree_nid
syntreeNodeAppend(syntree_t *syntree, syntree_nid list, syntree_nid elem) {
    //Die übergebene Liste ist ein NodeTag
    if (list.pointer->nodeType == nodeTag) {
        //gehe bis zum letzten Element
        syntree_nid tab_iterator = *list.pointer->capsuled;
        while (tab_iterator.next != NULL) {
            tab_iterator = *tab_iterator.next;
        }
        tab_iterator.pointer->next = elem.pointer;
    } else { //übergebene Liste ist NodeNumber
        syntree_nid number_iterator = *list.pointer;
        while (number_iterator.next != NULL) {
            number_iterator = *number_iterator.next;
        }
        number_iterator.pointer->next = elem.pointer;
    }
    return *list.pointer;
}

extern syntree_nid
syntreeNodePrepend(syntree_t *self, syntree_nid elem, syntree_nid list) {
    if (list.pointer->nodeType == nodeTag) {
        elem.pointer->next = list.pointer->capsuled;
        list.pointer->capsuled = elem.pointer;
    } else {
        elem.pointer->next = list.pointer->next;
        list.pointer->next = elem.pointer;
    }
    return *list.pointer;
}

extern void syntreePrint(const syntree_t *self, syntree_nid root) {
    if (root.nodeType == nodeTag) {
        printf("{");
        if (root.capsuled) {
            syntreePrint(self, *root.capsuled);
        }
        if (root.next) {
            syntreePrint(self, *root.next);
        }
    } else {
        printf("(%i)", root.number);
        if (root.next) {
            syntreePrint(self, *root.next);
        } else {
            printf("}");
        }
    }
}

