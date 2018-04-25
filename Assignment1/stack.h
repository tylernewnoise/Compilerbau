#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

/* *** structures *********************************************************** */

/**@brief Struktur des Stacks.
 */
typedef struct
{
    /* hier sollte noch etwas dazu kommen */
} intstack_t;

/* *** interface ************************************************************ */

/**@brief Initialisiert einen neuen intstack.
 * @param self  der zu initialisierende intstack
 * @return 0, falls keine Fehler bei der Initialisierung aufgetreten sind,
 *      != 0, ansonsten
 */
extern int
stackInit(intstack_t* self);

/**@brief Gibt den intstack und alle assoziierten Strukturen frei.
 * @param self  der freizugebende intstack
 */
extern void
stackRelease(intstack_t* self);

/**@brief Legt einen Wert auf den intstack.
 * @param self  der intstack
 * @param i     der Wert
 */
extern void
stackPush(intstack_t* self, int i);

/**@brief Gibt das oberste Element des Stacks zurück.
 * @param self  der intstack
 * @return das oberste Element von \p self
 */
extern int
stackTop(const intstack_t* self);

/**@brief Entfernt und liefert das oberste Element des Stacks.
 * @param self  der intstack
 * @return das oberste Element von \p self
 */
extern int
stackPop(intstack_t* self);

/**@brief Gibt zurück, ob der intstack leer ist.
 * @param self  der intstack
 * @return 0, falls nicht leer,
        != 0, falls leer
 */
extern int
stackIsEmpty(const intstack_t* self);

/**@brief Gibt den Inhalt des Stacks beginnend mit dem obersten Element auf der Standardausgabe aus.
 * @param self  der intstack
 */
extern void
stackPrint(const intstack_t* self);

#endif /* STACK_H_INCLUDED */
