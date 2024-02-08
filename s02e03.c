#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int a, b, c, max, min;
    //int a, b, c;
    // Eingabe von a, b und c durch den Benutzer
    scanf("%d %d %d", &a, &b, &c);

    // Vergleiche von a, b und c, um das Maximum und Minimum zu finden
    if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }

    if (a <= b && a <= c) {
        min = a;
    } else if (b <= a && b <= c) {
        min = b;
    } else {
        min = c;
    }

    /* int min = a, max = a;
    if (b < min) {
        min = b;
    } else if (b > max) {
        max = b;
    }
    if (c < min) {
        min = c;
    } else if (c > max) {
        max = c;
    }*/



    // Ausgabe des Maximums und Minimums
    printf("%d\n%d\n%d\n",a, b, c);
    printf("\nmin = %d\nmax = %d\n", min, max);

    return EXIT_SUCCESS;
}

/*
Zuerst werden die Variablen a, b und c als Ganzzahlwerte eingelesen, 
die vom Benutzer eingegeben werden. Dann wird jedes Paar von Variablen
mit if-Verzweigungen verglichen, um das Maximum und Minimum zu finden. 
Schließlich werden das Maximum und Minimum ausgegeben.
*/