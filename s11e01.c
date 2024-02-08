#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE BUFFER_SIZE // hat nun Größe 16 von BUFFERSIZE
#define BUFFER_SIZE DIMENSION * DIMENSION // hat Größe 16 von DIMENSION 4 
#define DIMENSION 4

#define MIN(x, y) ((x) <= (y) ? (x) : (y))

#define POW2(x) x * x

#define MY_PRINT(n) printf("var" #n " = %d\n", var##n)

#define DEBUG 1

#define DEBUG_PRINT(...) printf("DEBUG: " __VA_ARGS__)


// Codeausschnitt 1
char *array = malloc(ARRAY_SIZE * sizeof(*array));


// Codeausschnitt 2
short a = 3;
printf("%d\n", MIN(MIN(a, '2'), 5));
printf("%f\n", MIN(4.0, 1.0));


//- Was wird durch diesen Codeausschnitt auf der Standardausgabe ausgegeben?
//- Kann das Makro `MIN` mit einer Funktion `min` mit Signatur `float min(float x, float y)` ersetzt werden, ohne sonstige Änderungen im Codeausschnitt durchzuführen?

// Codeausschnitt 3
printf("%d\n", POW2(2 + 2));

//- Was wird durch diesen Codeausschnitt auf der Standardausgabe ausgegeben?

// Codeausschnitt 4
int var60 = 50;
int var50 = 60;
MY_PRINT(60);


//- Was bewirken die Präprozessor-Operatoren `#` und `##`?
//- Was wird durch diesen Codeausschnitt auf der Standardausgabe ausgegeben?

// Codeausschnitt 5
#ifdef DEBUG
    printf("My debug messages\n");
#endif


//- Was wird durch diesen Codeausschnitt auf der Standardausgabe ausgegeben, wenn `DEBUG` definiert ist?
//- Was wird durch diesen Codeausschnitt auf der Standardausgabe ausgegeben, wenn `DEBUG` nicht definiert ist?

// Codeausschnitt 6


int x = 12;
int y = 61;
DEBUG_PRINT("x = %d, y = %d\n", x, y);

//- Was ist ein variadisches Makro?

