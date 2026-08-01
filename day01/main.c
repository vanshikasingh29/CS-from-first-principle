#include <stdio.h>
#include <stdlib.h>

int main() {

    int my_number = 42;

    int *my_pointer = &my_number;

    printf("=== DAY 1 SYSTEM OVERVIEW ===\n");

    printf("1. Value: %d\n", my_number);

    printf("2. Address: %p\n", (void*)&my_number);

    printf("3. Pointer stores: %p\n", (void*)my_pointer);

    printf("4. Pointer gives value: %d\n", *my_pointer);


    *my_pointer = 999;


    printf("\n=== AFTER MEMORY CHANGE ===\n");

    printf("5. New value: %d\n", my_number);


    return 0;
}