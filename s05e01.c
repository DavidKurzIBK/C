#include <stdio.h>
#include <stdlib.h>

/*Programm kompiliert nicht, da f2() vor ihrer Deklaration in f1() aufgerufen wird.

Compiler erkennt Aufruf von f2() in f1() nicht und gibt deshalb eine Fehlermeldung aus.
Fehler beheben: f2() vor f1() stehen.
*/

unsigned f2(unsigned a);
unsigned f1(unsigned a, unsigned b) {
    if (a < b) {
        return a + b;
    }
    return f2(a - b);
}

unsigned f2(unsigned a) { return f1(a >> 1, 5); } // shift operator der Bits von a um 1 stelle nach rechts
// verschiebt mit dem festen argument 5

int main(void) {
    printf("%u\t%u\n", f1(1, 2), f2(3)); // %u 2 vorzeichenlose ganzzahlen durch tabulator separiert. 
    printf("%u\t%u\n", f1(4, 5), f2(6));
    return EXIT_SUCCESS;
}
