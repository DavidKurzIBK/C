//Programm liest eine Datei mit Zahlen, findet den kleinsten und größten Wert 
//sowie die Anzahl der gelesenen Zahlen und gibt sie auf der Konsole aus.

#include <stdio.h>
#include <stdlib.h> 

// Die main-Funktion ist der Einstiegspunkt des Programms. 
int main(int argc, char *argv[]) {  // Sie nimmt zwei Parameter: argc (die Anzahl der Argumente) und argv (ein Array von Zeichenketten, die die Argumente enthalten)
// Parameter ermöglichen Zugriff auf Befehlszeilenargumente, die beim Ausführen des Programms übergeben werden.


// Code überprüft, ob Argument (den Dateipfad) übergeben wurde. Wenn argc nicht 2 ist, wird Fehlermeldung ausgegeben, 
// die korrekten Verwendungszweck Programms erklärt, und Programm wird mit Rückgabewert 1 beendet.
    if (argc != 2) {
        printf("Verwendung: %s <dateipfad>\n", argv[0]); 
        return 1;
    }
// dateipfad wird mit Wert zweiten Arguments (argv[1]) initialisiert. Dies Pfad zur Datei, die geöffnet und gelesen werden soll.
    char *dateipfad = argv[1];
    // fopen: Datei mit angegebenen Pfad im Lesemodus zu öffnen. Ergebnis wird der Variablen datei zugewiesen. 
    // nicht erfolgreich geöffnet (das Ergebnis ist NULL), wird Fehlermeldung ausgegeben, und Programm mit Rückgabewert 1 beendet.
    FILE *datei = fopen(dateipfad, "r");
    if (datei == NULL) {
        printf("Fehler beim Öffnen der Datei.\n");
        return 1;
    }
// Variablen deklariert: zahl (aktuell gelesene Zahl aus der Datei), 
// min und max (kleinsten und größten Wert)  
// count (Anzahl der gelesenen Zahlen).
    long zahl;
    long min = 0;
    long max = 0;
    int count = 0;
// fscanf: Zahl aus geöffneten Datei zu lesen. 
// Wenn erfolgreich (das Ergebnis ist 1), wird Wert Variable zahl zugewiesen, und min & max erhalten Wert von zahl & count um eins erhöht.
    if (fscanf(datei, "%ld", &zahl) == 1) {
        min = zahl;
        max = zahl;
        count++;
    }
// Schleife wird die Datei Zeile für Zeile gelesen, mit fscanf weitere Zahl aus Datei zu lesen. 
// erfolgreich ist (das Ergebnis ist 1), wird der Code in der Schleife ausgeführt.
// überprüft, ob aktuell gelesene Zahl kleiner als min ist. 
// Wenn ja, min auf Wert der gelesenen Zahl aktualisiert. Ebenso überprüft aktuell gelesene Zahl größer als max ist. 
// Wenn ja,  max auf Wert der gelesenen Zahl aktualisiert. In beiden Fällen wird count um eins erhöht.
    while (fscanf(datei, "%ld", &zahl) == 1) {
        if (zahl < min)
            min = zahl;
        if (zahl > max)
            max = zahl;
        count++;
    }

    // alle Zahlen in Datei gelesen, wird Datei mit fclose geschlossen, um Ressourcen freizugeben.
    fclose(datei);

// Ergebnisse ausgegeben: Anzahl der gelesenen Zahlen (count), der kleinste Wert (min) und der größte Wert (max).
    printf("count = %d\n", count);
    printf("min = %ld\n", min);
    printf("max = %ld\n", max);

// Rückgabewert 0 zurück, um anzuzeigen, erfolgreich ausgeführt wurde.
    return 0;
}