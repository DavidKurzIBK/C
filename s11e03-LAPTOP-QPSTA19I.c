// erzeugt also die Fibonacci-Folge und eine Folge von ungeraden Zahlen und gibt sie aus, basierend auf dem Wert n, der als Befehlszeilenargument übergeben wird

#include <stdio.h>
#include <stdlib.h>
#include "integer_sequences.h"
#include "integer_sequences.c"

// Programm überprüft, ob Anzahl der übergebenen Argumente (argc) ungleich 2 ist. 
// Wenn dies der Fall ist, wird eine Fehlermeldung ausgegeben, die den korrekten Gebrauch des Programms erklärt. 
// Dann wird das Programm mit dem Wert 1 beendet, was auf einen Fehler hinweist
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: %s <n>\n", argv[0]); // Anzahl der Argumente korrekt ist, wird das erste Argument (argv[0]) verwendet, um den Namen des Programms auszugeben.
        return 1;
    }

    int n = atoi(argv[1]); // zweite Argument (argv[1]) wird in Ganzzahl (n) umgewandelt. Die Funktion atoi verwendet, um Zeichenkette (char) in eine Ganzzahl zu konvertieren
    if (n <= 0) {
        printf("error: n may not be negative\n"); // überprüft, ob n kleiner oder gleich 0 ist. Wenn Fall, wird eine Fehlermeldung ausgegeben, dass n nicht negativ sein darf.
        return 1;
    }

    // Zwei Zeiger (fib und odd) werden deklariert zu speicherung der erzeugten Integer-Folgen:
    // fibonacci(n) und odd_numbers(n) aufgerufen, um Fibonacci-Folge und Folge der ungeraden Zahlen zu generieren. 
    // Diese Funktionen verwenden den Wert n, um die Folgen entsprechend der übergebenen Größe zu erzeugen.
    int *fib = fibonacci(n);
    int *odd = odd_numbers(n);

    // Speicherzuweisung fib und odd erfolgreich war. 
    // Wenn einer der Zeiger NULL ist, was bedeutet, dass die Speicherzuweisung fehlgeschlagen ist, 
    // wird eine Fehlermeldung ausgegeben und das Programm wird mit dem Wert 1 beendet.
    if (fib == NULL || odd == NULL) {
        printf("error: Failed to allocate memory\n");
        return 1;
    }

    // zweimal aufgerufen, einmal für fib und einmal für odd. Diese Funktion gibt die erzeugten Integer-Folgen aus
    //printf("%d", n);
    print_integer_sequence(fib, n);

    //printf("%d", n);
    print_integer_sequence(odd, n);

    // allokierte Speicher für fib und odd wird freigegeben, um Speicherlecks zu vermeiden
    free(fib);
    free(odd);

    return 0;
}
