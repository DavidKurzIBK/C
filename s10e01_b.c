#include <stdlib.h>

int main(void) {
    int *p = malloc(sizeof(*p));
    *p = 1;
    free(p);
    *p = 2;
    return EXIT_SUCCESS;
}
