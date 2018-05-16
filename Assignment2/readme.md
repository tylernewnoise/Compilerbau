### Assignment 2

#### Aufgabe 1

##### Kurzbeschreibung

Implementieren Sie mit Hilfe von `flex` einen Scanner, der in einem Eingabestrom bzw. in einer Eingabedatei die Token der Sprache C1 erkennt.

##### Aufgabenstellung

In den Praktikumsveranstaltungen wurde bzw. wird der Umgang mit dem Scannergenerator `flex` besprochen. Mittels dieses Werkzeuges sollen sie einen Scanner implementieren, der aus einem Eingabestrom die Token der Sprache C1 extrahiert.

Die Lexik der Sprache C1 befindet sich [hier](https://amor.cms.hu-berlin.de/~kunert/lehre/material/c1-lexic.php). Zusätzlich sind folgende Punkte zu beachten:

* wenn man den Scanner ohne Kommandozeilenparameter aufruft, soll er von stdin lesen, ansonsten aus der auf der Kommandozeile angegebenen Datei (dabei sollen eventuell auftauchende Dateizugriffsfehler abgefangen werden)
* die Implementation befindet sich in der Datei `minako-lexic.l`
* Whitespaces (Leerzeichen, Tabulatoren, Zeilenenden) sollen vom Scanner ignoriert werden
* C- (`/* */`) und C++- (`//`) Kommentare sollen ebenfalls überlesen werden
* es sind nur die in der Headerdatei `minako.h` definierten Token (z.B.: "`==`") als Konstanten (im Bsp.: `EQ`) zurückzugeben; bei allen nicht in `minako.h` erwähnten Zeichen (die aber laut Lexikbeschreibung zur Lexik von C1 gehören, z.B.: "`+`"), soll einfach der ASCII-Wert des Zeichens zurückgegeben werden
* alle nicht in C1 erlaubten Zeichen (z.B.: "`&`") sollen zu einem lexikalischen Fehler führen (also zu einer sinnvollen Fehlerausgabe und Programmabbruch)
* wenn Sie den Scanner auf das mitgelieferte C1-Beispielprogramm `demorgan.c1` ansetzen, sollte genau die in `demorgan.sol` stehende Ausgabe erfolgen

#### Aufgabe 2

##### Kurzbeschreibung
Implementieren Sie mit Hilfe von `flex` einen Scanner, der in einem Eingabestrom bzw. aus einer Eingabedatei URLs und damit verbundene Linkbeschreibungen extrahiert.

##### Aufgabenstellung
Der zweite zu implementierende Scanner soll mittels `flex` aus einem Eingabestrom im xhtml-Format die URLs und die Linktexte extrahieren und ausgeben.

Zur Vereinfachung der Analyse gelten folgende Konventionen:

* der Eingabestrom ist valides xhtml, das keinen CDATA Abschnitt enthält. Die Links haben das Format`<a ... href="URL" ... >LINKTEXT</a>`, wobei im schließenden Tag nach dem 'a' null oder mehr Leerzeichen und Newlines stehen dürfen. Innerhalb des öffnenden Tags dürfen vor und nach `href` weitere Attribute auftreten, die überlesen werden
* Newlines innerhalb von `LINKTEXT` gehören zum Linktext. D.h. alles innerhalb des `a`-Tags gehört zum Linktext
* zwischen `<a ...>` und `</a>` treten keine anderen Tags auf
* `a`-Tags, die kein `href`-Attribut beinhalten, werden komplett ignoriert
* die Eingabe enthält keinerlei Kommentare

Bitte vergleichen Sie Ihre Ausgabe bei Eingabe der Datei `testeingabe.html` mit der erwarteten Ausgabe in href`testeingabe.sol`.