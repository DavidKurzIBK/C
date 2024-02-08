#include <stdlib.h>
#include <stdio.h>

long long sum(int values[], size_t length) {
    long long result = 0;
    for(size_t i = 0; i < length; i++){
        result += values[i];
    }
    return result;
}

int min(int values[], size_t length) {
    int result = values[0];
    for (size_t i = 1; i < length; i++){
        if (values[i] < result){
            result = values[i];
        }
    }
    return result;
}

int max(int values[], size_t length) {
    int result = values[0];
    for(size_t i = 1; i < length; i++){
        if(values[i] > result){
            result = values[i];
        }
    }
    return result;
}


/*
sum-Funktion: long long-Variable dass keine Überläufe auftreten, wenn Array viele Elemente enthält oder die Elemente sehr große Werte haben.
Die min- und max-Funktionen verwenden int-Variable, um aktuellen Minimum- bzw. Maximum-Wert zu speichern, 
und vergleichen ihn mit jedem Element des Arrays, um das neue Minimum bzw. Maximum zu finden.
Die main-Funktion testet die Funktionen anhand einiger Beispiele und gibt die Ergebnisse aus.*/

int main(void) {
    int arr1[] = {1, 2, 3};
    size_t len1 = sizeof(arr1) / sizeof(int);
    printf("Sum of {1, 2, 3}: %lld\n", sum(arr1, len1));
    printf("Min of {1, 2, 3}: %d\n", min(arr1, len1));
    printf("Max of {1, 2, 3}: %d\n", max(arr1, len1));
    
    int arr2[] = {4, 7, 10, -1};
    size_t len2 = sizeof(arr2) / sizeof(int);
    printf("Sum of {4, 7, 10, -1}: %lld\n", sum(arr2, len2));
    printf("Min of {4, 7, 10, -1}: %d\n", min(arr2, len2));
    printf("Max of {4, 7, 10, -1}: %d\n", max(arr2, len2));
    
    int arr3[] = {8, 2, 9, 2, 9};
    size_t len3 = sizeof(arr3) / sizeof(int);
    printf("Sum of {8, 2, 9, 2, 9}: %lld\n", sum(arr3, len3));
    printf("Min of {8, 2, 9, 2, 9}: %d\n", min(arr3, len3));
    printf("Max of {8, 2, 9, 2, 9}: %d\n", max(arr3, len3));
    return EXIT_SUCCESS;
}