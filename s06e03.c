#include <ctype.h> // benötigt für die isalpha-Funktion
#include <stddef.h> // benötigt für die size_t-Typdefinition
#include <stdlib.h>
#include <stdio.h>

size_t count_number_of_letters(char text[]) {
    size_t count = 0;
    for (int i = 0; text[i] != '\0'; i++) { // \0 ..null terminierungszeichen.
        if (isalpha(text[i])) {
            count++;
        }
    }
    return count;
}

/*isalpha-Funktion aus der ctype.h-Bibliothek um zu überprüfen, ob jedes Zeichen des Strings ein Buchstabe ist. 
isalpha gibt einen Wert ungleich Null zurück, wenn übergebene Zeichen ein Buchstabe ist, andernfalls gibt es Null zurück.
In der main-Funktion können Sie die count_number_of_letters-Funktion wie folgt testen:
*/


int main(void) {
char text1[] = "";
    printf("Anzahl der Buchstaben in '%s': %zu\n", text1, count_number_of_letters(text1));
    
    char text2[] = "0123456789";
    printf("Anzahl der Buchstaben in '%s': %zu\n", text2, count_number_of_letters(text2));
    
    char text3[] = "abcABC";
    printf("Anzahl der Buchstaben in '%s': %zu\n", text3, count_number_of_letters(text3));
    
    char text4[] = "a!B?";
    printf("Anzahl der Buchstaben in '%s': %zu\n", text4, count_number_of_letters(text4));
    
    char text5[] = "1a 2b 3c";
    printf("Anzahl der Buchstaben in '%s': %zu\n", text5, count_number_of_letters(text5));
    
    return EXIT_SUCCESS;
}
