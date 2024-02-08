#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int chosen_minutes = 3024; 
    int days, hours, minutes;
    
    days = chosen_minutes / (24 * 60);
    hours = (chosen_minutes % (24 * 60)) / 60; 
    minutes = chosen_minutes % 60; 
    
    printf("%dm -> %dd %dh %dm\n", chosen_minutes, days, hours, minutes);
    
    return EXIT_SUCCESS;
}

/*
1. Zahl in Minuten einlesen und berechnet daraus Tage 
2. Stunden und Minuten durch Division und Modulo-Operationen. 
3. %d - gibt das folgende argument als int aus!!
*/

