// implementiert eine Stack-Datenstruktur (Stapelspeicher) mithilfe einer verketteten Liste


#include "my_stack.h"
#include <stdbool.h>
#include <stdlib.h>

// Definition der verketteten Liste für den Stack-Knoten: 
// Struktur stack_node definiert, die Knoten in verketteten Liste repräsentiert. 
// Jeder Knoten enthält Datenfeld (void *data) und Zeiger auf nächsten Knoten (struct stack_node *next).
typedef struct stack_node {
    void *data;
    struct stack_node *next;
} stack_node;


// Definition der Datenstruktur für den Stack
// Struktur stack definiert, die die Datenstruktur für den Stack repräsentiert. 
// Der Stack enthält Zeiger auf obersten Knoten (stack_node *top) und Größe des Stacks (size_t size).
struct stack {
    stack_node *top;
    size_t size;
};

// Funktionen

// initialisiert Stack: dynamischer Speicher für eine Instanz von my_stack reserviert wird. 
// Wenn Speicherreservierung erfolgreich ist, wird obere Knoten (top) auf NULL gesetzt und Größe (size) auf 0 gesetzt. 
// Der initialisierte Stack wird zurückgegeben.
my_stack *my_stack_init() {
    my_stack *stack = (my_stack *)malloc(sizeof(my_stack));
    if (stack) {
        stack->top = NULL;
        stack->size = 0;
    }
    return stack;
}


// überprüft, ob Stack leer ist, indem überprüft wird, ob Größe (size) des Stacks gleich 0 ist. 
// Wenn Stack leer ist, wird true zurückgegeben, andernfalls false.
bool my_stack_empty(my_stack *stack) {
    return stack->size == 0;
}

// aktuelle Größe des Stacks zurück, indem der Wert des size-Feldes im Stack zurückgegebe
size_t my_stack_size(my_stack *stack) {
    return stack->size;
}

// gibt Wert des obersten Elements im Stack zurück, ohne es zu entfernen. 
// Zuerst überprüft, ob Stack nicht leer ist (stack->top != NULL). 
// Wenn der Stack nicht leer wird Datenfeld (data) des obersten Knotens zurückgegeben, andernfalls wird NULL zurückgegeben.
void *my_stack_top(my_stack *stack) {
    if (stack->top) {
        return stack->top->data;
    }
    return NULL;
}

// fügt ein Element zum Stack hinzu. dynamischer Speicher für neuen Knoten reserviert. 
// Speicherreservierung erfolgreich ist, wird Datenfeld des neuen Knotens auf übergebenen Wert (val) gesetzt, 
// Zeiger auf vorherigen obersten Knoten wird nächster Knoten für neuen Knoten festgelegt, 
// der neue Knoten wird zum obersten Knoten (top) gemacht und die Größe des Stacks wird erhöht. 
// Schließlich wird hinzugefügte Wert (val) zurückgegeben. Wenn Speicherreservierung fehlschlägt, wird NULL zurückgegeben.
void *my_stack_push(my_stack *stack, void *val) {
    stack_node *new_node = (stack_node *)malloc(sizeof(stack_node));
    if (new_node) {
        new_node->data = val;
        new_node->next = stack->top;
        stack->top = new_node;
        stack->size++;
        return val;
    }
    return NULL;
}

// entfernt oberste Element aus Stack und gibt selben Wert zurück. Zuerst überprüft, ob der Stack nicht leer ist. 
// Wenn Stack nicht leer ist, wird oberste Knoten inkl. Wert Datenfeld (data) des Stacks in temporären Variablen (top_node) & (data) gespeichert. 
// Der Zeiger auf nächsten Knoten des obersten Knotens wird neuer oberster Knoten festgelegt, Größe Stacks wird verringert und Speicher für obersten Knoten wird freigegeben. 
// gespeicherte Wert (data) zurückgegeben. Wenn der Stack leer ist, wird NULL zurückgegeben.
void *my_stack_pop(my_stack *stack) {
    if (stack->top) {
        stack_node *top_node = stack->top;
        void *data = top_node->data;
        stack->top = top_node->next;
        stack->size--;
        free(top_node);
        return data;
    }
    return NULL;
}

// gibt den vom Stack verwendeten Speicher frei. Dazu eine Schleife verwendet, um Stack zu durchlaufen, und für jeden Knoten wird Speicher freigegeben. 
// Speicher für den Stack selbst freigegeben
void my_stack_free(my_stack *stack) {
    while (stack->top) {
        stack_node *top_node = stack->top;
        stack->top = top_node->next;
        free(top_node);
    }
    free(stack);
}
