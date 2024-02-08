/*
Code definiert eine Schnittstelle für einen Stack-Datentyp in C. 
Implementierung des Stacks ist separat in einer C-Quelldatei bereitgestellt, 
in der die Funktionen der deklarierten Schnittstelle implementiert werden.*/


// Präprozessor-Direktiv #ifndef MY_STACK_H, um sicherzustellen, dass nachfolgende Code nur einmal eingefügt wird, selbst wenn Header-Datei mehrmals in Programm eingebunden. 
// Das MY_STACK_H ist ein eindeutiger Bezeichner, der den Header schützt

#ifndef MY_STACK_H
#define MY_STACK_H 

#include <stdbool.h>
#include <stdlib.h>

typedef struct stack my_stack;  // benutzerdefinierter Typ my_stack erstellt, der Stack darstellt.

my_stack *my_stack_init();     //  deklariert & initialisiert den Stack und gibt einen Zeiger auf den initialisierten Stack zurück

bool my_stack_empty(my_stack *stack);  // deklariert & prüft, ob der Stack leer ist, und gibt einen boolschen Wert zurück (true, wenn der Stack leer ist, andernfalls false).

size_t my_stack_size(my_stack *stack);  // deklariert & gibt die Anzahl der Elemente im Stack als size_t zurück.

void *my_stack_top(my_stack *stack);   // deklariert & gibt einen Zeiger auf das oberste Element des Stacks zurück, ohne es zu entfernen

void *my_stack_push(my_stack *stack, void *val);  // deklariert & fügt ein Element zum Stack hinzu und gibt einen Zeiger auf das hinzugefügte Element zurück.

void *my_stack_pop(my_stack *stack);  // deklariert & entfernt das oberste Element aus dem Stack und gibt einen Zeiger auf das entfernte Element zurück.

void my_stack_free(my_stack *stack);  // deklariert & gibt den Speicher des Stacks frei.

#endif // MY_STACK_H  // Präprozessor-Direktiv #endif verwendet, um Ende des geschützten Bereichs des Headers zu markieren
