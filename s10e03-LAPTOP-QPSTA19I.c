// Erzeugung und Manipulation verketteter Listen, die eine gegebene Zahl repräsentieren. 
// Der Code enthält verschiedene Funktionen, die die verkettete Liste ausgeben, sowohl rekursiv als auch iterativ
// malloc (für dynamische Speicherzuweisung) und printf (für die Ausgabe auf der Konsole).


#include <stdlib.h>
#include <stdio.h>

// Knoten in der verketteten Liste repräsentiert. 
// Jeder Knoten hat ein Feld value vom Typ unsigned mit einer Breite von 4 Bits und einen Zeiger next auf den nächsten Knoten in der Liste.
struct list_node {
    unsigned value : 4; // Bitfeld
    struct list_node *next;
};


// repräsentiert verkettete Liste. enthält die Anzahl der Knoten (size) und einen Zeiger head auf den ersten Knoten in der Liste.
struct linked_list {
    size_t size;
    struct list_node *head;
};


// function: dient dazu, den Speicherplatz der verketteten Liste freizugeben. 
void free_linked_list(struct linked_list *list) {
    if (!list) { // überprüft, ob übergebene Zeiger list NULL ist. 
                 // Wenn ja, gibt einfach zurück.
        return;
    }
    // Andernfalls durchläuft sie die Liste von Anfang bis Ende und gibt den Speicherplatz jedes Knotens frei. 
    struct list_node *node = list->head;
    while (node) {
        struct list_node *next_node = node->next;
        free(node);
        node = next_node;
    }
    free(list); // Speicherplatz der verketteten Liste selbst freigegeben.

}

// function: wandelt eine gegebene Zahl in eine verkettete Liste um
struct linked_list *int_to_linked_list(int number) {
    if (number < 0) {
        return NULL; // überprüft, ob die Zahl negativ ist, wenn ja, gibt sie NULL zurück
    }
    // Ansonsten wird Speicherplatz für verkettete Liste (list) mit Größe einer linked_list Struktur allokiert
    struct linked_list *list = malloc(sizeof(*list));
    if (!list) {
        return NULL; // die Speicherzuweisung fehlschlägt, wird NULL zurückgegeben
    }
    // Ansonsten head auf NULL und size auf 0 initialisiert. Zeiger last_node wird auf die Adresse von head gesetzt
    list->head = NULL;
    list->size = 0;
    struct list_node **last_node = &list->head;

    // durchläuft nun die Ziffern der Zahl von rechts nach links und erzeugt für jede Ziffer einen neuen Knoten (current_node). 
    while (number || !list->size) {
        struct list_node *current_node = malloc(sizeof(*list));
        if (!current_node) {
            free_linked_list(list);
            return NULL;
        }
        // Wert des Knotens wird auf die aktuelle Ziffer gesetzt, und der Zeiger last_node wird auf den Zeiger next des aktuellen Knotens gesetzt. 
        current_node->next = NULL;
        current_node->value = number % 10;
        number /= 10;
        *last_node = current_node;
        last_node = &current_node->next;
        ++list->size; // Schließlich wird Größe der Liste erhöht und Schleife wiederholt, bis alle Ziffern abgearbeitet sind. 

    }
    return list;  // erstellte verkettete Liste zurückgegeben.

}

//Funkt: gibt Werte der Knoten in der verketteten Liste aus. 
// erhält einen Zeiger auf die verkettete Liste (list) und durchläuft die Liste von Anfang bis Ende, 
// wobei sie den Wert jedes Knotens auf der Konsole mit printf ausgibt.
void print_linked_list(struct linked_list *list) {
    struct list_node *node = list->head;
    while (node) {
        printf("%d", node->value);
        node = node->next;
    }
}


// fkt: ibt die Werte der Knoten in der verketteten Liste rekursiv aus.
void print_number_rec(struct linked_list *list) {
    if (!list || list->size == 0) {
        return; // überprüft , ob übergebene Liste NULL ist oder die Größe 0 hat. In diesem Fall wird die Funktion beendet. 
    }
    
    // Andernfalls Teilliste (sublist) erzeugt, indem erste Knoten aktuellen Liste (list->head) entfernt 
    // Größe der Teilliste ist um 1 kleiner als die Größe der aktuellen Liste,
    struct linked_list sublist = { list->size - 1, list->head->next }; // Zeiger next von sublist wird zweiten Knoten der aktuellen Liste gesetzt
    print_number_rec(&sublist); // Funktion print_number_rec wird mit Teilliste sublist als Argument rekursiv aufgerufen
    
    printf("%d", list->head->value); // Wert des ersten Knotens der aktuellen Liste auf der Konsole ausgegeben.
}


// Fkt gibt Werte der Knoten in der verketteten Liste iterativ aus
// überprüft, ob die übergebene Liste NULL ist oder die Größe 0 hat, wenn ja, fkt beendet.
void print_number_iter(struct linked_list *list) {
    if (!list || list->size == 0) {
        return;
    }
    // Andernfalls wird Zeiger node auf den ersten Knoten der Liste gesetzt.
    struct list_node *node = list->head;
    // Zeiger-Array node_stack wird mit Speicherplatz für die Anzahl der Knoten in der Liste allokiert
    struct list_node **node_stack = malloc(list->size * sizeof(struct list_node *));
    if (!node_stack) { // Speicherzuweisung fehlschlägt, wird die Funktion beendet
        return;
    }
    
    // Funktion durchläuft Liste von Anfang bis Ende und speichert jeden Knoten im node_stack
    int index = 0;
    while (node) {
        node_stack[index++] = node;
        node = node->next;
    }
    
    // node_stack in umgekehrter Reihenfolge durchlaufen, und Wert jedes Knotens auf der Konsole ausgegeben
    while (index > 0) {
        printf("%d", node_stack[--index]->value);
    }
    // Speicherplatz von node_stack freigegeben.
    free(node_stack);
}

int main(void) {
    // Testen der Funktionen un implementierung zu überprüfen

    // Erzeugen einer verketteten Liste für die Zahl 10
    struct linked_list *list1 = int_to_linked_list(10);
    printf("Ausgabe print_linked_list: ");
    print_linked_list(list1); // Ausgabe: 01
    printf("\nAusgabe print_number_rec: ");
    print_number_rec(list1); // Ausgabe: 10
    printf("\nAusgabe print_number_iter: ");
    print_number_iter(list1); // Ausgabe: 10
    printf("\n");

    // Erzeugen einer verketteten Liste für die Zahl 504
    struct linked_list *list2 = int_to_linked_list(504);
    printf("Ausgabe print_linked_list: ");
    print_linked_list(list2); // Ausgabe: 405
    printf("\nAusgabe print_number_rec: ");
    print_number_rec(list2); // Ausgabe: 504
    printf("\nAusgabe print_number_iter: ");
    print_number_iter(list2); // Ausgabe: 504
    printf("\n");

    // Erzeugen einer verketteten Liste für die Zahl 12345
    struct linked_list *list3 = int_to_linked_list(12345);
    printf("Ausgabe print_linked_list: ");
    print_linked_list(list3); // Ausgabe: 54321
    printf("\nAusgabe print_number_rec: ");
    print_number_rec(list3); // Ausgabe: 12345
    printf("\nAusgabe print_number_iter: ");
    print_number_iter(list3); // Ausgabe: 12345
    printf("\n");

    // Aufräumen
    free_linked_list(list1);
    free_linked_list(list2);
    free_linked_list(list3);
    return EXIT_SUCCESS;
}
