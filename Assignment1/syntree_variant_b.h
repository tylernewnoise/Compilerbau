#ifndef SYNTREE_H_INCLUDED
#define SYNTREE_H_INCLUDED

/* *** structures *********************************************************** */
/**@brief Struktur des abstrakten Syntaxbaumes.
 */
// Ein enum um einen Typen zu deklarieren um die Knoten unterscheiden zu
// können.
typedef enum {
    nodeNumber, nodeTag
} identifier;

// Der eigentliche Knoten. Die ID des Knotens ist dabei seine Adresse im RAM.
// Der identifier nodeType beschreibt ob es sich um einen Kapselknoten
// (NodeTag) oder einen Knoten (Blatt) mit einer Nummer handelt (NodeNumber).
// capsuled zeigt auf das erste Element, dass in diesem NodeTag gekapselt ist.
// Die weiteren gekaplseten Elemente werden dann über next angesprochen. Der
// next Zeiger zeigt auf das nächste Element in der gleichen "Ebene".

typedef struct syntree_nid {
    int number;
    identifier nodeType;
    struct syntree_nid *pointer;
    struct syntree_nid *next;
    struct syntree_nid *capsuled;
} syntree_nid;

// Die Grundstruktur des Baumes. Sie enthält einfach nur einen Zeiger zu einer
// Liste, in der alle Knoten hängen.
typedef struct {
    struct syntree_nid *root;
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

/**@brief Helper Funktion mit der man rekursiv alle Knoten des Baumes löschen
 * kann
 * @param node Ein Zeiger auf einen nachfolgenden Knoten
 */
extern void releaseHelper(syntree_nid *node);

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
