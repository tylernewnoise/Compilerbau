### Assignment 3

#### Aufgabe 1

##### Kurzbeschreibung

Implementieren Sie von Hand einen Parser, der die Sprache C(-1) (eine Teilsprache von C1) erkennen kann. Verwenden sie dazu den beigelegten Scanner.

##### Aufgabenstellung

Nachdem Sie in der letzten Praktikumsaufgabe einen Scanner für die lexikalische Analyse gebaut haben, sollen Sie sich diesmal mit der syntaktischen Analyse beschäftigen. Wie Sie bereits in der Vorlesung gelernt haben, gibt es mehrere Ansätze, einen Parser zu bauen. Insbesondere wird dabei zwischen handgeschriebenen Parsern und (durch Parsergeneratoren) generierten Parsern unterschieden.
In dieser Aufgabe soll ein handgeschriebener Parser nach dem Prinzip des rekursiven Abstiegs implementiert werden. Da ein handgeschriebener Parser in der Regel ziemlich umfangreich ist, haben wir uns dazu entschlossen, die Sprache C1 (die ja durch Abrüsten aus C entstanden ist) noch einmal zu vereinfachen, um Ihnen extreme Tipporgien zu ersparen.
Sie finden die Grammatik von C(-1) [hier](https://amor.cms.hu-berlin.de/~kunert/lehre/material/c-1-grammar.php). Zusätzlich sind folgende Punkte zu beachten:

* wenn man den Parser ohne Kommandozeilenparameter aufruft, soll er von stdin lesen, ansonsten aus der auf der Kommandozeile angegebenen Datei (dabei sollen eventuell auftauchende Dateizugriffsfehler wie üblich abgefangen werden)
* die Implementation hat in einer Datei namens `minako-syntax.c` zu erfolgen
* der Parser gibt im erfolgreichen Fall nichts aus und beendet sich mit dem Rückgabewert 0
* bei einem Parserfehler wird eine Fehlermeldung (beendet durch ein Newline) nach `stderr` ausgegeben und das Programm mit einem Rückgabewert ungleich 0 beendet
* wenn sie den Parser auf das mitgelieferte C(-1)-Beispielprogramm `beispiel.c-1` ansetzen, sollte er entsprechend nichts ausgeben und sich mit Rückgabewert 0 beenden - sehen Sie bitte diesen Test als Mindestvoraussetzung für eine Abgabe an.

Bitte halten Sie sich des Weiteren an folgende Konventionen:
* Das jeweils aktuelle Token wird in einer Variable namens `currentToken`, das darauffolgende Token (Lookahead) in einer Variablen namens `nextToken` gespeichert
* Implementieren (und benutzen) Sie eine Funktion namens `eat()`, die das aktuelle Token „frisst“
* Implementieren (und benutzen) Sie eine Funktion namens `isTokenAndEat()`, die überprüft, ob das ihr übergebene Token gleich dem aktuellen ist. Im Positivfall wird das aktuelle Token „gefressen“, im Negativfall ein Fehler `ERROR: Syntaxfehler in Zeile (<zeile>)` ausgegeben und das Programm mit Exitcode -1 abgebrochen.
* Implementieren (und benutzen) Sie eine Funktion namens `isToken()`, die überprüft, ob das ihr übergebene Token gleich dem aktuellen ist und das Ergebnis des Vergleiches als `int` kodiert zurückgibt.