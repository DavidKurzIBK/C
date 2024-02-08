#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int most_frequent_letter(const char *text) {
    int freq[26] = {0}; // Array mit der Häufigkeit jedes Buchstabens im Text (ignoriert Groß- und Kleinschreibung)
    int max_freq = 0;   // Die größte Häufigkeit eines Buchstabens im Text
    int max_idx = -1;   // Der Index des Buchstabens mit der größten Häufigkeit im Text

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            int c = tolower(text[i]) - 'a'; // Buchstabe in Kleinbuchstaben umwandeln und auf Index im Array abbilden
            freq[c]++; // Häufigkeit des Buchstabens erhöhen
            if (freq[c] > max_freq || (freq[c] == max_freq && c < max_idx)) {
                max_freq = freq[c];
                max_idx = c;
            }
        }
    }

    return max_idx;
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
    const char *texts[] = {"hello", "abcde", "accbb", "b B a A", ".;:"};
    int expected[] = {2, 0, 3, 4, -1};

    for (int i = 0; i < sizeof(texts) / sizeof(texts[0]); i++) {
        int result = most_frequent_letter(texts[i]);
        printf("most_frequent_letter(\"%s\") = %d (expected %d)\n", texts[i], result, expected[i]);
    }
    return EXIT_SUCCESS;
}
