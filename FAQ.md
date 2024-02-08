# FAQ

## Artemis bewertet meine Abgabe als fehlerhaft. Was soll ich tun?

Artemis ist im Testbetrieb und Fehler sind in dieser Phase nicht auszuschließen. Dennoch sollten Sie sicherstellen, dass
Sie die Aufgabe und die Fehlermeldung genau gelesen und verstanden haben, Beispiele (sofern angegeben) getestet haben
und alle Anforderungen durch Ihre Lösung erfüllt werden. Sofern Sie sich sicher sind, dass Ihre Lösung stimmt oder Sie
das Problem nicht identifizieren können, kontaktieren Sie bitte Ihren Proseminarleiter.

## Welche Testarten gibt es in Artemis?

In Summe gibt es folgende Testarten:

- Kompilieren: Testet, ob der abgegebene Code erfolgreich kompiliert. Sofern der Code nicht erfolgreich kompiliert,
  werden die Kompilierfehler angezeigt.
- Code Struktur: Testet, ob das Programm die gewünschte Struktur aufweist (z. B. Verwendung einer `while`-Schleife).
- Ein-/Ausgabetests: Testet, ob ein Programm die erwartete Ausgabe erzeugt und der Rückgabewert beim Beenden stimmt.
- Funktionstests: Testet, ob eine Funktion den erwarteten Rückgabewert und entsprechende Seiteneffekte hat.
- [Linten](https://en.wikipedia.org/wiki/Lint_(software)): Führt eine statische Codeanalyse durch.

Teilweise hängen Testarten voneinander ab. Beispielsweise wird ein Ein-/Ausgabetest nur ausgeführt, wenn die Abgabe
erfolgreich kompiliert werden konnte.

## Was ist ein Ein-/Ausgabetest?

Ein Ein-/Ausgabetest überprüft die Ausgabe und den Rückgabewert eines Programms. Dabei wird das Programm mit
vordefinierten Kommandozeilenparametern gestartet. Zudem werden, sofern durch die Anforderungen erforderlich, Eingaben
über die Standardeingabe bereitgestellt. Anschließend wird der Rückgabewert mit einem vordefinierten, erwarteten
Rückgabewert abgeglichen. Zusätzlich werden die Standardausgabe und Standardfehlerausgabe mit den erwarteten Ergebnissen
verglichen. Sofern mindestens ein Ergebnis nicht den Anforderungen entspricht, schlägt dieser Test fehl und es wird eine
Fehlermeldung generiert.

Aus diesem Grund ist es, wenn in der Aufgabenstellung Beispiele bereitgestellt werden, ratsam der Ausgabe möglichst
genau zu folgen und zumindest diese auch zu testen.

## Wie lese ich einen Fehlerreport eines Ein-/Ausgabetests?

In einem Ein-/Ausgabetest können mehrere Testfälle überprüft werden und möglicherweise mehrere Testfälle fehlschlagen.
In der Titelnachricht wird aufgezeigt wie viele Testfälle nicht erfolgreich waren. Anschließend werden Details zu den
einzelnen fehlerhaften Testfällen aufgelistet. Diese Details zu den Testfällen sind in folgende Abschnitte unterteilt:

- Status: Welche Teile, d. h., Rückgabewert (eng. return code), Standardausgabe (`stdout`),
  Standardfehlerausgabe (`stderr`), des Ein-/Ausgabetests entsprechen nicht der Erwartung.
- Kommandozeilenparameter (optional): Welche Kommandozeilenparameter wurden beim Start des Programms übergeben?
- Eingabe auf der Standardeingabe (optional): Welche Eingaben auf der Standardeingabe wurden getätigt?
- Ausgabe auf der Standardausgabe (optional): Welche Ausgabe auf der Standardausgabe hat das Programm erzeugt?
- Erwartete Ausgabe auf der Standardausgabe (optional): Welche Ausgabe auf der Standardausgabe wird erwartet?
- Tipp Standardausgabe (optional): Ein Tipp, wie man von der erhaltenen Ausgabe zur erwarteten Ausgabe gelangt.
- Ausgabe auf der Standardfehlerausgabe (optional): Welche Ausgabe auf der Standardfehlerausgabe hat das Programm
  erzeugt?
- Erwartete Ausgabe auf der Standardfehlerausgabe (optional): Welche Ausgabe auf der Standardfehlerausgabe wird
  erwartet?
- Tipp Standardfehlerausgabe (optional): Ein Tipp, wie man von der erhaltenen Ausgabe zur erwarteten Ausgabe gelangt.
- Tipp: Ein Tipp, welcher zur Problemlösung beitragen könnte.

Im Folgenden wird ein Beispiel gezeigt, bei welchem statt der Ausgabe `Hello World!` der Text `Hallo Welt!` auf der
Standardausgabe ausgegeben wird. In diesem Fall wird die folgende Fehlermeldung angezeigt.

```
Error: The output of your program does not match the expected output. In total 1 test case failed:


                                           Test case                                           
-----------------------------------------------------------------------------------------------

Status
======
Correct return code! Expected: '0' Obtained: '0'
Wrong output on stdout!
Correct output on stderr!

Obtained output on stdout
=========================
Hallo Welt!

Expected output on stdout
=========================
Hello World!

Hint stdout
===========
H[a->e]llo W[e->or]l[t->d]!

Hint (none)
===========
No hint available! Please, read the exercise description very carefully!


```

## Warum wird teilweise bei Ein-/Ausgabetest nicht genau aufgezeigt was falsch ist?

Die Vergleiche der Ausgaben (Standardausgabe und Standardfehlerausgabe) basieren teilweise auf regulären Ausdrucken (
engl. [regular expression](https://en.wikipedia.org/wiki/Regular_expression)s). Da verschiedene Lösungen akzeptiert
werden, kann keine Musterlösung vorgegeben werden. Generell wird empfohlen, dass Sie sich möglichst genau am Format der
Beispiele orientieren, sofern eine Beispielausgabe bereitgestellt wird.

## Der Ein-/Ausgabetest schlägt mit der Fehlermeldung `Error: timeout` fehl. Was heißt das?

Ein-/Ausgabetest dürfen eine gewisse Ausführungszeit nicht überschreiten. Sofern diese Zeit überschritten wird, kommt es
zu dieser Fehlerausgabe. Möglicherweise terminiert das Programm – beispielsweise aufgrund einer Endlosschleife oder weil
auf eine Eingabe des\*der Benutzers\*Benutzerin gewartet wird – nicht. Überprüfen Sie den Quellcode Ihres Programms
genau. Sofern Sie keine Probleme feststellen können, kontaktieren Sie bitte Ihren Proseminarleiter.

## Auf meinem Rechner funktioniert alles und entspricht der Vorgabe ganz genau; in Artemis bekomme ich beim Ein-/Ausgabetest einen Fehler. Was ist das Problem?

Möglicherweise kann das Verhalten des Programms durch den Quellcode nicht vollständig bestimmt werden aufgrund
von [undefined behavior](https://en.wikipedia.org/wiki/Undefined_behavior),
[unspecified behavior](https://en.wikipedia.org/wiki/Unspecified_behavior), implementation-defined behavior oder
locale-specific behavior. Beispielsweise ist das Verhalten für folgende Fälle undefiniert:

- Der Wert einer Variable mit automatischer Lebensdauer wird verwendet ohne, dass diese initialisiert wurde
  (z. B. `int a; int b = a + 3;` – Wert der Variable `b` ist undefiniert)
- Umwandlung eines Gleitkommazahldatentyps (z. B. `float`) zu einem Ganzzahldatentyp (z. B. `char`), wenn der
  Ganzzahlteil nicht im Ganzzahldatentyp dargestellt werden kann (z. B. `float f = 400.3; char c = f;` – Wert der
  Variable `c` ist undefiniert).

Überprüfen Sie den Quellcode Ihres Programms genau. Sofern Sie keine Probleme feststellen können, kontaktieren Sie bitte
Ihren Proseminarleiter.

## Meine Abgabe kompiliert auf meinem Rechner; in Artemis bekomme ich einen Kompilierfehler. Was ist das Problem?

Stellen Sie sicher, dass Sie [`gcc`](https://gcc.gnu.org/) als Compiler verwenden und, sofern von der Aufgabenstellung
nicht anders gefordert, mit den Optionen, d. h.
Flags, [`-Wall`](https://gcc.gnu.org/onlinedocs/gcc-8.3.0/gcc/Warning-Options.html#index-Wall)
, [`-Werror`](https://gcc.gnu.org/onlinedocs/gcc-8.3.0/gcc/Warning-Options.html#index-Werror)
, [`-Wextra`](https://gcc.gnu.org/onlinedocs/gcc-8.3.0/gcc/Warning-Options.html#index-Wextra)
, [`-Wpedantic`](https://gcc.gnu.org/onlinedocs/gcc-8.3.0/gcc/Warning-Options.html#index-Wpedantic)
und [`-std=c18`](https://gcc.gnu.org/onlinedocs/gcc-8.3.0/gcc/C-Dialect-Options.html#index-std-1) kompilieren.
Überprüfen Sie, dass Sie lokal denselben Code bearbeiten wie in Artemis. Sollte dies das Problem nicht beheben,
kontaktieren Sie bitte Ihren Proseminarleiter.

## Werden die Punkte aus Artemis oder OLAT für die Benotung des Proseminars herangezogen?

Für die Benotung des Proseminars werden die im OLAT-Kurs hinterlegten erreichten Punkte herangezogen. Stellen Sie aber
dennoch sicher, dass Sie Ihre Lösung in Artemis abgeben und auf mögliche Fehlermeldungen eingehen!
