#include <stdlib.h>
#include <stdio.h>

// dynamische Speicherzuweisung (malloc) und dynamische Speicherfreigabe (free)
// benutzerdefinierte Datenstruktur definiert, die das Pascalsche Dreieck repräsentiert. 
// enthält Anzahl der Zeilen (rows) und Zeiger auf ein zweidimensionales Array von Ganzzahlen (values), das die Dreieckswerte enthält.
struct pascals_triangle {
    unsigned rows;
    unsigned **values;
};


// Fkt: die Pascalsche Dreieck initialisiert. nimmt die Anzahl der gewünschten Zeilen als Parameter. 
struct pascals_triangle *init_pascals_triangle(unsigned rows) {
    struct pascals_triangle *triangle = malloc(sizeof(struct pascals_triangle)); // Speicher für Datenstruktur pascals_triangle mit malloc allokiert.
    triangle->rows = rows;
    triangle->values = malloc(rows * sizeof(unsigned *)); // Speicher für das zweidimensionale Array values allokiert. 


    // In Schleife Werte des Dreiecks berechnet und in Array geschrieben.
    for (unsigned i = 0; i < rows; i++) {
        triangle->values[i] = malloc((i + 1) * sizeof(unsigned)); // -> oder . operato greift auf komponent. der Struktur zu
        triangle->values[i][0] = 1;

        for (unsigned j = 1; j < i; j++) {
            triangle->values[i][j] = triangle->values[i - 1][j - 1] + triangle->values[i - 1][j];
        }

        triangle->values[i][i] = 1;
    }

    return triangle;
}

//  gibt Element des Pascalschen Dreiecks an der angegebenen Zeile (row) und Spalte (column) zurück
unsigned get_element(const struct pascals_triangle *triangle, unsigned row, unsigned column) {
    if (row >= triangle->rows || column > row) {
        return 0; // überprüft, ob angegebenen Indizes gültig sind, Wenn nicht, wird 0 zurückgegeben. 
    }

    // Andernfalls entsprechende Wert aus dem Array values zurückgegeben
    return triangle->values[row][column];
}

// Funktion gibt den durch das Pascalsche Dreieck belegten Speicher frei
void free_pascals_triangle(struct pascals_triangle *triangle) {
    // durchläuft das zweidimensionale Array und gibt den Speicher für jede Zeile frei
    for (unsigned i = 0; i < triangle->rows; i++) {
        free(triangle->values[i]);
    }
    // Speicher für das Array values und schließlich der Speicher für das triangle-Objekt selbst freigegeben
    free(triangle->values);
    free(triangle);
}

//Zeile für Zeile durchs Array values und druckt die Werte mit entsprechenden Abständen aus, um ein schönes Dreiecksmuster zu erzeugen.
void print_pascals_triangle(const struct pascals_triangle *triangle) {
    for (unsigned i = 0; i < triangle->rows; i++) { //print leading spaces
        for (unsigned j = 0; j <= i; j++) { // print values
            printf("%d ", triangle->values[i][j]);
        }
        printf("\n");
    }
}


// nimmt die Anzahl der Zeilen als Befehlszeilenargument (argv[1]) entgegen
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <rows>\n", argv[0]);
        return EXIT_FAILURE; // nicht genau ein Argument übergeben, eine Fehlermeldung ausgegeben und Programm beendet
    }

    //  Dreieck initialisiert, gedruckt und anschließend der Speicher freigegeben
    unsigned rows = atoi(argv[1]);

    struct pascals_triangle *triangle = init_pascals_triangle(rows);
    print_pascals_triangle(triangle);
    free_pascals_triangle(triangle);
    
    return EXIT_SUCCESS;
}
