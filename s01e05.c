#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 32767; 
    
    int t = n / 11 * 11;
    while (t >= 0) {
        printf("%d\n", t);
        t -=11;
    }
    return EXIT_SUCCESS;
}


/*
1. n initialisiert,
2. t initialisiert als die nächstkleinere durch elf teilbare Zahl von n: n / 11 * 11.
2. while-Schleife gibt die durch elf teilbaren Zahlen in 
absteigender Reihenfolge aus, beginnt mit t und wird pro schleife 
um 11 verringert, bis t Null ist.
*/