#include "my_stack.h"
#include <assert.h>
#include <stdio.h>

static void test_stack() {
    // test stack functionality
    my_stack *stack = my_stack_init();
    // check stack is empty
    assert(my_stack_empty(stack) == true);
    assert(my_stack_size(stack) == 0);
    assert(my_stack_top(stack) == NULL);
    assert(my_stack_pop(stack) == NULL);

    /* TODO: Implement further tests */
}

int main(void) {
    test_stack();
    return EXIT_SUCCESS;
}
