#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int n;
    /* "unsigned short" für Variable n = 2048 ist zu klein zum speichern, deswegen unsigned int als Datentyp
    und h weg vom short datentyp*/
    if (!scanf("%u", &n)) {
        fprintf(stderr, "ERROR: The provided input could not be converted!\n");
        return EXIT_FAILURE;
    }
    unsigned count = 0;

    /*"unsigned char" für die Variable "i" ist besser unsigned int*/
    for (unsigned int i = 0; i < n; ++i) {
        /*die Schleife zählt Anzahl der Zahlen die durch 13 teilbar sind.. sollte "if (i % 13 != 0)" lauten???*/
        if (i % 13) {
            ++count;
        }
    }
    printf("count = %u\n", count);
    return EXIT_SUCCESS;
}

