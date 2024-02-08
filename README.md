# Aufgabe 1 (4 Punkte)

## Vorlesungsfolien

* Einführung (EidP-01-Einfuehrung.pdf)

## Beschreibung

In dieser Aufgabe sollen Sie sich mit einigen Grundlagen vertraut machen. Verwenden Sie dafür einen Rechner mit einer
Linux Distribution Ihrer Wahl. Stellen Sie sicher, dass `gcc` installiert ist. Testen Sie erneut, ob das im Proseminar
besprochene *Hello World*-Programm `s00e01.c` kompiliert.

### Arbeitsschritte

Beantworten Sie die folgenden Fragen in der Textdatei `s01e01.txt`.

1. Was ist `gcc`? Wozu wird es gebraucht? Gibt es Alternativen?
2. Welche `gcc` Version ist auf Ihrem System installiert? Wie haben Sie diese Information ermittelt?
3. Welche ist die neueste `gcc` Version?
4. Erklären Sie die einzelnen Befehle Ihres *Hello World*-Programmcodes `s01e01.c` mithilfe von Kommentaren im
   Quellcode.
5. Was ist der Unterschied zwischen C-Quellcode und einem Executable, d. h. einer ausführbaren Datei? Ist `s01e01.c` ein
   Executable oder Quellcode?
6. Was passiert beim Kompilieren und warum ist dieser Schritt vor dem Ausführen notwendig?
7. Was bewirken die Optionen (`-Wall`, `-Wextra`, `-Werror`, `-Wpedantic`, `-std=c18`, `-o s01e01`) beim
   `gcc`-Aufruf `gcc -Wall -Wextra -Werror -Wpedantic -std=c18 s01e01.c -o s01e01`?
8. Wie kann das beim Kompilieren generierte Executable `s01e01` ausgeführt werden?

### Hinweise

- Während des gesamten Proseminars wird eine funktionierende Linux-Distribution vorausgesetzt. Sie ersparen sich jede
  Menge Arbeit, wenn Sie bereits jetzt eine Version installieren. Sie Können alle Aufgaben auch in *Artemis* lösen. Es
  wird jedoch vorausgesetzt, dass Sie Programme auch selbst in der Kommandozeile kompilieren können.
- Sollten Sie keinen eigenen PC besitzen, gibt es die Möglichkeit, die Linux-Rechner in den Rechnerräumen der
  Universität zu nutzen.
- Der Befehl `man gcc` könnte hilfreich sein.
- Sie können das *Hello-World*-Programm mittels des
  Befehls `gcc -Wall -Wextra -Werror -Wpedantic -std=c18 s01e01.c -o s01e01` kompilieren.

# Aufgabe 2 (5 Punkte)

## Vorlesungsfolien

