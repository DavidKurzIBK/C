#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

//erforderlichen Header-Dateien werden eingefügt, um Funktionen wie Ein- und Ausgabeoperationen, Zeichenmanipulation und Ganzzahltypen zu unterstützen.

union DoubleBits {
    double d;
    uint64_t bits;
};

/* 
2. Eine Union mit dem Namen "DoubleBits" wird definiert, die aus einem double (d) und einem uint64_t (bits) besteht. 
Dies ermöglicht den Zugriff auf die Gleitkommazahl als Bitmuster.

3. Die Funktion "printBits" wird definiert, die die einzelnen Bits einer 64-Bit-Ganzzahl (uint64_t) ausgibt.

4. Die Funktion "printErrorMessage" wird definiert, um eine Fehlermeldung auszugeben, wenn die Eingabe keine gültige Gleitkommazahl ist.
*/

void printBits(uint64_t bits) {
    for(int i = 63; i >= 0; i--) {
        putchar((bits & (1ull << i)) ? '1' : '0');
        if(i == 63 || i == 52) putchar(' ');  // schreibt das übergebene Zeichen auf die Standardausgabe.
    }
    putchar('\n');
}

void printErrorMessage(const char* input, const char* extracted, const char* remaining) {
    fprintf(stderr, "ERROR: %s is not a valid double!\n", input);
    fprintf(stderr, "Extracted double component: %.6f\n", atof(extracted)); // str to double 
    fprintf(stderr, "Remaining: %s\n", remaining);
}

/*5. Die Hauptfunktion (main) wird definiert.

6. Es wird überprüft, ob mindestens ein Kommandozeilenargument angegeben wurde. 
Wenn nicht, wird eine Fehlermeldung ausgegeben, die das korrekte Verwendungsmuster angibt, und das Programm wird beendet.

7. Die Funktion "strtod" wird verwendet, um das erste Kommandozeilenargument in eine Gleitkommazahl (double) umzuwandeln. 
Der Zeiger "endptr" wird verwendet, um den Teil der Eingabe zu speichern, der nicht zur Zahl gehört.

8. Wenn "endptr" auf denselben Wert wie "argv[1]" zeigt, bedeutet dies, dass keine gültige Gleitkommazahl eingegeben wurde. 
In diesem Fall wird eine Fehlermeldung ausgegeben, die die ursprüngliche Eingabe, die extrahierte Zahl (0.000000) und den 
restlichen Teil der Eingabe enthält. Das Programm wird dann beendet.

9. Wenn "endptr" nicht auf das Ende der Eingabe zeigt, bedeutet dies, dass die Eingabe eine Teilzahl enthält, 
die als gültige Gleitkommazahl interpretiert wurde, gefolgt von zusätzlichen Zeichen. 
In diesem Fall wird die Teilzahl und der restliche Teil der Eingabe in einer Fehlermeldung ausgegeben. Das Programm wird dann beendet.

10. Eine Instanz der Union "DoubleBits" wird erstellt und mit der eingegebenen Gleitkommazahl initialisiert.

11. Die eingegebene Zahl wird ausgegeben, gefolgt von ihrer binären Darstellung.

12. Die einzelnen Komponenten der binären Darstellung (Vorzeichen, Exponent und Mantisse) werden extrahiert und 
in einem bestimmten Format ausgegeben.
*/

int main(int argc, char** argv) {
    if(argc < 2) {
        fprintf(stderr, "usage: %s <double>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* endptr;
    double input = strtod(argv[1], &endptr); // ascii-str to double

    if(endptr == argv[1]) {
        printErrorMessage(argv[1], "0.000000", argv[1]);
        return EXIT_FAILURE;
    }

    if(*endptr != '\0') {
        char extracted[32];
        strncpy(extracted, argv[1], endptr - argv[1]); // copies first char nums of a string
        extracted[endptr - argv[1]] = '\0';
        printErrorMessage(argv[1], extracted, endptr);
        return EXIT_FAILURE;
    }

    union DoubleBits bits = { .d = input };

    printf("Number: %.6e\n", input);
    printf("Binary representation:\n");
    printf("   %ld ", (bits.bits >> 63) & 1);

    int exponent = (bits.bits >> 52) & 0x7ff;
    //int sign = (bits.bits >> 63) & 1;
    uint64_t mantissa = bits.bits & 0xfffffffffffff;

    for(int i = 10; i >= 0; i--) {
        putchar(((exponent & (1 << i)) ? '1' : '0'));
    }
    putchar(' ');

    for(int i = 51; i >= 0; i--) {
        putchar(((mantissa & (1ull << i)) ? '1' : '0'));
    }
    putchar('\n');

    //printf("%s %d %lu\n", (sign == 1) ? "1" : "0", exponent - 1023, mantissa);
    printf("sign    exponent                                             mantissa\n");

    return EXIT_SUCCESS;
}


/* 
Zusammenfassend liest dieser Code eine Gleitkommazahl (double) aus den Kommandozeilenargumenten ein und gibt ihre 
binäre Darstellung sowie einige Informationen über die Komponenten der Gleitkommazahl aus



13. Das Programm wird erfolgreich beendet (EXIT_SUCCESS).

.
*/