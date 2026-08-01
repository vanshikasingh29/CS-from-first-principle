#include <stdio.h>
#include <stdlib.h>

int main() {

    int my_number = 42;

    int *my_pointer = &my_number;

    printf("=== DAY 1 SYSTEM OVERVIEW ===\n");

    printf("1. The value inside my_number box is: %d\n", my_number);

    printf("2. The physical RAM hardware address of my_number is: %p\n", (void*)&my_number);

    printf("3. The address stored inside my_pointer box is: %p\n", (void*)my_pointer);

    printf("4. The value sitting at the address my_pointer points to is: %d\n", *my_pointer);


    *my_pointer = 999;


    printf("\n=== AFTER MEMORY CHANGE ===\n");

    printf("5. The value inside my_number is now magically: %d\n", my_number);


    return 0;
}