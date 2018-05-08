#include "syntree.h"
#include <stdio.h>

int main() {
    syntree_t tree;
    syntree_nid id;

    syntreeInit(&tree);
    id = syntreeNodeNumber(&tree, 666);
    syntreePrint(&tree, id);
    printf("%p \n", id);
    id = syntreeNodeNumber(&tree, 1337);
    syntreePrint(&tree, id);
    printf("%p \n", id);
    id = syntreeNodeNumber(&tree, 731);
    syntreePrint(&tree, id);
    printf("%p \n", id);
    //id = syntreeNodeTag(&tree, syntreeNodeNumber(&tree, 0));
/*
    for (unsigned int i = 1; i < 10; ++i) {
        switch (i % 3) {
            case 0:
                id = syntreeNodePair(&tree, syntreeNodeNumber(&tree, i), id);
                break;

            case 1:
                id = syntreeNodeAppend(&tree, id, syntreeNodeNumber(&tree, i));
                break;

            case 2:
                id = syntreeNodePrepend(&tree, syntreeNodeNumber(&tree, i), id);
                break;
            default:break;
        }
    }

    syntreePrint(&tree, id);
    syntreeRelease(&tree);*/
    printf("Durchgelaufen!\n");
    return 0;
}

/* Erwartete Ausgabe nach Entfernen aller Leerzeichen:
{(9){(8)(6){(5)(3){(2)(0)(1)}(4)}(7)}}

Mit Leerzeichen:
{
    (9)
    {
        (8)
        (6)
        {
            (5)
            (3)
            {
                (2)
                (0)
                (1)
            }
            (4)
        }
        (7)
    }
}
*/
