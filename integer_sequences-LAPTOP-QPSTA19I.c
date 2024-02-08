#include <stdio.h>
#include <stdlib.h>
#include "integer_sequences.h"

// generiert die Fibonacci-Folge bis zur angegebenen Anzahl von Elementen n. 
// Die Funktion gibt einen Zeiger auf ein Integer-Array zurück, das die Fibonacci-Folge enthält.
int *fibonacci(int n) { // Zuerst wird überprüft, ob der übergebene Wert n kleiner oder gleich 0 ist. 
    if (n <= 0) {
        return NULL; // In diesem Fall wird NULL zurückgegeben, um anzuzeigen, dass die Eingabe ungültig ist
    }
    // Andernfalls wird Speicher für ein Integer-Array der Größe n mit malloc reserviert. 
    // Wenn die Speicherzuweisung fehlschlägt, wird ebenfalls NULL zurückgegeben.
    int *sequence = (int *)malloc(n * sizeof(int));
    if (sequence == NULL) {
        return NULL;
    }
    // erste Element der Sequenz wird auf 0 gesetzt. Wenn n größer als 1 ist, wird das zweite Element auf 1 gesetzt
    sequence[0] = 0;
    if (n > 1) {
        sequence[1] = 1;
    }

    // Schleife wird gestartet, die bei 2 beginnt und bis n-1 läuft. 
    // In jeder Iteration wird das aktuelle Element der Sequenz als die Summe der beiden vorherigen Elemente berechnet und in das Array eingefügt
    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
    // generierte Array zurückgegeben;
    return sequence;
}


// ähnlich fibonacci: überprüfen ebenfalls, ob n kleiner oder gleich 0 ist und geben in diesem Fall NULL zurück. 
// Sie reservieren Speicher für ein Integer-Array der Größe n und initialisieren die Sequenz entsprechend.
int *odd_numbers(int n) {
    if (n <= 0) {
        return NULL;
    }

    int *sequence = (int *)malloc(n * sizeof(int));
    if (sequence == NULL) {
        return NULL;
    }

    int number = 1;
    for (int i = 0; i < n; i++) {
        sequence[i] = number;
        number += 2;
    }

    return sequence;
}



// ähnlich fibonacci: überprüfen ebenfalls, ob n kleiner oder gleich 0 ist und geben in diesem Fall NULL zurück. 
// Sie reservieren Speicher für ein Integer-Array der Größe n und initialisieren die Sequenz entsprechend
int *even_numbers(int n) {
    if (n <= 0) {
        return NULL;
    }

    int *sequence = (int *)malloc(n * sizeof(int));
    if (sequence == NULL) {
        return NULL;
    }

    int number = 0;
    for (int i = 0; i < n; i++) {
        sequence[i] = number;
        number += 2;
    }

    return sequence;
}

// überprüft, ob übergebene Zeiger sequence NULL ist. In diesem Fall wird die Funktion beendet. 
// Ansonsten Schleife gestartet, die jedes Element der Sequenz ausgibt. 
// Ein Komma und ein Leerzeichen werden zwischen den Elementen ausgegeben, außer beim letzten Element, dann neue Zeile gedruckt.
void print_integer_sequence(const int *sequence, int n) {
    if (sequence == NULL) {
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("%d", sequence[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("\n");
}
