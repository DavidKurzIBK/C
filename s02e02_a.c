#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char a = 'c';
    short b = 11995;
    int c = +12005;
    unsigned d = 36772;
    long e = -510543188;
    float f = -279.29;
    double g = 4.92108e+15;

    printf("a = %c\nb = %hd\nc = %+d\nd = %u\ne = %ld\nf = %.2f\ng = %.5e\n", a, b, c, d, e, f, g);
    /*Die Variable a wird als %c formatiert, um sie als einzelnes Zeichen auszugeben.
    Die Variablen b, d, e werden als %d, %f formatiert, um sie als Dezimalzahlen auszugeben.
    Die Variable c wird als %+.3f formatiert, um sie als Dezimalzahl mit Vorzeichen und drei Nachkommastellen auszugeben.
    Die Variable f wird als %.2f formatiert, um sie als Dezimalzahl mit zwei Nachkommastellen auszugeben.
    Die Variable g wird als %.5e formatiert, um sie als Dezimalzahl in Exponentialdarstellung mit 
    kleingeschriebenem e und fünf Nachkommastellen auszugeben.*/

    printf("\nf_10 = %.10f\n", f);
    /*Anzahl an Nachkommastellen hängt vom Datentyp ab. Hier: double-Datentyp 
    mit Genauigkeit bei von 15 bis 17 Dezimalstellen*/

    printf("\nd_pad = %0*d\n", c-b, d);
    /*%0*d gibt an: Wert vor d mit Nullen aufgefüllen, um die Mindestbreite von c - b zu erreichen. 
    (*)  = Breite im Argument nach Formatierung übergeben */


    printf("\na = %16d\nb = %16d\nc = %16d\nd = %16u\ne = %16ld\nf = %21.4f\ng = %21.4f\n", a, b,c, d, e, f, g);
    /*Die Formatierungsoption %16.4f gibt an, dass jeder Gleitkommawert mit einer Breite von 
    16 Zeichen und einer Genauigkeit von 4 Nachkommastellen ausgegeben werden soll.*/


    return EXIT_SUCCESS;
}

