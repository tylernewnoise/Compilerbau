#### Aufgabe 1

##### Kurzbeschreibung

Implementieren Sie einen Stack, der beliebig viele Integerzahlen speichern kann ("beliebig viel" bedeutet für uns: lediglich begrenzt durch den Arbeitsspeicher). Erweitern Sie dabei eine vorgegebene Schnittstelle, so dass Ihr Stack in andere (bereits existierende) Programme eingebunden werden kann.

##### Aufgabenstellung

Bereits im C-Einführungskurs wurden Sie mit der Aufgabe betraut, einen Stack zu implementieren, so dass wir hier auf eine erneute, ausführliche Beschreibung verzichten wollen. Wie Sie in der gegebenen Headerdatei `stack.h` sehen können, betrachten wir einen Stack als eine Datenstruktur, auf der folgende Operationen ausgeführt werden können:
* `int stackInit(intstack_t* self)`  
initialisiert einen neuen Stack und liefert den Rückgabewert 0, falls keine Fehler bei der Initialisierung aufgetreten sind und andernfalls einen Fehlercode
* `void stackRelease(intstack_t* self)`  
gibt den Stack und alle assoziierten Strukturen frei
* `void stackPush(intstack_t* self, int i)`  
legt den Wert i auf den Stack
* `int stackTop(const intstack_t* self)`  
gibt das oberste Element des Stacks zurück
* `int stackPop(intstack_t* self)`  
entfernt und liefert das oberste Element des Stacks
* `int stackIsEmpty(const intstack_t* self)`  
gibt zurück, ob ein Stack leer ist, d.h. kein Element enthält (Rückgabewert != 0, wenn leer; == 0, wenn nicht)
Sollte beim Aufruf einer der Methoden ein Fehler auftauchen, so soll eine sinnvolle Fehlerausgabe nach `stderr` und ein Abbruch des Programms mit Exitcode != 0 erfolgen.

Implementieren Sie den Stack in der Datei `stack.c` und erweitern Sie die Schnittstelle `stack.h`, so dass ein externes Programm nur die Headerdatei einbinden muss, um mit Stacks arbeiten zu können.

Zusätzlich stellen wir Ihnen ein Makefile und ein Testprogramm in der Datei `teststack.c` zur Verfügung. Ihre Lösung befindet sich auf dem richtigen Weg, wenn dieses Testprogramm (ohne Änderungen an den beiden letztgenannten Dateien) erfolgreich kompiliert und durchläuft. Bitte beachten Sie jedoch, dass die Testumgebung bei weitem nicht alle interessanten Testfälle abdeckt.

Noch ein Hinweis: Sie werden feststellen, dass in der Datei `stack.h` eine Funktion namens `stackPrint()` deklariert wurde. Es steht Ihnen frei diese Funktion zu Testzwecken zu implementieren.

#### Aufgabe 2

##### Kurzbeschreibung
Implementieren Sie eine Datenstruktur, die beliebig verzweigte Bäume speichern kann, mit den im Folgenden beschriebenen Methoden.

##### Aufgabenstellung
Diese Aufgabe stellt eine der Grundlagen für den später zu implementierenden Praktikumsinterpreter dar. Die hier von Ihnen zu implementierende Datenstruktur werden Sie bei der Konstruktion des abstrakten Syntaxbaumes benötigen, da uns die Bordmittel von C keine wirkliche Hilfe leisten.

Die zu implementierende Datenstruktur `syntree_t` soll Baumknoten in beliebig komplexen Konfigurationen speichern können und davon beliebig viele. Beschreiben Sie die Implementation Ihrer Datenstruktur kurz in einem Programmkommentar am Anfang der Headerdatei. Implementieren Sie dann die folgenden Operationen:

* `int syntreeInit(syntree_t* self)`  
initialisiert einen neuen Syntaxbaum und liefert den Rückgabewert 0, falls keine Fehler bei der Initialisierung aufgetreten sind und andernfalls einen Fehlercode != 0
* `void syntreeRelease(syntree_t* self)`  
gibt den Syntaxbaum und alle assoziierten Strukturen frei
* `syntree_nid syntreeNodeNumber(syntree_t* self, int number)`  
erstellt einen neuen Knoten mit einem Zahlenwert als Inhalt und gibt dessen ID zurück; der ID-Typ ist durch Sie Ihrer Implementation entsprechend festzulegen
* `syntree_nid syntreeNodeTag(syntree_t* self, syntree_nid id)`  
kapselt einen Knoten innerhalb eines Knotens und gibt dessen ID zurück
* `syntree_nid syntreeNodePair(syntree_t* self, syntree_nid id1, syntree_nid id2)`  
kapselt zwei Knoten innerhalb eines Knotens und gibt dessen ID zurück
* `syntree_nid syntreeNodeAppend(syntree_t* self, syntree_nid list, syntree_nid elem)`  
hängt einen Knoten an das Ende eines Listenknotens und gibt dessen ID zurück
* `syntree_nid syntreeNodePrepend(syntree_t* self, syntree_nid elem, syntree_nid list)`  
hängt einen Knoten an den Anfang eines Listenknotens und gibt dessen ID zurück
* `void syntreePrint(const syntree_t* self, syntree_nid root)`  
gibt alle Zahlenknoten zwischen runden und alle zusammengesetzten Knoten zwischen geschweiften Klammern rekursiv (depth-first) auf der Standardausgabe aus
Hinweis: es ist legitim bei der Ausgabe beliebig viele Leerzeichen und Zeilenenden zu verwenden; wir werden alle Zeichen aus der Ausgabe entfernen, für die `isspace() != 0` ist
Sollte beim Aufruf einer der Methoden ein Fehler auftauchen, so soll eine sinnvolle Fehlerausgabe nach `stderr` und ein Abbruch des Programms mit Exitcode != 0 erfolgen.

Führen Sie die Implementation in der Datei `syntree.c` durch. Zur Selbstüberprüfung stellen wir Ihnen auch hier eine Testumgebung inklusive Makefile zur Verfügung.