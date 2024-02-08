# Aufgabe 1 (8 Punkte)

## Vorlesungsfolien

* Zeiger (EidP-08-Zeiger.pdf)

## Beschreibung

Gegeben ist folgender Ausschnitt des (fiktiven) Arbeitsspeichers eines Rechners, wobei links die Speicheradresse und
rechts der Inhalt des Bytes an dieser Speicheradresse steht.

| Speicheradresse | Inhalt (Binär) |
|----------------:|---------------:|
|             ... |            ... |
|              30 |     `00011010` |
|              31 |     `01100001` |
|              32 |     `00101000` |
|              33 |     `00101100` |
|              34 |     `01100011` |
|              35 |     `00111110` |
|              36 |     `01100000` |
|              37 |     `01101001` |
|              38 |     `00011011` |
|              39 |     `01011011` |
|              40 |     `01111010` |
|              41 |     `00010000` |
|              42 |     `00010111` |
|              43 |     `00100001` |
|              44 |     `00000001` |
|              45 |     `00001111` |
|              46 |     `00100100` |
|              47 |     `01101011` |
|              48 |     `00100101` |
|              49 |     `00011001` |
|             ... |            ... |

Beantworten Sie die nachfolgenden Fragen und füllen Sie alle Zeilen in der Tabelle `s07e01.txt` aus, bei welchen die
Speicheradresse oder der Inhalt dieser Zeile verwendet wird. Sofern notwendig, können Sie in der Tabelle Zellen
verbinden.

