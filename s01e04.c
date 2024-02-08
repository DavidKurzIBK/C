#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 5, i = 0; 
    
    while (i < n){
        printf("Hello World!\n");
        i++;
    }
    return EXIT_SUCCESS;
}

/*
1. Variable n deklariert: gibt Anzahl der Wiederholungen an 
2. Variable i als Zähler deklariert: wird pro Schleifendurchlauf um 1 erhöht
damit Schleife genau n-mal durchlaufen wird, solange eben i < n ist 
3. Schleife mit printf gibt n-mal "Hello World!" untereinander aus
*/