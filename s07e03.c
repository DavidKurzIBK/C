#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

bool safe_add(const int *x, const int *y, int *result) {
    if (x == NULL || y == NULL || result == NULL) {
        return false;
    }
    if (*x > 0 && *y > INT_MAX - *x) {
        return false;
    }
    if (*x < 0 && *y < INT_MIN - *x) {
        return false;
    }
    *result = *x + *y;
    return true;
}


/*
Die Funktion prüft zuerst, ob einer der drei Zeiger NULL ist. 
Wenn dies der Fall ist, wird false zurückgegeben.

Anschließend werden Über- und Unterlaufbedingungen überprüft. 
Wenn die Summe von *x und *y größer als INT_MAX wäre, aber *x positiv ist, oder wenn die Summe kleiner als INT_MIN wäre, 
aber *x negativ ist, würde ein Überlauf oder ein Unterlauf auftreten. In diesem Fall wird false zurückgegeben.

Wenn keine dieser Bedingungen erfüllt ist, wird die Summe von *x und *y berechnet und in den Speicherbereich gespeichert, auf den result zeigt. 
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

