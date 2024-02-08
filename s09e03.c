#define MAX_LEN_NAME 64

typedef struct lecture_hall {
    char name[MAX_LEN_NAME + 1];
    unsigned short size;
    unsigned short num_seats;
} lecture_hall_t;
