#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    char start, end;
    scanf("%c-%c", &start, &end);
    
    printf("\n");
    
    if (start < 'a' || start > 'z' || end < 'a' || end > 'z') {
        printf("ERROR: At least one input was not a lowercase letter!\n");
        exit(EXIT_FAILURE);
    } 
    

    if (start > end) {
        char temp = start;
        start = end;
        end = temp;
        for (char c = end; c >= start; c--) {
        printf("%c\n", c);
        }
    }
    
    else {
        for (char c = start; c <= end; c++) {
        printf("%c\n", c);
        }
    }
    
    
    return EXIT_SUCCESS;
}


/*1. Eingabe des Benutzers einlesen & prüfen, ob gültig. 
2. mind. eines der eingegebenen Zeichen nicht zw. 'a' und 'z', 
Programm gibt Fehlermeldung aus und beendet.
3. Eingabe gültig: alle Buchstaben zw. beiden eingegebenen 
in auf/absteig. Reihenfolge ausgegeben, zuvor überprüft welcher Buchstabe zuerst kommt.*/