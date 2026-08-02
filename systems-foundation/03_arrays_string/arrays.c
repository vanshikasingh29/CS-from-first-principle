/*
    ===========================================================
    Program:

    arrays.c

    Purpose:
    Demonstrate how arrays are stored in memory
    and how they relate to pointers.


    Concepts:

    - Contiguous memory
    - Array indexing
    - Pointer arithmetic
    - Address traversal
    - Array decay into pointers

    ============================================================
*/


#include <stdio.h>



int main(void)
{

    /*
        Creating an integer array.

        The compiler reserves a continuous
        block of memory.

        Allocates 16 continuous bytes (4 items x 4 bytes each) in RAM

        Memory example:

        Address       Value

        1000          10
        1004          20
        1008          30
        1012          40

    */

    int numbers[4] = {10, 20, 30, 40};



    printf("=== Array Memory Demonstration ===\n\n");



    /*
        The array name represents the address
        of the first element.

        Therefore 'numbers' is equivalent to:
            &numbers[0]

    */

    printf("Array starting address:\n");

    printf("%p\n\n",
           (void *)numbers);




    /*
        Normal array indexing.

        Internally: numbers[i]   becomes:
            *(numbers + i)

    */
    printf("Access using indexing:\n");

    for(int i = 0; i < 4; i++)
    {
        printf("numbers[%d] = %d\n",
               i,
               numbers[i]);
    }


// 'pointer' copies the starting address from 'numbers'
    printf("\n");



    /*
        Accessing the same array using pointers.

        A pointer stores the address
        of the first element.

    */
    int *pointer = numbers;



    printf("Access using pointer arithmetic:\n");



    for(int i = 0; i < 4; i++)
    {
        // pointer + i moves forward by (i * 4) bytes automatically
        // *(pointer + i) dereferences that address to read the value

        printf(
            "Address: %p  Value: %d\n",
            (void *)(pointer + i),
            *(pointer + i)
        );

    }



    printf("\n");



    
       // Demonstrating that changing values through a pointer changes the array.
       // The pointer refers to the same memory.
       // Target the address of the second item and overwrite its data box
    *(pointer + 1) = 999;


    // Verifies that modifying memory via the pointer changes the array directly
    printf("After pointer modification:\n");
    printf("numbers[1] = %d\n",
           numbers[1]);



    /*
        The array was modified because:
            pointer + 1
        points to:
            numbers[1]
    */



    return 0;
}