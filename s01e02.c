#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int value = 5;
    
    if (value > 10) {
        printf("value is greater than 10!\n");
    } if (value <= 10) {
        printf("value is less than or equal to 10!\n");
    }
    return EXIT_SUCCESS;
}