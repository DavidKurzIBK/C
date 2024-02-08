    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define MAX_LEN_NAME 64 // Konstante MAX_LEN_NAME definiert, die die maximale Länge des Hörsaalnamens festlegt.

    typedef struct lecture_hall {
        char name[MAX_LEN_NAME + 1];
        unsigned short size;
        unsigned short num_seats;
    } lecture_hall_t;


    /* 
    Datenstruktur lecture_hall_t wird definiert, die drei Mitglieder enthält: name, size und num_seats. 
    name ist ein Array von Zeichen, das den Namen des Hörsaals speichert, size ist die Größe des Hörsaals und num_seats 
    ist die Anzahl der Sitzplätze im Hörsaal.
    */

    void print_lecture_hall(const lecture_hall_t* hall) {
        printf("Name: %s, Size: %hu, Seats: %hu\n", hall->name, hall->size, hall->num_seats);
    }


    /*
    Im folgenden werden verschiedene Vergleichsfunktionen definiert, die als Parameter für die Sortierungsfunktion verwendet werden. 
    Diese Funktionen vergleichen zwei Hörsäle basierend auf ihrem Namen, ihrer Größe und ihrer Anzahl an Sitzplätzen.
    Folgende Arrays der Hörsääle werden in folgenden Funktnen mit vergleichsoperatoren sortiert.
    */

    int name_comparator(const void* a, const void* b) {
        const lecture_hall_t* hall_a = (const lecture_hall_t*)a;
        const lecture_hall_t* hall_b = (const lecture_hall_t*)b;
        return strcmp(hall_a->name, hall_b->name);
    }

    int size_comparator(const void* a, const void* b) {
        const lecture_hall_t* hall_a = (const lecture_hall_t*)a;
        const lecture_hall_t* hall_b = (const lecture_hall_t*)b;
        return hall_a->size - hall_b->size;
    }

    int num_seats_comparator(const void* a, const void* b) {
        const lecture_hall_t* hall_a = (const lecture_hall_t*)a;
        const lecture_hall_t* hall_b = (const lecture_hall_t*)b;
        return hall_a->num_seats - hall_b->num_seats;
    }

    int lecture_hall_comparator(const void* a, const void* b) {
        const lecture_hall_t* hall_a = (const lecture_hall_t*)a;
        const lecture_hall_t* hall_b = (const lecture_hall_t*)b;

        if (hall_a->num_seats == hall_b->num_seats) {
            return hall_a->size - hall_b->size;
        }
        return hall_a->num_seats - hall_b->num_seats;
    }

/*
sort_lecture_halls wird definiert, um ein Array von Hörsälen mithilfe eines gegebenen Vergleichsfunktionszeigers zu sortieren. 
Sie verwendet die qsort-Funktion aus der Standardbibliothek, um das Array zu sortieren.
*/
    void sort_lecture_halls(lecture_hall_t* lecture_halls, const size_t num_lecture_halls, int (*comparator)(const void*, const void*)) {
        qsort(lecture_halls, num_lecture_halls, sizeof(lecture_hall_t), comparator);
    }

/* 
main-Funktion wird definiert. In dieser Funktion werden Beispieldaten für Hörsäle erstellt und verschiedene Sortierungen durchgeführt.
*/

    int main() {
        // Beispiel-Hörsäle
        lecture_hall_t halls[] = {
            {"Hörsaal 1", 100, 150},
            {"Hörsaal 2", 80, 120},
            {"Hörsaal 3", 120, 100},
            {"Hörsaal 4", 150, 100}
        };
        size_t num_halls = sizeof(halls) / sizeof(lecture_hall_t);

        // Unsortierte Ausgabe
        printf("Unsorted Halls:\n");
        for (size_t i = 0; i < num_halls; i++) {
            print_lecture_hall(&halls[i]);
        }

        // Sortieren nach Namen
        sort_lecture_halls(halls, num_halls, name_comparator);
        printf("\nSorted by Name:\n");
        for (size_t i = 0; i < num_halls; i++) {
            print_lecture_hall(&halls[i]);
        }

        // Sortieren nach Größe
        sort_lecture_halls(halls, num_halls, size_comparator);
        printf("\nSorted by Size:\n");
        for (size_t i = 0; i < num_halls; i++) {
            print_lecture_hall(&halls[i]);
        }
        // Sortieren nach Anzahl der Sitzplätze
        sort_lecture_halls(halls, num_halls, num_seats_comparator);
        printf("\nSorted by Num Seats:\n");
        for (size_t i = 0; i < num_halls; i++) {
            print_lecture_hall(&halls[i]);
        }

        // Sortieren nach Hörsaaldaten
        sort_lecture_halls(halls, num_halls, lecture_hall_comparator);
        printf("\nSorted by Lecture Hall Data:\n");
        for (size_t i = 0; i < num_halls; i++) {
            print_lecture_hall(&halls[i]);
        }

        return 0;
    }

