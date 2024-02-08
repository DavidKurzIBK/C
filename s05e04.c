#include <stdio.h>
#include <stdlib.h>


unsigned long long triangular_number(unsigned side_length) {
    return side_length * (unsigned long long) (side_length + 1) / 2;
}


int main(void) {
    printf("%llu\n", triangular_number(0)); // 0 
    printf("%llu\n", triangular_number(1)); // 1
    printf("%llu\n", triangular_number(2)); // 3
    printf("%llu\n", triangular_number(3)); // 6
    printf("%llu\n", triangular_number(4)); // 10
    printf("%llu\n", triangular_number(8)); // 36
    return EXIT_SUCCESS;
}