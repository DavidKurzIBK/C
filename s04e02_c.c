#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i = 1;
    while (i <= 20) {
        if (!(i % 2)) {
            i++;
            continue;
        }
        printf("%d\n", i);
        i++;
    }
    return EXIT_SUCCESS;
}

/*while-Schleife wird ausgeführt solange die Bedingung "i <= 20" wahr ist, 
Zuerst wird geprüft, ob i gerade ist -> wenn ja wird i erhöht und der Schleifendurchlauf fortgesetzt. 
Andernfalls wird die ungerade Zahl i ausgegeben und um eins erhöht.
Zahlen von 1 bis 19 in aufsteigender Reihenfolge, wobei alle geraden Zahlen ausgelassen werden.*/