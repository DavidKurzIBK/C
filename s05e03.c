#include <stdio.h>
#include <stdlib.h>

unsigned longest_sequence_set_bits(unsigned value) {
    unsigned longest = 0;
    unsigned current = 0;
    
    // value wird in dieser Schleife Bit-wise durchlaufen mit "&"
    // und die Anzahl der aufeinanderfolgenden Einsen gezählt mit current inkrementiert
    // könnte auch  while (value > 0) {if (value & 1) { ??? 
    // 
    while (value != 0) {
        if ((value & 1) == 1) {
            current++;
            if (current > longest) {
                longest = current;  // prüft ob anzahl der Einsen größer ist als bisher längste Folge, 
                // gespeichert in longest, falls der Fall, lonogest neu eingespeichert. 
            }
        } else {
            current = 0; // wenn 0 in Binärdarstellung auftritt, wird Zahl aufeinander 
            // folgenden Einsen current = 0 auf Null gesetzt.
        }
        value >>= 1; // Bit shift operator bewegt bits von value um position nach Rechts sodas nächste bit geprft. 
    }
    
    return longest;
}

int main(void) {
    printf("%u\n", longest_sequence_set_bits(0));    // output: 0
    printf("%u\n", longest_sequence_set_bits(2));    // output: 1
    printf("%u\n", longest_sequence_set_bits(6));    // output: 2
    printf("%u\n", longest_sequence_set_bits(27));   // output: 2
    printf("%u\n", longest_sequence_set_bits(31));   // output: 5
    return EXIT_SUCCESS;
}