# Aufgabe 1 (15 Bonuspunkte)

## Vorlesungsfolien

* Strukturen, Unions, Bitfelder (EidP-09-StrukturenUnionsBitfelder.pdf)
* Dynamische Speicherverwaltung (EidP-11-DynamischeSpeicherverwaltung.pdf)
* Modulare Programmierung in C (EidP-13-ModulareProgrammierung.pdf)
* Ein-/Ausgabe (EidP-14-IO.pdf)

## Beschreibung

Ziel dieser Aufgabe ist es ein Programm zu erstellen, welches die Worte in einer als Kommandozeilenparameter übergebenen
Textdatei beliebiger Länge – unabhängig von Groß- und Kleinschreibung – zählt. Die Worte und deren Häufigkeit sollen in
einer Liste (`my_list` aus Aufgabenblatt 10) gespeichert werden. Sie können davon ausgehen, dass im zu durchsuchenden
Text nur die folgenden Trennzeichen vorkommen:

- `' '`
- `'\n'`
- `'\t'`
- `'?'`
- `'!'`
- `'.'`
- `','`
- `';'`
- `':'`
- `'('`
- `')'`

Andere Sonderzeichen werden als Teil der Wörter bzw. eigenständige Wörter angesehen.

Am Ende sollen die vorkommenden Wörter, zusammen mit den ermittelten Häufigkeiten, lexikografisch sortiert auf der
Standardausgabe als Tabelle ausgegeben werden, wobei die Spalte mit den Wörtern den Titel `Word` und die Spalte mit den
entsprechenden Häufigkeiten den Titel `Count` trägt. Zwischen dem Titel und den weiteren Zeilen der Tabelle werden
Minuszeichen (`-`) ausgegeben (mindestens ein Minuszeichen), um die Zeile mit dem Titel von den restlichen Zeilen zu
trennen. Anschließend wird pro Zeile jeweils ein Wort mit der entsprechenden Häufigkeit ausgegeben. Abgesehen von der
Zeile mit den Minuszeichen, werden die Spalten jeweils mit mindestens einem Leerzeichen getrennt.

## Beispiele

### Inhalt der Eingabedatei `s13e01-in1.txt`

```text
A very VERY short example.
```

### Aufruf und Ausgabe

```text
./s13e01 s13e01-in1.txt
Word     Count
--------------
a            1
example      1
short        1
very         2

```

## Hinweise

- Übertragen Sie Ihre `my_list` Implementierung in die Datei `my_list.c`. Implementieren Sie für die lexikografische
  Sortierung der Liste die Funktion mit der
  Signatur `void my_list_sort(my_list *list, int (*compar)(const void *, const void *))`.
- Sie können für diese Aufgabe annehmen, dass die maximale Zeilenlänge in den übergebenen Textdateien 80 Zeichen nicht
  überschreitet.
- In der ausgegebenen Tabelle wird die Anzahl der Leerzeichen zwischen `Word` und `Count` sowie die Anzahl der
  Leerzeichen zwischen den effektiven Worten und den ausgegebenen Häufigkeiten von den Tests nicht überprüft. Es muss
  allerdings mindestens 1 Leerzeichen vorhanden sein. Außerdem wird auch die Anzahl der `-` in der Trennlinie zwischen
  Tabellenkopf und Rumpf nicht überprüft. Auch hier wird mindestens ein Zeichen erwartet.
- Halten Sie sich genau an das Format aus der Beschreibung und geben Sie keine weiteren Texte aus!
- Weitere Texte zum Testen finden Sie im Ordner `examples`. Dort finden Sie auch die dazugehörigen Lösungen zur
  Kontrolle.
