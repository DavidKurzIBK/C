#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG
#define MY_VALUE 1
#else
#define MY_VALUE 10
#endif

#define MY_TRUE 1
#define MY_FALSE 0

#define MY_ASSERT(expr, msg) \
    do { \
        if (!(expr)) { \
            fprintf(stderr, "%s\n", msg); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)

#define COND_TO_STR(expr) \
    (expr) ? "true" : "false"

#ifdef DEBUG
#define PRINT_COND(expr) \
    printf("%s evaluates to '%s'\n", #expr, COND_TO_STR(expr))
#else
#define PRINT_COND(expr) \
    do {} while (0)
#endif

#ifdef DEBUG
#if DEBUG == 3
#define PRINT_STATUS(msg) \
    printf("%s:%d | function: %s | message: %s\n", __FILE__, __LINE__, __func__, msg)
#else
#define PRINT_STATUS(msg) \
    do {} while (0)
#endif
#else
#define PRINT_STATUS(msg) \
    do {} while (0)
#endif

int main() {
    int x = MY_VALUE;
    int y = 5;

    PRINT_COND(MY_TRUE);
    PRINT_COND(MY_FALSE);
    PRINT_COND(y < x);
    PRINT_COND(12 + 34 / 12 > 0);

    MY_ASSERT(y < x, "stop program, y < x.");

    #ifdef DEBUG
    printf("x: %d\n", x);
    printf("y: %d\n", y);
    #endif

    #ifdef DEBUG
    PRINT_COND(y < x);
    #endif

    PRINT_COND(12 + 34 / 12 > 0);

    #ifdef DEBUG
    PRINT_STATUS("program start!");
    #endif

    MY_ASSERT(y > x, "before first assertion");

    #ifdef DEBUG
    PRINT_STATUS("before second assertion");
    PRINT_STATUS("program end");
    #endif

    return 0;
}
