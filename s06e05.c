#include <stdlib.h>
#include <stdio.h>

size_t copy_duplicates(int dst[], const int src[], size_t len) {
    size_t count = 0;

    // hfgkt des elements in src zählen
    int* frequencyMap = (int*)calloc(len, sizeof(int));
    for (size_t i = 0; i < len; i++){
        frequencyMap[src[i]]++;
    }

    // Kopiere Werte mit einer Häufigkeit von mehr als 1 in dst

    for (size_t i = 0; i < len; i++) {
        if (frequencyMap[src[i]] > 1) {
            dst[count++] = src[i];
            frequencyMap[src[i]] = 0;  // Markiere das Element als kopiert
        }
    }

    free(frequencyMap);
    return count;

}


int main(void){
    int src1[] = {1, 1, 1};
    int dst1[3];
    size_t n1 = copy_duplicates(dst1, src1, 3);
    printf("n1: %zu, dst1: {", n1);
    for (size_t i = 0; i < n1; i++) {
        printf("%d, ", dst1[i]);
    }
    printf("}\n");

    int src2[] = {1, 2, 3};
    int dst2[3];
    size_t n2 = copy_duplicates(dst2, src2, 3);
    printf("n2: %zu, dst2: {", n2);
    for (size_t i = 0; i < n2; i++) {
        printf("%d, ", dst2[i]);
    }
    printf("}\n");

    int src3[] = {5, 2, 5, 7, -7, 3};
    int dst3[6];
    size_t n3 = copy_duplicates(dst3, src3, 6);
    printf("n3: %zu, dst3: {", n3);
    for (size_t i = 0; i < n3; i++) {
        printf("%d, ", dst3[i]);
    }
    printf("}\n");

    int src4[] = {4, 3, 1, 4, 1};
    int dst4[5];
    size_t n4 = copy_duplicates(dst4, src4, 5);
    printf("n4: %zu, dst4: {", n4);
    for (size_t i = 0; i < n4; i++) {
        printf("%d, ", dst4[i]);
    }
    printf("}\n");
    return EXIT_SUCCESS;
}