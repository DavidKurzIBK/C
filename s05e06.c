#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

void print_binary_recursive(uint32_t value, int bit_pos) {
    if (bit_pos == 0) {
        printf("%d", ((value >> bit_pos) & 1));
    }
    return print_binary_recursive(value, bit_pos - 1);
;
}

void print_binary(uint32_t value) {
    printf("%" PRIu32 " = 0b", value);
    print_binary_recursive(value, 31);
}

int main(void) {
    uint32_t value;
    printf("value: ");
    if (scanf("%"SCNu32, &value) != 1) {
        fprintf(stderr, "ERROR: While reading the 'uint32_t' value an error occurred!");
        return EXIT_FAILURE;
    }
    printf("\n");
    print_binary(value);
    printf("\n");
    return EXIT_SUCCESS;
}
