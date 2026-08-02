/*
    ============================================================
    Program: pointer_arithmetic.c

    Purpose:

    Demonstrate how pointers move through memory.

    Concepts:

    - Pointer addresses
    - Dereferencing
    - Arrays and pointers
    - Pointer increment/decrement
    - Memory spacing based on data type

    ============================================================
*/


#include <stdio.h>



int main(void)
{

    /*
        An integer array is stored as consecutive
        blocks of memory.

        Example:

        Address       Value

        1000          10
        1004          20
        1008          30


        Assuming an integer occupies 4 bytes.
    */
    int numbers[3] = {10, 20, 30};



    /*
        The array name represents the address
        of the first element.

        Therefore:

            numbers

        is equivalent to:

            &numbers[0]

    */
    int *pointer = numbers;



    printf("=== Pointer Arithmetic Demonstration ===\n\n");



    /*
        Current pointer location.

        The pointer stores the address
        of numbers[0].
    */
    printf("Pointer address: %p\n",
           (void *)pointer);



    /*
        Dereferencing retrieves the value
        stored at that address.

        Equivalent:

        numbers[0]

        and

        *pointer

        are the same operation.
    */
    printf("Value: %d\n\n",
           *pointer);




    /*
        Pointer arithmetic.

        Adding 1 does NOT increase the address
        by one byte.

        Instead:

            pointer + 1

        moves to the next integer.

        Example:

        Before:

        1000

        After:

        1004

    */
    pointer++;



    printf("After pointer++\n");

    printf("Pointer address: %p\n",
           (void *)pointer);


    printf("Value: %d\n\n",
           *pointer);




    /*
        Move again.

        Now the pointer points to:

            numbers[2]

    */
    pointer++;



    printf("After second pointer++\n");

    printf("Pointer address: %p\n",
           (void *)pointer);


    printf("Value: %d\n\n",
           *pointer);




    /*
        Moving backwards.

        Pointer arithmetic also supports:

            --
            -

    */
    pointer--;



    printf("After pointer--\n");

    printf("Value: %d\n",
           *pointer);



    /*
        Important:

        Pointer arithmetic only makes sense
        within the same allocated object.

        Moving outside an array boundary
        creates undefined behaviour.
    */


    return 0;
}