#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char values[] = "0123456789";
    char *p1 = values;
    char *p2 = values + strlen(values);
    printf("1. %c\n", *(p1 + 4));
    printf("2. %c\n", *p2);
    printf("3. %d\n", p1 < p2);
    printf("4. %d\n", (p1 + 2) < (p2 - 4));
    printf("5. %d\n", (((int32_t *)p1) + 2) < (int32_t *)(p2 - 4));
    printf("6. %td\n", p2 - p1);
    return EXIT_SUCCESS;
}
