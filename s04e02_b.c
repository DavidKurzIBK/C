#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned char n;
    if (!scanf("%u", &n)) {
        fprintf(stderr, "ERROR: The provided input could not be converted!\n");
        return EXIT_FAILURE;
    }
    unsigned long long sum = 0;
    /* long long datentyp verwenden für sehr große eingabewerte.
    wenn schleifen-variable i Null ist, auf unsigned char läuft,wird unendlich oft von Null subtrahiert und 0 zur summe
    addiert, deshalb i auf größer als Null*/
    for (unsigned char i = n; i > 0; --i) {
        sum += i;
    }
    printf("sum = %llu\n", sum); // hier ll für string verweden!!
    return EXIT_SUCCESS;
}
