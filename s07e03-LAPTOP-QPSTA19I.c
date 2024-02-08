#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

bool safe_add(const int *x, const int *y, int *result) {
    if (x == NULL || y == NULL || result == NULL) {   // "||" logisches oder
        return false;
    }
    // überlauf
    if (*x > 0 && *y > INT_MAX - *x) {
        return false;
    }
    // Unterlauf
    if (*x < 0 && *y < INT_MIN - *x) {    // "&&" logisches und
        return false;
    }
    *result = *x + *y;
    return true;
}


/*
Die Funktion prüft ob einer der drei Zeiger NULL ist. 
Wenn der Fall ist, false zurückgegeben.

Anschließend Über- und Unterlaufbedingungen überprüft. 
Wenn *y größer als INT_MAX - *x wäre, aber *x positiv ist, oder wenn *y größer als INT_MIN - *x wäre, 
aber *x negativ ist, würde ein Überlauf bzw. ein Unterlauf auftreten. In diesem Fall wird false zurückgegeben.

Wenn keine dieser Bedingungen erfüllt, wird die Summe von *x und *y berechnet und in den Speicherbereich gespeichert, auf den result zeigt. 
Schließlich wird true zurückgegeben.

*/



int main() {
    int x = 10;
    int y = 20;
    int result;
    
    if (safe_add(&x, &y, &result)) {
        printf("%d + %d = %d\n", x, y, result);
    } else {
        printf("Error: addition failed.\n");
    }
    
    int a = INT_MAX;
    int b = 1;
    
    if (safe_add(&a, &b, &result)) {
        printf("%d + %d = %d\n", a, b, result);
    } else {
        printf("Error: addition failed.\n");
    }
    
    int *ptr = NULL;
    
    if (safe_add(&x, ptr, &result)) {
        printf("%d + %d = %d\n", x, *ptr, result);
    } else {
        printf("Error: addition failed.\n");
    }
    
    return EXIT_SUCCESS;
}

