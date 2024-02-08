#include <stdlib.h>

void do_something(int my_array[], size_t my_length) {
    for (size_t i = 0; i < my_length; ++i) {
        my_array[i] *= 2;
    }
}

int main(void) {
    int my_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    do_something(my_array, 9);
    return EXIT_SUCCESS;
}
