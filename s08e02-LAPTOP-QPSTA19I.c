#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char values[] = "0123456789";       //character array values is declared and initialized with the string "0123456789". 
    char *p1 = values;                  //pointers p1 and p2 are then declared, p1 is assigned the address of the first element of values,
    char *p2 = values + strlen(values); //p2 is assigned the address of the last element of values by adding the length of the string values to the base address.
    printf("1. %c\n", *(p1 + 4));       // A.
    printf("2. %c\n", *p2);             // B.
    printf("3. %d\n", p1 < p2);         // C.
    printf("4. %d\n", (p1 + 2) < (p2 - 4)); // D. 
    printf("5. %d\n", (((int32_t *)p1) + 2) < (int32_t *)(p2 - 4)); // E.
    printf("6. %td\n", p2 - p1);                                    // F.
    return EXIT_SUCCESS;
}


/*
A. prints value at the memory location p1 + 4 -> p1 points to the first element of values, p1 + 4 points to the fifth element, 
which is '4'. Therefore, it will output "1. 4".

B. prints the value at the memory location p2. 
p2 points to the last element of values, which is '9'. 
Therefore, it will output "2. 9".

C. compares the memory addresses pointed to by p1 and p2. 
p1 points to the first element of values and p2 points to the last element, 
the condition p1 < p2 evaluates to true == 1. Therefore, it will output "3. 1".

D. compares the memory addresses resulting from pointer arithmetic. 
(p1 + 2) points to the third element of values, while (p2 - 4) points to the sixth element. 
memory address of the third element is lower than the memory address of the sixth element, 
the condition (p1 + 2) < (p2 - 4) evaluates to true == 1. Therefore, it will output "4. 1".

E. demonstrates pointer casting. p1 is cast to a pointer to int32_t and then incremented by 2. 
(p2 - 4) is cast to a pointer to int32_t. comparison is then performed between the two pointers. 
output of this line depends on the size of int32_t and the difference between the memory addresses of p1 and p2, 
in this case again it's true == 1; 

F. calculates the difference between the memory addresses pointed to by p2 and p1 and prints the result using the %td format specifier. 
p2 points to the last element of values and p1 points to the first element, the difference between their 
memory addresses is equal to the length of values (including the null terminator). 
Therefore, it will output "6. 10" (assuming the null terminator is included in the length calculation).*/
