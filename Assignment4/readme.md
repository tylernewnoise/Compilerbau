### Assignment 4

#### Aufgabe 1

##### Kurzbeschreibung

Implementieren Sie unter Verwendung des Werkzeugs Bison einen Parser für die Sprache C1. Erweitern Sie dazu das von uns vorgegebene Gerüst in der Datei `minako-syntax.y`.

##### Aufgabenstellung
Der von uns verwendete Parsergenerator Bison sollte Ihnen bereits aus der Vorlesung bekannt sein. Da Materialien zu Bison (Handbücher, Tutorials, …) sehr zahlreich im Netz vorhanden sind, wird hier auf eine weitere Erklärung verzichtet.

Ihre Aufgabe besteht darin, einen Parser für die Sprache C1 zu erstellen. Dazu bekommen Sie von uns einen Scanner. (Sie können theoretisch auch Ihren Scanner vom Aufgabenblatt 2 benutzen – zur Korrektur werden wir jedoch den von uns gegebenen verwenden!)

Die Grammatik von C1 finden Sie hier. Da Bison leider keine EBNF, sondern nur BNF versteht, werden Sie die Grammatik zwangsläufig umbauen müssen. Dabei ist im Prinzip fast alles erlaubt, nur die Sprache darf sich dabei natürlich nicht ändern!

Folgende Anforderungen werden Ihre Lösung gestellt:

* wenn man den Parser ohne Kommandozeilenparameter aufruft, soll er von stdin lesen, ansonsten aus der auf der Kommandozeile angegebenen Datei (dabei sollen eventuell auftauchende Dateizugriffsfehler wie üblich abgefangen werden)
* die Implementation erfolgt in der Datei `minako-syntax.y`
* der Parser gibt im erfolgreichen Fall nichts aus und beendet sich mit dem Rückgabewert 0
* bei einem Parserfehler wird eine Fehlermeldung (beendet durch ein Newline) ausgegeben und das Programm mit einem Rückgabewert ungleich 0 beendet
* wenn Sie den Parser auf das mitgelieferte C1-Programm `demorgan.c1` ansetzen, sollte er entsprechend nichts ausgeben und sich mit Rückgabewert 0 beenden
* die Verwendung von `%expect` ist nicht gestattet

Zur Hilfestellung seien noch folgende Hinweise gegeben:
Gehen Sie am Anfang alle EBNF-Konstrukte durch und überlegen Sie sich, wie man diese jeweils generisch in BNF umwandeln kann.
In dieser Grammatik ist eine Mehrdeutigkeit enthalten, die einem spätestens bei der Implementierung auffällt.
Rufen Sie sich die Bedeutung von `%left`, `%right` und `%nonassoc` in Erinnerung, bevor Sie die Grammatik unnötig verkomplizieren.