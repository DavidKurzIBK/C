#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // Hinzugefügt für die Verwendung von tolower()
#include "my_list.h"

#define MAX_LINE_LENGTH 80

int is_word_separator(char c) {
    char separators[] = " \n\t?!.,;:()";
    size_t separators_count = strlen(separators);  // Verwende size_t für die Schleifenvariable
    for (size_t i = 0; i < separators_count; i++) {
        if (c == separators[i]) {
            return 1;
        }
    }
    return 0;
}

void count_words_in_file(const char *filename, my_list *word_list) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Fehler beim Öffnen der Datei: %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *word = strtok(line, " \n\t?!.,;:()");
        while (word != NULL) {
            for (int i = 0; word[i]; i++) {
                word[i] = tolower((unsigned char)word[i]);  // Nutze tolower() und cast zu unsigned char
            }

            int word_found = 0;
            for (size_t i = 0; i < my_list_size(word_list); i++) {
                char *existing_word = (char *)my_list_get(word_list, i);
                if (strcmp(word, existing_word) == 0) {
                    word_found = 1;
                    break;
                }
            }

            if (!word_found) {
                size_t word_length = strlen(word);
                char *new_word = malloc((word_length + 1) * sizeof(char));
                if (new_word == NULL) {
                    fprintf(stderr, "Speicher konnte nicht zugewiesen werden.\n");
                    exit(1);
                }
                strcpy(new_word, word);
                my_list_append(word_list, new_word);
            }

            word = strtok(NULL, " \n\t?!.,;:()");
        }
    }

    fclose(file);
}

int word_comparator(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void print_word_count_table(my_list *word_list) {
    printf("Word     Count\n");
    printf("--------------\n");

    my_list_sort(word_list, word_comparator);

    for (size_t i = 0; i < my_list_size(word_list); i++) {
        char *word = (char *)my_list_get(word_list, i);
        printf("%-10s %d\n", word, 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Verwendung: %s <Dateiname>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    my_list *word_list = my_list_init();

    count_words_in_file(filename, word_list);
    print_word_count_table(word_list);

    my_list_free(word_list);

    return 0;
}
