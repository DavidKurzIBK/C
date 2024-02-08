#include <stdio.h>
#include <stdlib.h>


int min(int a, int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

// überprüft ob a kleiner oder gleich b -> dann a retourniert, 
// andernfalls wird b zurückgeg.

int max(int a, int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

// überprüft ob a größer oder gleich b -> dann a retourniert 
// andernfalls b zurück

int main(void){
    int a, b;
    
    // Test case 1: ausgabe und ausführung in einer Zeichenkette
    a = 0;
    b = 0;
    printf("a = %d, b = %d, min(a,b) = %d, max(a,b) = %d\n", a, b, min(a,b), max(a,b));
    
    // Test case 2
    a = -5;
    b = 5;
    printf("a = %d, b = %d, min(a,b) = %d, max(a,b) = %d\n", a, b, min(a,b), max(a,b));
    
    // Test case 3
    a = 13;
    b = 34;
    printf("a = %d, b = %d, min(a,b) = %d, max(a,b) = %d\n", a, b, min(a,b), max(a,b));
    

    return EXIT_SUCCESS;
}