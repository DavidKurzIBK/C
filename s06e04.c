#include <stdlib.h>
#include <stdio.h>

int is_monotonic(int values[], size_t length) {
    size_t i;
    int is_increasing = 1;
    int is_decreasing = 1;
    
    for (i = 1; i < length; i++) {
        if (values[i] > values[i - 1]) {
            is_decreasing = 0;
        } else if (values[i] < values[i - 1]) {
            is_increasing = 0;
        }
    }
    
    return is_increasing || is_decreasing;
}

 /*is_monotonic wird ein boolean-Wert is_increasing initial auf true und is_decreasing initial auf true gesetzt. 
 Dann jedes Paar aufeinanderfolgender Werte im Array values verglichen. 
 Wenn Wert an aktuellen Position größer ist als der vorherige, kann es nicht monoton fallend sein, 
 und wenn Wert kleiner ist, kann es nicht monoton steigend sein. Wenn eines der beiden Flags auf false gesetzt wird, 
 kann die Funktion vorzeitig verlassen werden, da Monotonie dann nicht mehr erhalten bleibt. Am Ende wird überprüft, 
 ob eines der Flags auf true geblieben ist und dementsprechend 1 oder 0 zurückgegeben.
*/



int main(void){
int arr1[] = {1};
    printf("%d\n", is_monotonic(arr1, 1)); // should print 1

    int arr2[] = {1, 3, -5};
    printf("%d\n", is_monotonic(arr2, 3)); // should print 0
    
    int arr3[] = {-10, 0, 4, 4};
    printf("%d\n", is_monotonic(arr3, 4)); // should print 1
    
    int arr4[] = {4, 12, 16, 50};
    printf("%d\n", is_monotonic(arr4, 4)); // should print 1
    
    int arr5[] = {4, 2, 0, -1};
    printf("%d\n", is_monotonic(arr5, 4)); // should print 1

    return EXIT_SUCCESS;
}