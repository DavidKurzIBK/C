#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>


int main() {
    uint32_t value;
    printf("value: ");
    scanf("%" SCNu32, &value);
    printf("\n");

    uint32_t temp = value;
    int zeros = 0;
    while (temp != 0) {
        if ((temp & 1) == 0) {
            zeros++;
        }
        temp >>= 1;
    }

    if (value == 0){
        printf("The number %" PRIu32 " contains 1 zero in the significant digits of the binary representation!\n", value);
        printf("\n");
        return EXIT_SUCCESS;
    }
    if (zeros == 1) {
        printf("The number %" PRIu32 " contains 1 zero in the significant digits of the binary representation!\n", value);
    } else {
        printf("The number %" PRIu32 " contains %d zeros in the significant digits of the binary representation!\n", value, zeros);
    }

    return EXIT_SUCCESS;
}


/* 1. Einlesen einer Dezimalzahl value und ermitteln der Anzahl der Nullen 
der signifikanten Stellen der Binärrepräsentation von value. 
Eine Schleife überprüft die Bits von value von rechts nach links. 
Wenn ein Bit = 0 ist, wird Zähler zeros um 1 erhöht.

Ausgegeben wird entweder: value hat genau eine Null in den signifikanten Stellen der Binärrepräsentation oder
value hat keine oder mehr als eine Null.

Header inttypes.h inkludieren um value mit scanf einzulesen und den Formatstring "%" SCNu32 verwenden. 
Um value mit printf auszugeben, muss der Formatstring "%" PRIu32 für uint32_t-Variablen verwendet werden.*/
