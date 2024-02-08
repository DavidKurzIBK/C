#include <stdlib.h>
#include <stdio.h>

void reverse(int values[], size_t length) {
    for(size_t i = 0; i < length / 2; i++){
        int temp = values[i];
        values[i] = values[length - i - 1];
        values[length - i - 1] = temp;
    }
}


/*
reverse-Funktion verwendet for-Schleife, um jedes Element im Array values zu durchlaufen. 
Innerhalb Schleife wird temporärer Wert temp verwendet, um aktuelle Element am Anfang des Arrays zu speichern. 
Dann aktuelle Element durch das entsprechende Element am Ende des Arrays ersetzt, 
und Ende des Arrays um eins nach links verschoben. Dieser Prozess wird fortgesetzt, 
bis alle Elemente im Array ausgetauscht wurden und das Array vollständig umgekehrt ist.
In der main-Funktion werden die Funktionen reverse aufgerufen, um die Arrays umzukehren. 
Größe des Arrays wird mit sizeof-Operator bestimmt. 
Anschließend werden die umgekehrten Arrays mithilfe der printf-Funktion ausgegeben.
*/

int main(void){
    int values1[] = {1, 2, 3};
    size_t length1 = sizeof(values1) / sizeof(int);
    reverse(values1, length1);
    printf("{%d, %d, %d}\n", values1[0], values1[1], values1[2]); // {3, 2, 1}

    int values2[] = {4, 7, 10, -1};
    size_t length2 = sizeof(values2) / sizeof(int);
    reverse(values2, length2);
    printf("{%d, %d, %d, %d}\n", values2[0], values2[1], values2[2], values2[3]); // {-1, 10, 7, 4}

    return EXIT_SUCCESS;

}