#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int n, sum = 0;
    printf("Geben Sie eine positive Ganzzahl ein: ");
    scanf("%u", &n);
    printf("\n");

    // Berechne die Summe aller Teiler von n
    for (unsigned int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    // Überprüfe, ob die Summe der Teiler gleich n ist
    if (sum == n) {
        printf("The number %u is a perfect number!\n", n);
    } else {
        printf("The number %u is not a perfect number!\n", n);
    }

    return EXIT_SUCCESS;
}

/*
1. Zahl n vom Benutzer einlesen und rechnet Summe aller Teiler von n. 
Wenn Summe = n: Ausgabe: n ist eine vollkommene Zahl.
Sonstige Ausgabe: n keine vollkommene Zahl.

Wenn eine Variable möglicherweise nicht initialisiert wurde ist Summe der Teiler. Dann n keine Teiler hat und  
initialisieren die Variable sum auf 0, um eine mögliche Kompiler-Warnung zu vermeiden.*/