// Code öffnet eine Eingabedatei, liest zeilenweise daraus und schreibt bestimmte Zeilen in eine Ausgabedatei basierend auf dem Wert n. 
// Fehlermeldungen werden ausgegeben, wenn beim Öffnen, Lesen oder Schreiben der Dateien ein Fehler auftritt.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

// folgende FKT akzeptiert drei Parameter: src_path (Quellpfad der Eingabedatei), dst_path (Zielpfad der Ausgabedatei) und
//  n (der Wert, der angibt, wie viele Zeilen übersprungen werden sollen).
int write_n(const char *src_path, const char *dst_path, int n) {
    //  überprüft, ob  n gültig ist, n kleiner als 1 ist, gibt die Funktion -1 zurück, um ungültigen Wert anzuzeigen.
    if (n < 1) {
        return -1;
    }
    // Fkt: Eingabedatei öffnen, durch src_path angegeben, indem fopen Modus "r" verwendet.
    // Wenn Öffnen der Datei fehlschlägt, gibt Funktion -2 zurück und gibt Fehlermeldung aus.
    FILE *src_file = fopen(src_path, "r");
    if (src_file == NULL) {
        perror("Fehler beim Öffnen der Eingabedatei");
        return -2; // Fehler beim Öffnen der Eingabedatei
    }

    // Fkt Ausgabedatei öffnen, durch dst_path angegeben, indem fopen Modus "w" verwendet, 
    // um neue Datei zu erstellen oder vorhandene Datei zu überschreiben. 
    // Wenn Öffnen Datei fehlschlägt, gibt Funktion -3 zurück, schließt geöffnete Eingabedatei und gibt eine Fehlermeldung aus.
    FILE *dst_file = fopen(dst_path, "w");
    if (dst_file == NULL) {
        perror("Fehler beim Öffnen der Ausgabedatei");
        fclose(src_file); // Schließen Sie die Datei, da sie erfolgreich geöffnet wurde
        return -3; // Fehler beim Öffnen der Ausgabedatei
    }

    // Zeilenpuffer line mit Größe von 81 Zeichen wird definiert. Puffer wird verwendet, um Zeilen aus Eingabedatei zu lesen.
    char line[81]; // Zeilenpuffer mit Platz für 80 Zeichen & Nullpointer
    int line_number = 1; // line_number initialisiert und auf 1 gesetzt, verwendet, um die aktuelle Zeilennummer zu verfolgen.
    
    // Schleife solange, bis fgets Ende der Eingabedatei erreicht oder Fehler auftritt. 
    // fgets verwendet, um Zeile aus Eingabedatei in Puffer line zu lesen.
    // Schleife überprüft, ob line_number durch n ohne Rest teilbar ist. 
    // Wenn ja, wird aktuelle Zeile in die Ausgabedatei geschrieben, mit fprintf. 
    // Wenn Schreiben in die Ausgabedatei fehlschlägt, gibt Funktion -4 zurück, schließt geöffneten Dateien und gibt Fehlermeldung aus.
    while (fgets(line, sizeof(line), src_file) != NULL) {
        if (line_number % n == 0 && fprintf(dst_file, "%s", line) < 0) {
            perror("Fehler beim Schreiben in die Ausgabedatei");
            fclose(src_file);
            fclose(dst_file);
            return -4; // Fehler beim Schreiben in die Ausgabedatei
        }
        line_number++; // nachdem Zeile bearbeitet wurde, wird line_number um eins erhöht.
    }

    // Schleife beendet, wird überprüft, ob während Lesen der Eingabedatei Fehler aufgetreten 
    // Wenn ja, gibt Funktion -5 zurück, schließt geöffneten Dateien und gibt Fehlermeldung aus.
    if (ferror(src_file)) {
        perror("Fehler beim Lesen der Eingabedatei");
        fclose(src_file);
        fclose(dst_file);
        return -5; // Fehler beim Lesen der Eingabedatei
    }
    //  Eingabe- und Ausgabedateien werden mit fclose geschlossen.
    fclose(src_file);
    fclose(dst_file);

    // Set permissions for the output file
    chmod(dst_path, 0644);

    return 0; // erfolgreich ausgeführt 
}



int main() {
    const char *src_path = "in.txt"; // Pfad zur Eingabedatei src_path
    int n = 3; // n wird auf 3 gesetzt,jede dritte Zeile übersprungen

    char dst_path[20];
    snprintf(dst_path, sizeof(dst_path), "out_n=%d.txt", n); // Zielpfad für Ausgabedatei dst_path wird mit snprintf erstellt, wobei der Wert von n in den Dateinamen eingefügt 

    int result = write_n(src_path, dst_path, n); // write_n wird aufgerufen und Rückgabewert wird in Variable result gespeichert.
    switch (result) { // switch-Anweisung verwendet, um Rückgabewert zu überprüfen und entsprechende Fehlermeldungen auszugeben
        case 0:
            printf("Die Funktion wurde erfolgreich ausgeführt.\n");
            break;
        case -1:
            printf("Ungültiger Wert für 'n'. Die Funktion wurde nicht ausgeführt.\n");
            break;
        case -2:
            printf("Fehler beim Öffnen der Eingabedatei.\n");
            break;
        case -3:
            printf("Fehler beim Öffnen der Ausgabedatei.\n");
            break;
        case -4:
            printf("Fehler beim Schreiben in die Ausgabedatei.\n");
            break;
        case -5:
            printf("Fehler beim Lesen der Eingabedatei.\n");
            break;
        default:
            printf("Unbekannter Fehler.\n");
            break;
    }

    return 0; // rogramm erfolgreich beendet.
}








