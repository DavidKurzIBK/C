#include <stdio.h>
#include <stdlib.h>

// Rekusive Summenberechnung: sum() ruft sich selbst mit argument auf
// um Summe aller Zahlen von 0 bis n-1 zu rechnen.
// wiederholt, bis n den Wert 0 erreicht, woraufhin die Rekursion stoppt und Summe der Zahlen zurückgegeben.
unsigned sum(unsigned n) {
    if(n==0){
        return EXIT_SUCCESS;
    } else {
        return n + sum(n - 1);
    }
}

// rekursive Fakultätsberechnung: produkt aller natürlichen zahlen von 1 bis n
// Funktion fac sich selbst mit dem Argument n-1 aufruft, um die Fakultät von n-1 zu berechnen. 
// Dieser rekursive Aufruf wird wiederholt, bis n den Wert 0 erreicht, 
// woraufhin die Rekursion stoppt und das Ergebnis der Fakultätsberechnung zurückgegeben wird.


unsigned long long fac(unsigned char n) {
    if(n == 0){
        return EXIT_FAILURE; // oder Wert 1 entspr. EXIT_FAILURE
    } else {
        return (unsigned long long)n * fac(n-1);
    }
}

// Rekusive berechnung des n-ten Elem. in Zahlenfolge: n-te Glied der Fibonacci-Folge berechnet
// wenn nicht n == 0 oder 1: ruft die Funktion sich selbst auf, 
// um die Summe der beiden vorherigen Glieder der Folge zu berechnen. 
// Dies geschieht durch die Addition der beiden rekursiven Aufrufe von number_sequence mit 
// den Argumenten n-1 und n-2. Die Rekursion wird fortgesetzt, bis n den Wert 0 oder 1 erreicht, 
// woraufhin die Berechnung der Fibonacci-Folge abgeschlossen ist und das Ergebnis zurückgegeben wird.


unsigned number_sequence(unsigned char n) {
    if(n == 0){
        return 2;
    } else if(n == 1){ //geht auch nur if, weil return beendet fknt sofort
        return 1;
    } else {
        return number_sequence(n-1) + number_sequence(n-2); // könnte else weglassen, fkt beendet rekusion bei n > 1
    }
}

// Rekursive Ziffernsummenberechnung: 
unsigned digit_sum(int n) {
    if(n<0){
        n = -n;
    } // für den Fall, dass n negativ ist zuerst pos gemacht
    if(n<10){
        return n; // ziffernsumme gleich retourniert 
    } else {
        return (n%10) + digit_sum(n/10); // Ziffer an der Einserstelle von n durch den Modulo-Operator (%) berechnet 
        // und zur Ziffernsumme der restlichen Ziffern von n hinzugefügt wird. 
        // Dies geschieht durch den rekursiven Aufruf von digit_sum mit dem Argument n/10,
        // welches alle Stellen von n außer der Einserstelle enthält. Die Rekursion wird 
        // fortgesetzt, bis n kleiner als 10 ist, woraufhin die Ziffernsumme von n zurückgegeben wird.
    }
}

int main(){
    unsigned n = 5;
    printf("Summe von 0 bis %u: %u\n", n, sum(n));
    
    unsigned char m = 10;
    printf("Fakultät von %u: %llu\n", m, fac(m));
    
    unsigned char k = 7;
    printf("Das %u-te Element der Zahlenfolge: %u\n", k, number_sequence(k));
    
    int p = -123456;
    printf("Ziffernsumme von %d: %u\n", p, digit_sum(p));
    
    return EXIT_SUCCESS;
}








