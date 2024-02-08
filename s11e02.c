#include <stdio.h>
#include <stdlib.h>

/* TODO: Insert macros here */

int main(void) {
    int x = MY_VALUE;
    int y = 5;

    PRINT_STATUS("program start!");

    PRINT_DEBUG("x: %d\n", x);
    PRINT_DEBUG("y: %d\n", y);

    PRINT_STATUS("before first assertion");
    MY_ASSERT(x < 0, "x less than 0!");

    PRINT_COND(MY_TRUE);
    PRINT_COND(MY_FALSE);
    PRINT_COND(y < x);
    PRINT_COND(12 + 34 / 12 > 0);

    PRINT_STATUS("before second assertion");
    MY_ASSERT(y < x, "stop program, y < x.");

    PRINT_STATUS("program end");
    return EXIT_SUCCESS;
}
