#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int most_frequent_letter(const char *text) {
        // Speicher für Zähler-Array allozieren und initialisieren
    int *count = (int*) calloc(26, sizeof(int));
    if (count == NULL) {
        // Fehler: Speicher konnte nicht alloziert werden
        return -1;
    }
    // Zähler-Array mit Buchstaben-Häufigkeiten füllen
    for (const char *p = text; *p != '\0'; p++) {
        if (isalpha(*p)) {
            count[tolower(*p) - 'a']++;
        }
    }
    // Index des Buchstabens mit der größten Häufigkeit suchen
    int max_index = -1;
    int max_count = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > max_count) {
            max_index = i;
            max_count = count[i];
        }
    }
    // Speicher für Zähler-Array freigeben
    free(count);
    // Wenn kein Buchstabe im Text gefunden wurde, -1 zurückgeben
    if (max_index == -1) {
        return -1;
    }
    // Index des Buchstabens mit der größten Häufigkeit im Original-Alphabet berechnen
    char most_frequent_letter = max_index + 'a';
    if (max_index >= 13) {
        most_frequent_letter += 'A' - 'a';
    }
    return strchr(text, most_frequent_letter) - text;
    
}


/*Die Funktion alloziert Speicher für ein Zähler-Array mit 26 Elementen, 
eines für jeden Buchstaben im lateinischen Alphabet. 
Es durchläuft den Eingabetext und erhöht den Zähler für jeden Buchstaben im Zähler-Array. 
Dann durchläuft es das Zähler-Array, um den Index des Buchstabens mit der größten Häufigkeit zu finden. 
Schließlich gibt es den kleinsten Index des am häufigsten vorkommenden Buchstabens im Eingabetext zurück.

Die Funktion nutzt die Standardbibliotheks-Funktionen calloc, isalpha, tolower, free und strchr. 
Die calloc-Funktion wird verwendet, um Speicher für das Zähler-Array zu allozieren und mit Nullen zu initialisieren. 
isalpha wird verwendet, um zu überprüfen, ob ein Zeichen ein lateinischer Buchstabe ist. tolower wird verwendet, 
um Großbuchstaben in Kleinbuchstaben umzuwandeln. free wird verwendet, um den Speicher des Zähler-Arrays freizugeben, 
nachdem er nicht mehr benötigt wird. strchr wird verwendet, um den Index des am häufigsten vorkommenden Buchstabens im Eingabetext zu finden.
*/


int main(void) {
    const char *text1 = "hello";
    printf("%d\n", most_frequent_letter(text1)); // Ausgabe: 2

    const char *text2 = "abcde";
    printf("%d\n", most_frequent_letter(text2)); //
    return EXIT_SUCCESS;
}
