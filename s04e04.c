#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int height;
    printf("height: ");
    if (scanf("%d", &height) != 1 || height < 0) {
        printf("Ungültige Höhe!\n");
        return EXIT_FAILURE;
    }
    printf("\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }
        printf("x");
        for (int j = 0; j < 2 * i - 1; j++) {
            printf(" ");
            if (j != 2 * i - 2 && i != height - 1) {
                printf(" ");
            } else {
                printf("x");
            }
        }
        if (i != height - 1) {
            printf("\n");
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}

/*Das Programm fragt den Benutzer nach der Höhe des Dreiecks und 
prüft, ob die Eingabe gültig ist und ob die Höhe negativ ist. 
Dann gibt es das Dreieck entsprechend der angegebenen Höhe aus. 
Das Dreieck besteht aus Sternchen (*), und jede Zeile enthält eine zusätzliche Sternchen als die vorherige. 
Beachten Sie, dass die Ausgabe des Dreiecks direkt nach der Eingabe 
des Benutzers erfolgt, ohne zusätzliche Eingabeaufforderungen.*/

