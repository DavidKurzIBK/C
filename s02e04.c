#include <stdio.h>
#include <stdlib.h>



int main(void) {
    int number, digit;
    if (scanf("%d", &number) != 1) {
        printf("ERROR: While reading the 'int' value an error occurred!");
        return EXIT_FAILURE;
    }
    printf("\n");
    printf("input:  %d\noutput: ", number);
    
    while (number > 0) {
        digit = number % 10;
        number /= 10;
        printf("%d", digit);
    }

    printf("\n");

    
    return EXIT_SUCCESS;
}


/*Zuerst wird die Ganzzahl number eingelesen, die vom Benutzer eingegeben wird. 
Dann wird eine while-Schleife verwendet, um die Ziffern in umgekehrter Reihenfolge auszugeben. 
In jeder Schleifeniteration wird der Rest der Division durch 10 berechnet und ausgegeben, 
und number wird durch 10 geteilt, um zur nächsten Ziffer zu gelangen. Die Schleife wird ausgeführt, 
bis alle Ziffern ausgegeben wurden, d.h. number gleich 0 ist.*/