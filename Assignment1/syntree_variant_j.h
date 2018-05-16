#ifndef SYNTREE_H_INCLUDED
#define SYNTREE_H_INCLUDED

/*********************************************************************************************************************
 *                                                                                                                   *
 *  Das Struct syntree_nid beinhaltet die int Variable value, in der der Zahlenwert gespeichert wird.                *
 *  Außerdem beinhaltet es ein Pointer auf sich selbst, da die Funktionsprototypen im Header ein syntree_nid Objekt  *
 *  uebergeben und nicht ein Pointer auf ein syntree_nid Objekt. Da C alle Funktionsargumente als Call by Value      *
 *  uebergibt, kann man ueber den self_ptr auf das eigentliche Objekt zugreifen. syntree_nid* next ist ein           *
 *  Pointer auf das nächste Objekt in der gleichen Ebene der Baumtruktur. syntree_nid* capsuled ist ein Pointer      *
 *  auf den ersten Kindknoten des Listenknotens. Alle weitere Kindknoten lassen sich erreichen, indem man            *
 *  den * capsuled Pointer zum ersten Kindknoten folgt und dann ueber den * next Pointer des Kindknotens zum         *
 *  naechsten kommt, genau wie bei einer einfach verketteten Liste. Zusaezlich gibt es das struct linked_list,       *
 *  das ausschließlich dazu da ist, alle alloziierten Baum Knoten einem syntree zuzuordnen und spaeter alle          *
 *  Knoten wieder freizugeben. Da ein Knoten auch ertsellt werden kann ohne ihn im Baum "einzuhaengen", ist          *
 *  dieser Schritt notwendig um Memory Leaks zu vermeiden.                                                           *
 *                                                                                                                   *
 *********************************************************************************************************************/

/* *** structures *********************************************************** */

typedef struct nid {
    int value;
    struct nid *self_ptr;
    struct nid *next;
    struct nid *capsuled;
} syntree_nid;


struct linked_list {
    syntree_nid *ptr_value;
    struct linked_list *next;
};

/**@brief Struktur des abstrakten Syntaxbaumes.
 */
typedef struct {
    struct linked_list *root;
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

/**@brief Haengt einen Knoten an das Ende eines Listenknotens.
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
