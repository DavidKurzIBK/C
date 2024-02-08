// einfache dynamische Array-basierte Liste in C. Hier ist eine schrittweise Erklärung des Codes:

#include <stdlib.h>
#include <stdio.h>

#define ARRAY_INIT_CAPACITY 4   // Makro definiert und auf den Wert 4 gesetzt (anfängliche Kapazität des Arrays in der Liste sein.)

typedef struct list {
    void **items;    // array of pointers to list items
    size_t capacity; // maximum possible size for currently allocated memory
    size_t size;     // current size of the list
} my_list; // hat also 3 Felder, 


// my_list_init wird definiert, um neue Liste zu initialisieren. sie erstellt eine Instanz der Struktur my_list, 
// allokiert Speicher für das Array items mit der anfänglichen Kapazität ARRAY_INIT_CAPACITY 
// Falls die Speicherzuweisung fehlschlägt, wird NULL zurückgegeben.
my_list *my_list_init() {
    my_list *list = (my_list *)malloc(sizeof(my_list)); 
    if (list == NULL) {
        return NULL;  // Failed to allocate memory
    }

// setzt die Kapazität und Größe auf die entsprechenden Werte und gibt einen Zeiger auf die initialisierte Liste zurück
// Falls die Speicherzuweisung fehlschlägt, wird NULL zurückgegeben.

    list->items = (void **)malloc(ARRAY_INIT_CAPACITY * sizeof(void *)); 
    if (list->items == NULL) {
        free(list);
        return NULL;  // Failed to allocate memory
    }

    list->capacity = ARRAY_INIT_CAPACITY;
    list->size = 0;

    return list;
}

// ibt die Größe der Liste zurück. Falls die Liste ungültig ist (Zeiger auf NULL), wird 0 zurückgegeben
size_t my_list_size(my_list *list) {
    if (list == NULL) {
        return 0;  // Invalid list
    }

    return list->size;
}


// fügt ein Element an einer bestimmten Position (idx) in die Liste ein. 
// Sie überprüft, ob die Liste gültig ist und ob der Index innerhalb des gültigen Bereichs liegt. 
// Wenn die aktuelle Kapazität nicht ausreicht, um das Element aufzunehmen, wird die Kapazität verdoppelt. 
// Anschließend werden die Elemente verschoben, um Platz für das neue Element zu machen, und das neue Element wird eingefügt. 
// Die Größe der Liste wird erhöht und 0 wird zurückgegeben, um den Erfolg der Operation anzuzeigen. 
// Andernfalls wird -1 zurückgegeben, um Fehler anzuzeigen.

int my_list_insert(my_list *list, void *item, size_t idx) {
    if (list == NULL) {
        return -1;  // Invalid list
    }

    if (idx > list->size) {
        return -1;  // Invalid index
    }

    // If the current capacity is not enough, double the capacity
    if (list->size == list->capacity) {
        size_t new_capacity = list->capacity * 2;
        void **new_items = (void **)realloc(list->items, new_capacity * sizeof(void *));
        if (new_items == NULL) {
            return -1;  // Failed to allocate memory
        }
        list->items = new_items;
        list->capacity = new_capacity;
    }

    // Shift elements to make space for the new item
    for (size_t i = list->size; i > idx; i--) {
        list->items[i] = list->items[i - 1];
    }

    // Insert the new item
    list->items[idx] = item;
    list->size++;

    return 0;
}



// fügt ein Element am Ende der Liste hinzu, indem sie die my_list_insert-Funktion aufruft und den Index auf die aktuelle Größe der Liste setzt. 
// Der Rückgabewert ist derselbe wie bei my_list_insert.
int my_list_append(my_list *list, void *item) {
    if (list == NULL) {
        return -1;  // Invalid list
    }

    return my_list_insert(list, item, list->size);
}



// gibt das Element an einem bestimmten Index zurück. 
// Sie überprüft, ob die Liste gültig ist und ob der Index innerhalb des gültigen Bereichs liegt. 
// Wenn die Überprüfung erfolgreich ist, wird der entsprechende Elementzeiger zurückgegeben. 
// Andernfalls wird NULL zurückgegeben.
void *my_list_get(my_list *list, size_t idx) {
    if (list == NULL || idx >= list->size) {
        return NULL;  // Invalid list or index
    }

    return list->items[idx];
}


// löscht das Element an einem bestimmten Index aus der Liste. 
// Sie überprüft, ob die Liste gültig ist und ob der Index innerhalb des gültigen Bereichs liegt. 
// Das gelöschte Element wird in deleted_item gespeichert. 
// Anschließend werden die verbleibenden Elemente verschoben, um die Lücke des gelöschten Elements zu füllen. Die Größe der Liste wird verringert. 
// Wenn der Speicherbedarf des Arrays weniger als ein Viertel der Kapazität beträgt und die Kapazität größer als die anfängliche Kapazität ist, 
// wird die Kapazität halbiert. 
// Schließlich wird das gelöschte Element zurückgegeben oder NULL, wenn ein Fehler auftritt.

void *my_list_delete(my_list *list, size_t idx) {
    if (list == NULL || idx >= list->size) {
        return NULL;  // Invalid list or index
    }

    void *deleted_item = list->items[idx];

    // Shift elements to fill the gap left by the deleted item
    for (size_t i = idx; i < list->size - 1; i++) {
        list->items[i] = list->items[i + 1];
    }

    list->size--;

    // If the memory used by items is less than a quarter of the capacity,
    // halve the capacity if it's greater than the initial capacity
    if (list->size < list->capacity / 4 && list->capacity > ARRAY_INIT_CAPACITY) {
        size_t new_capacity = list->capacity / 2;
        void **new_items = (void **)realloc(list->items, new_capacity * sizeof(void *));
        if (new_items != NULL) {
            list->items = new_items;
            list->capacity = new_capacity;
        }
    }

    return deleted_item;
}


// gibt den Speicher frei, der von der Liste und dem Array items verwendet wird. Wenn die Liste ungültig ist, wird nichts getan
void my_list_free(my_list *list) {
    if (list == NULL) {
        return;  // Invalid list
    }

    free(list->items);
    free(list);
}


// Einstiegspunkt des Programms. Hier werden die verschiedenen Funktionen der Liste getestet:
int main(void) {
    my_list *list = my_list_init();
    if (list == NULL) {
        printf("Failed to initialize the list\n"); // Eine Liste wird initialisiert und überprüft, ob die Initialisierung erfolgreich war.
        return 1;
    }

    // Es werden Elemente in die Liste eingefügt und am Ende angehängt.
    my_list_insert(list, "apple", 0);
    my_list_insert(list, "banana", 1);
    my_list_append(list, "cherry");
    my_list_insert(list, "date", 1);

    // Die Elemente werden nacheinander abgerufen und ausgegeben.
    printf("List elements: ");
    for (size_t i = 0; i < my_list_size(list); i++) {
        printf("%s ", (char *)my_list_get(list, i));
    }
    printf("\n");

    // Ein Element wird aus der Liste gelöscht und das gelöschte Element wird ausgegeben.
    void *deleted_item = my_list_delete(list, 2);
    printf("Deleted item: %s\n", (char *)deleted_item);

    // Die Elemente nach der Löschung werden erneut abgerufen und ausgegeben.
    printf("List elements after deletion: ");
    for (size_t i = 0; i < my_list_size(list); i++) {
        printf("%s ", (char *)my_list_get(list, i));
    }
    printf("\n");

    // Schließlich wird der Speicher der Liste freigegeben.
    my_list_free(list);

    return 0;
}

