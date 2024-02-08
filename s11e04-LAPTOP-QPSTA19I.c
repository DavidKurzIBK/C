#include "my_stack.h"
#include "my_stack.c"
#include <assert.h>
#include <stdio.h>

// Hilfsfunktion, die den Stapel auf seine Funktionalität testet.
static void test_stack() {
    // test stack functionality
    my_stack *stack = my_stack_init(); // Instanz Stapels stack erstellt, indem Fkt my_stack_init aufgerufen -> initialisiert Stapel und gibt Zeiger auf den Stapel zurück.
    // check stack is empty
    assert(my_stack_empty(stack) == true); // überprüft ob stapel leer; 
    assert(my_stack_size(stack) == 0); // ob stapel größe 0; 
    assert(my_stack_top(stack) == NULL); // ob stapel oben kein element
    assert(my_stack_pop(stack) == NULL); // ob entfernen eines elements aus leeren stapel null ergibt; 

    // push values onto the stack
    int val1 = 10;
    int val2 = 20;
    int val3 = 30;
    my_stack_push(stack, &val1); // wert auf den stapel gepushed; 
    assert(my_stack_empty(stack) == false); // ob stapel nicht leer; 
    assert(my_stack_size(stack) == 1);      // ob stapel größe 1; 
    assert(*(int *)my_stack_top(stack) == val1); // ob oberste element des stapels größe 10?
    // Vorgang wie oben für die anderen Werte (20 und 30) wiederholt
    my_stack_push(stack, &val2);
    assert(my_stack_empty(stack) == false);
    assert(my_stack_size(stack) == 2);
    assert(*(int *)my_stack_top(stack) == val2);
    my_stack_push(stack, &val3);
    assert(my_stack_empty(stack) == false);
    assert(my_stack_size(stack) == 3);
    assert(*(int *)my_stack_top(stack) == val3);

    // pop values from the stack, indem die Funktion my_stack_pop aufgerufen wird. 
    // Rückgabewert ist Zeiger auf den entfernten Wert.
    // sicherzustellen, das Entfernen der Werte korrekt war. 
    // Dabei überprüft, ob Werte in richtigen Reihenfolge entfernt wurden und ob Stapelgröße und Zustand des Stapels nach Pop-Operationen korrekt sind.
    int *popped_val = (int *)my_stack_pop(stack);
    assert(*popped_val == val3);
    assert(my_stack_empty(stack) == false);
    assert(my_stack_size(stack) == 2);
    assert(*(int *)my_stack_top(stack) == val2);
    popped_val = (int *)my_stack_pop(stack);
    assert(*popped_val == val2);
    assert(my_stack_empty(stack) == false);
    assert(my_stack_size(stack) == 1);
    assert(*(int *)my_stack_top(stack) == val1);
    popped_val = (int *)my_stack_pop(stack);
    assert(*popped_val == val1);
    assert(my_stack_empty(stack) == true);
    assert(my_stack_size(stack) == 0);
    assert(my_stack_top(stack) == NULL);
    popped_val = (int *)my_stack_pop(stack);
    assert(popped_val == NULL);

    // Stapel mit Funktion my_stack_free freigegeben, um Speicherlecks zu vermeiden
    my_stack_free(stack);
}

int main(void) {
    test_stack();
    return EXIT_SUCCESS;
}
