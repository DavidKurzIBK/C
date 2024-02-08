#include <stdio.h>
#include <stdlib.h>

#define START_SYMBOL 'S'
#define END_SYMBOL 'E'
#define PATH_SYMBOL 'O'
#define FREE_SYMBOL ' '
#define ROWS 21
#define COLS 42


void print_grid(char grid[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS - 1; c++) {
            printf("%c ", grid[r][c]);
        }
        putchar('\n');
    }
}


int find_path(char grid[ROWS][COLS]) {
          /* TODO: Implement function logic */
}


int main(void) {
    char grid[ROWS][COLS] = {
            "+-------------+-+---+-------------+-----+",
            "|             | |S  |             |     |",
            "| +-----+---+ | + + | +-----+ +-+ +-+ +-+",
            "|       |   | |   | | |     | | |   |   |",
            "| +---+ | + | | +-+ + + +---+ | +-+ +-+ |",
            "| |   | | | | |   |     |     |   |     |",
            "+-+ + | | | | +---+-----+ +---+-+ +-+-+ |",
            "|   | | | | |     |       |       | |   |",
            "| +-+ + | | +---+ + +-----+-+ +-+ + | +-+",
            "|   |   | | |   |   |         | |   |   |",
            "+-+ +---+ +-+ + +-+-+ + +-+---+ +-+ +-+ |",
            "| | | |       |   |   |   |         |   |",
            "| + | | +-----+ + | +-+-+ | +---+---+ +-+",
            "|   | | |     | | | |     |     |   |   |",
            "+-+-+ | +---+ | | +-+ +---+---+ | + +-+ |",
            "| |   |       | |     |         | |   | |",
            "| + + +-----+ | | +---+-------+-+ | + | |",
            "|   |       | | | |           |   | | | |",
            "| +-+ +-----+ | +-+ +-------+ + +-+ +-+ |",
            "|   |         |     E       |     |     |",
            "+---+---------+-------------+-----+-----+",
    };
    print_grid(grid);
    printf("\nsolution found: %s\n", find_path(grid) ? "yes" : "no");
    print_grid(grid);
    return EXIT_SUCCESS;
}
