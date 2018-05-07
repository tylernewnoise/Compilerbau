#ifndef SYNTREE_H_INCLUDED
#define SYNTREE_H_INCLUDED

/* *** structures *********************************************************** */
/**@brief Struktur des abstrakten Syntaxbaumes.
 */
// id des knotens, einfach ne zahl;
typedef unsigned int syntree_nid;

// liste für knoten
struct list_of_nodes;

// definition vom knoten. der knoten kann entweder einen wert enthalten, oder aber
// weitere knoten (kapselung) und somit eine liste
struct Node {
    syntree_nid node_id; //id vom knoten
    union {
        int value;
        struct list_of_nodes *next;
    } content;
};

// klassische einfach verkettete Liste. Die Elemente sind die Knoten und ein Zeiger auf das nächste Element.
struct list_of_nodes {
    struct Node *element;
    struct list_of_nodes *next;
};

// der eigentliche Baum
typedef struct {
    struct list_of_nodes *nodes;
} syntree_t;

/* *** interface ************************************************************ */

/**@brief Initialisiert einen neuen Syntaxbaum.
 * @param self  der zu initialisierende Syntaxbaum
 * @return 0, falls keine Fehler bei der Initialisierung aufgetreten sind,
 *      != 0 ansonsten
 */
extern int
syntreeInit(syntree_t *self);

/**@brief Gibt den Syntaxbaum und alle assoziierten Strukturen frei.
 * @param self  der freizugebende Syntaxbaum
 */
extern void
syntreeRelease(syntree_t *self);

/**@brief Erstellt einen neuen Knoten mit einem Zahlenwert als Inhalt.
 * @param self    der Syntaxbaum
 * @param number  die Zahl
 * @return ID des neu erstellten Knoten
 */
extern syntree_nid
syntreeNodeNumber(syntree_t *self, int number);

/**@brief Kapselt einen Knoten innerhalb eines anderen Knotens.
 * @param self  der Syntaxbaum
 * @param id    der zu kapselnde Knoten
 * @return ID des neu erstellten Knoten
 */
extern syntree_nid
syntreeNodeTag(syntree_t *self, syntree_nid id);

/**@brief Kapselt zwei Knoten innerhalb eines Knoten.
 * @param self  der Syntaxbaum
 * @param id1   erster Knoten
 * @param id2   zweiter Knoten
 * @return ID des neu erstellten Knoten
 */
extern syntree_nid
syntreeNodePair(syntree_t *self, syntree_nid id1, syntree_nid id2);

/**@brief Hängt einen Knoten an das Ende eines Listenknotens.
 * @param self  der Syntaxbaum
 * @param list  Listenknoten
 * @param elem  anzuhängender Knoten
 * @return ID des Listenknoten
 */
extern syntree_nid
syntreeNodeAppend(syntree_t *self, syntree_nid list, syntree_nid elem);

/**@brief Hängt einen Knoten an den Anfang eines Listenknotens.
 * @param self  der Syntaxbaum
 * @param elem  anzuhängender Knoten
 * @param list  Listenknoten
 * @return ID des Listenknoten
 */
extern syntree_nid
syntreeNodePrepend(syntree_t *self, syntree_nid elem, syntree_nid list);

/**@brief Gibt alle Zahlenknoten rekursiv (depth-first) aus.
 * @param self  der Syntaxbaum
 * @param root  der Wurzelknoten
 */
extern void
syntreePrint(const syntree_t *self, syntree_nid root);

#endif /* SYNTREE_H_INCLUDED */
