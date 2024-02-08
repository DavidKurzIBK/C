// Code liest Eingabedatei, die Informationen über Marskarte und Aktionen des Rovers enthält, und zeichnet dann Karte entsprechend den Aktionen des Rovers.

#include <stdio.h>
#include <stdlib.h>

// Konstanten definiert: MAX_WIDTH und MAX_HEIGHT, maximale Breite und Höhe Marskarte festlegen.
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// deklariert, die den Dateinamen einer Eingabedatei erwartet.
void draw_mars_map(const char* input_file) {
    FILE* file = fopen(input_file, "r"); //  Öffnen der angegebenen Datei im Lese-Modus. Wenn Öffnen fehlschlägt, wird Fehlermeldung ausgegeben und Funktion kehrt zurück.
    if (file == NULL) {
        printf("Fehler beim Öffnen der Datei.\n");
        return;
    }

    // Variablen für die Breite, Höhe, x- und y-Koordinaten des Rovers deklariert
    int width, height, x, y;
    // fscanf werden Werte für Breite, Höhe, x- und y-Koordinaten aus Eingabedatei gelesen.
    fscanf(file, "width = %d\n", &width);
    fscanf(file, "height = %d\n", &height);
    fscanf(file, "x = %d\n", &x);
    fscanf(file, "y = %d\n", &y);

    // zweidimensionales Array map erstellt, um Marskarte darzustellen. Alle Elemente des Arrays werden mit Leerzeichen initialisiert.
    char map[MAX_HEIGHT][MAX_WIDTH];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = ' ';
        }
    }

    // Element der Karte, an dem sich der Rover befindet, wird mit dem Buchstaben 'O' markiert.
    map[y][x] = 'O';
    char action;
    char direction = 'N'; // Anfangsrichtung des Rovers (Norden)

    // Schleife gestartet, um die Aktionen des Rovers aus der Eingabedatei zu lesen, bis Dateiende erreicht ist.
    // zuerst das nächste Zeichen aus Datei in der Variablen action gespeichert.
    while (fscanf(file, "%c", &action) != EOF) {

        // action den Wert 'L' hat, eine Linksdrehung des Rovers um 90 Grad. 
        // Je nach aktueller Ausrichtung des Rovers wird Richtung entsprechend geändert (Norden -> Westen -> Süden -> Osten).
        if (action == 'L') {
            // Linksdrehung um 90 Grad
            if (direction == 'N') {
                direction = 'W'; // Neue Richtung: Westen
            } else if (direction == 'W') {
                direction = 'S'; // Neue Richtung: Süden
            } else if (direction == 'S') {
                direction = 'E'; // Neue Richtung: Osten
            } else if (direction == 'E') {
                direction = 'N'; // Neue Richtung: Norden
            }
        } else if (action == 'R') {
            // action den Wert 'R' hat, Rechtsdrehung des Rovers um 90 Grad. Ähnlich wie zuvor wird die Richtung entsprechend aktualisiert.
            if (direction == 'N') {
                direction = 'E'; // Neue Richtung: Osten
            } else if (direction == 'E') {
                direction = 'S'; // Neue Richtung: Süden
            } else if (direction == 'S') {
                direction = 'W'; // Neue Richtung: Westen
            } else if (direction == 'W') {
                direction = 'N'; // Neue Richtung: Norden
            }
        } else if (action == 'S') {
            // action den Wert 'S' hat, Vorwärtsbewegung des Rovers. Die Anzahl der Schritte wird aus der Datei gelesen und in der Variablen steps gespeichert.
            int steps;
            fscanf(file, "%d", &steps);

            // // Abhängig aktuellen Ausrichtung des Rovers werden entsprechenden Felder Karte mit Buchstaben 'O' markiert, um Bewegung des Rovers darzustellen.
            if (direction == 'N') {
                // Bewegung in Richtung Norden
                for (int i = 1; i <= steps; i++) {
                    if (y - i >= 0) {
                        map[y - i][x] = 'O'; 
                    }
                }
                y -= steps; // Aktualisiere die y-Koordinate
            } else if (direction == 'E') {
                // Bewegung in Richtung Osten
                for (int i = 1; i <= steps; i++) {
                    if (x + i < width) {
                        map[y][x + i] = 'O';
                    }
                }
                x += steps; // Aktualisiere die x-Koordinate
            } else if (direction == 'S') {
                // Bewegung in Richtung Süden
                for (int i = 1; i <= steps; i++) {
                    if (y + i < height) {
                        map[y + i][x] = 'O';
                    }
                }
                y += steps; // Aktualisiere die y-Koordinate
            } else if (direction == 'W') {
                // Bewegung in Richtung Westen
                for (int i = 1; i <= steps; i++) {
                    if (x - i >= 0) {
                        map[y][x - i] = 'O';
                    }
                }
                x -= steps; // Aktualisiere die x-Koordinate
            }
        }
    }

    fclose(file); // alle Aktionen ausgeführt wurden, wird die Eingabedatei geschlossen.

    // Ausgabe der Marskarte zeienweise, indem die Elemente des Arrays map nacheinander gedruckt werden.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) { // Dateipfad der Eingabedatei als Kommandozeilenargument erwartet.

    // überprüft, ob mindestens ein Kommandozeilenargument vorhanden ist. Wenn nicht, wird Fehlermeldung ausgegeben und programm mit Rückgabewert 1 beendet.
    if (argc < 2) {
        printf("Bitte geben Sie den Dateipfad als Kommandozeilenargument an.\n");
        return 1;
    }

    const char* input_file = argv[1]; // Dateipfad wird in der Variablen input_file gespeichert.
    draw_mars_map(input_file); // draw_mars_map wird mit Dateipfad aufgerufen, um Marskarte zu zeichnen.

    return 0;
}