* Vorschau (EidP-02-Vorschau.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches überprüft, ob die Variable `value` vom Datentyp `int` größer als $`10`$ ist oder
nicht.

### Arbeitsschritte

Verwenden Sie das bereitgestellte Codefragment und führen Sie folgende Schritte durch:

- Weisen Sie der Variable `value` eine beliebige, von Ihnen gewählte Ganzzahl zu.
- Verwenden Sie eine `if`-Anweisung, um zu entscheiden, ob der Wert der Variable `value` größer als $`10`$ ist oder
  nicht.
- Sofern der von Ihnen gewählte Wert von `value` größer als $`10`$ ist, geben Sie mittels `printf` den
  Text `"value is greater than 10!"` aus.
- Sollte der Wert kleiner oder gleich $`10`$ sein, muss `"value is less than or equal to 10!"` ausgegeben werden.
- Nach der Ausgabe wird das Programm erfolgreich mit dem Rückgabewert `EXIT_SUCCESS` beendet.
- Bitte beachten Sie, dass aufgrund von Einschränkungen beim Testen in Artemis, die Variable `value` in diesem Programm
  nur einmal initialisiert und anschließend nicht mehr verändert werden darf!

### Beispielausgaben

Beispiel 1: `value = 35`

```text
value is greater than 10!
```

Beispiel 2: `value = 10`

```text
value is less than or equal to 10!
```

Beispiel 2: `value = -5`

```text
value is less than or equal to 10!
```

### Hinweise

- Testen Sie die Ausgabe Ihres Programms mit einigen verschiedenen Werten für die Variable `value`. Achten Sie dabei
  darauf, dass Sie die beiden in der Aufgabenstellung beschriebenen Fälle – d. h. Zahl ist größer als $`10`$ sowie
  kleiner oder gleich $`10`$ – abdecken.
- Verwenden Sie `if` und `printf`.
- Bei den Ein-/Ausgabetests wird beim Testen der Wert der Variable `value` in Ihrem Programm verändert!
- Artemis setzt beim Testen für die Variable `value` nur Werte zwischen $`-32767`$ und $`32767`$ – d h.
  $`-32767 \leq \mathtt{value} \leq 32767`$ – ein.
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!

# Aufgabe 3 (6 Punkte)

## Vorlesungsfolien

* Vorschau (EidP-02-Vorschau.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches berechnet wie viele Tage, Stunden und Minuten einem gewählten
Wert `chosen_minutes` in Minuten entsprechen.

### Arbeitsschritte

Verwenden Sie das bereitgestellte Codefragment und führen Sie folgende Schritte durch:

- Weisen Sie der Variable `chosen_minutes` eine beliebige, von Ihnen gewählte Ganzzahl zu.
- Berechnen der Werte für Tage, Stunden und Minuten und Ausgabe des
  Texts `"<chosen_minutes>m -> <days>d <hours>h <minutes>m"` auf der Standardausgabe, wobei der
  Platzhalter `<chosen_minutes>` mit der gewählten Zahl und die Platzhalter `<days>`, `<hours>` bzw. `<minutes>` mit den
  entsprechenden Werten für Tage, Stunden bzw. Minuten ersetzt werden.
- Nach der Ausgabe wird das Programm erfolgreich mit dem Rückgabewert `EXIT_SUCCESS` beendet.
- Bitte beachten Sie, dass aufgrund von Einschränkungen beim Testen in Artemis, die Variable `chosen_minutes` in diesem
  Programm nur einmal initialisiert und anschließend nicht mehr verändert werden darf!

### Beispielausgaben

Beispiel 1: `chosen_minutes = 60`

```text
60m -> 0d 1h 0m
```

Beispiel 2: `chosen_minutes = 1441`

```text
1441m -> 1d 0h 1m
```

Beispiel 3: `chosen_minutes = 3024`

```text
3024m -> 2d 2h 24m
```

### Hinweise

- Bei den Ein-/Ausgabetests wird beim Testen der Wert der Variable `chosen_minutes` in Ihrem Programm verändert!
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!

# Aufgabe 4 (5 Punkte)

## Vorlesungsfolien

* Vorschau (EidP-02-Vorschau.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches mithilfe einer `while`-Schleife den Text `Hello World!`  `n` mal untereinander auf
der Standardausgabe ausgibt.

### Arbeitsschritte

Verwenden Sie das bereitgestellte Codefragment und führen Sie folgende Schritte durch:

- Initialisieren Sie die Variable `n` mit dem Datentyp `int` mit einer beliebigen, von Ihnen gewählten Ganzzahl.
- Implementieren Sie die erforderliche Programmlogik mit einer `while`-Schleife.
- Bitte beachten Sie, dass aufgrund von Einschränkungen beim Testen in Artemis, die Variable `n` in diesem Programm nur
  einmal initialisiert und anschließend nicht mehr verändert werden darf!

### Beispielausgaben

Beispiel 1: `n = 3`

```text
Hello World!
Hello World!
Hello World!

```

Beispiel 2: `n = 5`

```text
Hello World!
Hello World!
Hello World!
Hello World!
Hello World!

```

Beispiel 3: `n = 0`

```text

```

## Hinweise

- Bei den Ein-/Ausgabetests wird beim Testen der Wert der Variable `n` in Ihrem Programm verändert!
- Artemis setzt beim Testen für die Variable `n` nur Werte zwischen $`0`$ und $`32767`$ – d. h.
  $`0 \leq \mathtt{value} \leq 32767`$ – ein.
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!

# Aufgabe 5 (10 Punkte)

## Beschreibung

Erstellen Sie ein C-Programm, welches mithilfe einer `while`-Schleife alle durch elf teilbaren Ganzzahlen zwischen $`0`$
und $`\mathtt{n} \leq 32767`$ (jeweils inklusive), d. h. $`\{t\in\{0, ..., \mathtt{n}\}\;:\;11|t\}`$, in absteigender Reihenfolge
untereinander ausgibt.

### Arbeitsschritte

Führen Sie folgende Arbeitsschritte aus:

- Initialisieren Sie eine Variable vom Datentyp `int` namens `n` mit einem beliebigen, von Ihnen gewählten Wert zwischen
  $`0`$ und $`32767`$, d. h. $`0 \leq \mathtt{n} \leq 32767`$.
- Implementieren Sie die erforderliche Programmlogik.
- Bitte beachten Sie, dass aufgrund von Einschränkungen beim Testen in Artemis, die Variable `n` in diesem Programm nur
  einmal initialisiert und anschließend nicht mehr verändert werden darf!

### Beispielausgabe für `n = 100`

```
99
88
77
66
55
44
33
22
11
0
```

### Hinweise

- Die angegebenen Grenzen für die Variable `n` sind als "weiche Grenzen" zu verstehen. Das heißt alle Werte im
  angegebenen Bereich müssen funktionieren, Werte außerhalb können funktionieren.
- Bei den Ein-/Ausgabetests wird beim Testen der Wert der Variable `n` in Ihrem Programm verändert!
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!