Für die Bestimmung des Dezimalwerts von mehreren zusammenhängenden Speicheradressen wird angenommen, dass der Rechner
das [höchstwertige Byte zuerst](https://en.wikipedia.org/wiki/Endianness), d. h. an der kleinsten Speicheradresse,
speichert. Gehen Sie weiters davon aus, dass sowohl der Datentyp `int` als auch Zeiger $`8`$ Bit und der
Datentyp `long int` $`16`$ Bit groß ist.

1. Die Variable `int a` liegt auf Speicheradresse $`47`$.
    - Was gibt `printf("%d", a)` aus?
2. Gegeben sei die Variable `int b`. Der Befehl `printf("%d", b)` gibt `62` aus.
    - Was wird für `printf("%p", &b)` ausgeben?
3. Der Zeiger `int *pc` liegt auf Speicheradresse $`48`$.
    - Auf welche Speicheradresse verweist der Zeiger `pc`?
    - Was wird bei `printf("%p", &pc)` ausgegeben?
    - Was wird bei `printf("%d", *pc)` ausgegeben?
4. Gegeben sei der Zeiger `int *pd`. Der Befehl `printf("%d", *pd)` gibt `96` aus.
    - Auf welche Speicheradresse verweist der Zeiger `pd`?
    - An welcher Speicheradresse liegt der Zeiger?
5. Der Zeiger `long int *pe` liegt auf der Speicheradresse $`32`$.
    - Welche Länge in Bytes hat der Zeiger `pe`.
    - Welche Länge hat der Speicherbereich, auf den er verweist?
    - Was gibt der Befehl `printf("%ld", *pe)` aus?
6. Der Zeiger `int **ppf` liegt auf der Speicheradresse $`43`$.
    - Was wird für `printf("%p", &ppf)` ausgegeben?
    - Was wird für `printf("%p", ppf)` ausgegeben?
    - Was wird für `printf("%p", *ppf)` ausgegeben?
    - Was wird für `printf("%d", **ppf)` ausgegeben?

### Hinweise

- Auf realen Systemen schreibt der C-Standard vor, dass der Datentyp `int` bzw. `long int` eine Minimalgröße von $`16`$
  bzw. $`32`$ Bit haben muss! Die Annahme, dass der Datentyp `int` $`8`$ Bit und der Datentyp `long int` $`16`$ Bit
  lang ist, wird hier zugunsten der Lesbarkeit getroffen.

# Aufgabe 2 (8 Punkte)

## Vorlesungsfolien

* Zeiger (EidP-08-Zeiger.pdf)

## Beschreibung

Implementieren Sie eine Funktion mit der Signatur `int most_frequent_letter(const char *text)`, welche den kleinsten
(Array-)Index von dem Buchstaben des [lateinischen Alphabets](https://en.wikipedia.org/wiki/Latin_alphabet), d. h. „a“,
„b“, …, „z“, „A“, „B“, …, „Z“, mit der größten Häufigkeit im String `text` zurückgibt.

Berücksichtigen Sie für Ihre Implementierung die folgenden Regeln:

1. Die Groß- und Kleinschreibung der Buchstaben ist nicht von Bedeutung.
2. Gibt es mehrere Buchstaben mit der gleichen größten Häufigkeit, wird die Ordnung im Alphabet berücksichtigt, d. h.
   der Index des Buchstabens mit der größten Häufigkeit, welcher zuerst im Alphabet vorkommt, wird zurückgegeben.
3. Bei einem leeren String `text` oder einem String ohne Buchstaben des lateinischen Alphabets wird der Wert `-1`
   zurückgegeben.

Testen Sie Ihre `most_frequent_letter`-Implementierung in der `main` -Funktion mit einigen Beispielaufrufen.

## Beispiele

|    `text` | `most_frequent_letter(text)` |
|----------:|-----------------------------:|
|   "hello" |                            2 |
|   "abcde" |                            0 |
|   "accbb" |                            3 |
| "b B a A" |                            4 |
|     ".;:" |                           -1 |

# Aufgabe 3 (6 Punkte)

## Vorlesungsfolien

* Zeiger (EidP-08-Zeiger.pdf)

## Beschreibung

Implementieren Sie in der Datei `s07e03.c` die Funktion mit der Signatur
`bool safe_add(const int *x, const int *y, int *result)`, welche die durch die Zeiger `x` und `y` referenzierten Werte
addiert. Sofern mindestens einer der drei Zeiger `x`, `y`, `result` ein `NULL`-Pointer ist oder beim Summieren ein
Überlauf oder ein Unterlauf auftreten würde, wird die Addition nicht durchgeführt und die Funktion gibt `false` zurück.
In jedem anderen Fall wird das berechnete Ergebnis in den Speicherbereich, auf welchen `result` zeigt, gespeichert und
der Wert `true` retourniert.

Testen Sie Ihre `safe_add`-Implementierung in der `main`-Funktion mit einigen Beispielaufrufen.

# Aufgabe 4 (8 Punkte)

## Vorlesungsfolien

* Arrays (EidP-07-Arrays.pdf)
* Zeiger (EidP-08-Zeiger.pdf)

## Beschreibung

In dieser Aufgabe soll mit einem Debugger gearbeitet werden. In der ersten Teilaufgabe sollen Sie sich mit dem
Debugger [`gdb`](https://en.wikipedia.org/wiki/GNU_Debugger)  vertraut machen. Im Folgenden sollen bestimmte Tätigkeiten
im `gdb`-Debugger ausgeführt werden. Abschließend soll ein fehlerhaftes Programm, basierend auf den Erkenntnissen aus
den ersten beiden Teilaufgaben, mit dem Debugger analysiert und korrigiert werden.

### Teilaufgabe a)

Beantworten Sie folgende Fragen in der Textdatei `s07e04_a.txt`:

1. Was ist debuggen?
2. Was ist ein Debugger?
3. Was bewirkt die Option, d. h. Flag, `-g`, welche beim Kompilieren verwendet werden kann?
4. Wie kann das Executable `my_executable` mit dem `gdb`-Debugger ausgeführt werden, wenn ein Programm bereits zu dem
   Executable `my_executable` kompiliert wurde?
5. Erklären Sie die Befehle `run`, `breakpoint`, `cond`, `continue`, `next`, `step`, `print` und `watch` des `gdb`
   -Debuggers.

### Teilaufgabe b)

Gegeben sei folgendes Programm.

```c
#include <stdlib.h>

void do_something(int my_array[], size_t my_length) {
    for (size_t i = 0; i < my_length; ++i) {
        my_array[i] *= 2;
    }
}

int main(void) {
    int my_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    do_something(my_array, 9);
    return EXIT_SUCCESS;
}
```

Geben Sie in der Datei `s07e04_b.txt` die `gdb`-Befehle an, mit welchen die folgenden Tätigkeiten mit dem `gdb`-Debugger
ausgeführt werden können:

1. Setzen Sie einen Breakpoint in der Funktion `do_something`.
2. Starten Sie die Ausführung.
3. Geben Sie die Werte von allen Parametern aus.
4. Setzen Sie einen weiteren Breakpoint vor der ersten Anweisung im `for`-Schleifenrumpf in der Funktion `do_something`.
   Dieser Breakpoint soll nur aktiv werden, sofern die Bedingung `i > 7` erfüllt ist.
5. Führen Sie die Ausführung bis zum nächsten Breakpoint fort.
6. Geben Sie den Wert der Laufvariable `i` und alle Elemente des Arrays `my_array` aus.
7. Beenden Sie das Debugging.

### Teilaufgabe c)

```c
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int cmp(int x, int y) {
    if (x < y) {
        return 1;
    } else if (x > y) {
        return 0;
    } else {
        return -1;
    }
}

void bubblesort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n; j >= i; j--) {
            if (cmp(a[j], a[j - 1]) < 0)
                swap(&a[j], &a[j - 1]);
        }
    }
}

int main(void) {
    int a[] = {5, 10, 11, 9, 7, 8, 4, 5, 7, 2, 45, 1, 4, 20};
    int n = sizeof(a) / sizeof(*a);
    bubblesort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}

```

Dieses Programm sollte ein Array aufsteigend sortieren, ist aber fehlerhaft. Finden Sie die fehlerhaften Stellen und
korrigieren Sie diese. Verwenden Sie dazu auch den `gdb`-Debugger. Geben Sie in der Datei `s07e04_c.txt` für jedes
Problem an, in welcher Zeile bzw. in welchem Bereich das Problem liegt und mit welchen `gdb`-Befehlen Sie das Problem
gefunden haben.

### Hinweise

- Eine kurze Einführung für das Arbeiten mit dem `gdb`-Debugger finden Sie beispielsweise
  [hier](https://sourceware.org/gdb/current/onlinedocs/gdb/Sample-Session.html#Sample-Session) oder
  [hier](http://www.unknownroad.com/rtfm/gdbtut/gdbinfloop.html).
- Sofern Ihr Rechner `gdb` – wie beispielsweise bei Macs
  mit [Apple Silicon](https://en.wikipedia.org/wiki/Apple_silicon) – nicht unterstützt, können Sie diese Aufgabe mit
  Ihrem Linux-Account in den Rechnerräumen oder am
  [zid-gpl](https://www.uibk.ac.at/zid/systeme/linux/lpccs_4/benutzeranleitung_zid-gpl) lösen.
