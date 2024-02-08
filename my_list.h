#ifndef MY_LIST_H
#define MY_LIST_H

#include <stdlib.h>

typedef struct list my_list;

my_list *my_list_init();

size_t my_list_size(my_list *list);

int my_list_insert(my_list *list, void *item, size_t idx);

int my_list_append(my_list *list, void *item);

void *my_list_get(my_list *list, size_t idx);

void *my_list_delete(my_list *list, size_t idx);

void my_list_sort(my_list *list, int (*compar)(const void *, const void *));

void my_list_free(my_list *list);

#endif // MY_LIST_H
