#include <stdlib.h>

#define ARRAY_INIT_CAPACITY 4

typedef struct list {
    void **items;    // array of pointers to list items
    size_t capacity; // maximum possible size for currently allocated memory
    size_t size;     // current size of the list
} my_list;

my_list *my_list_init() {
    /* TODO: Implement function logic */
}

size_t my_list_size(my_list *list) {
    /* TODO: Implement function logic */
}

int my_list_insert(my_list *list, void *item, size_t idx) {
    /* TODO: Implement function logic */
}

int my_list_append(my_list *list, void *item) {
    /* TODO: Implement function logic */
}

void *my_list_get(my_list *list, size_t idx) {
    /* TODO: Implement function logic */
}

void *my_list_delete(my_list *list, size_t idx) {
    /* TODO: Implement function logic */
}

void my_list_free(my_list *list) {
    /* TODO: Implement function logic */
}

int main(void) {
    /* TODO: Implement Tests */
}
