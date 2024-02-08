#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int height, i, j;

    printf("height: ");
    if (scanf("%d", &height) != 1 || height < 0) {
        printf("Ungültige Höhe!\n");
        return EXIT_FAILURE;
        }
    printf("\n");

    for (i = 1; i <= height; i++) {
        for (j = 1; j <= i; j++) {
            printf("%2d", j);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}

/*Das Programm liest die Höhe von der Standardausgabe ein und überprüft, ob die Eingabe gültig ist. 
Wenn die Eingabe ungültig ist, wird eine Fehlermeldung ausgegeben und das Programm beendet.

Ansonsten wird die Zifferntreppe mithilfe von zwei 
ineinander verschachtelten Schleifen generiert und auf der Standardausgabe ausgegeben. 
Jede Zahl wird mit einer Mindestbreite von zwei Stellen ausgegeben.*/