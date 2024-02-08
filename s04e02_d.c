#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned height = 10;
    
    
    for (unsigned i = 1; i <= height; i += 3) {
        for (unsigned j = 1; j <= height;  j++) {
            printf(" %c", height - j >= i ? ' ' : '#');
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}

/*Das Ergebnis wird für jede i-Zeile mit j-Spalten gedruckt, wobei der j-Zähler für jede i-Zeile zurückgesetzt wird.*/