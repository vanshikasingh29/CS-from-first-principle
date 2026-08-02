/*
    ============================================================
    malloc.c


    Purpose:

    Demonstrate dynamic memory allocation
    using malloc().


    Concepts:

    - Heap memory
    - malloc()
    - sizeof()
    - Memory ownership
    - Allocation failure handling
    - free()

    ============================================================
*/


#include <stdio.h>
#include <stdlib.h>



int main(void)
{


    printf("=== Dynamic Memory Allocation ===\n\n");



    /*
        Normal stack allocation:

            int numbers[5];


        Size must be known at compile time.


        Dynamic allocation (manual) allows:

            Runtime decisions

    */


    int size = 5;




    /*
        Creating a pointer.

        At this moment:
            No memory exists on heap.

        The pointer only stores an address.

    */

    int *numbers;



    /*
        malloc requests memory from the heap.

        Calculation:

            sizeof(int) * size


        Example:

            4 bytes * 5

            = 20 bytes

        The heap provides this memory block.

    */

    numbers = malloc(sizeof(int) * size);





    /*
        malloc can fail.

        Always check.

        Failure returns:

            NULL

    */

    if(numbers == NULL)
    {

        printf("Memory allocation failed.\n");

        return 1;

    }





    printf("Memory allocated successfully.\n\n");



    /*
        Memory before initialisation:

        +----+----+----+----+----+
        | ?? | ?? | ?? | ?? | ?? |
        +----+----+----+----+----+


        malloc does not clear memory.

    */



    /*
        Writing values into heap memory.

    */

    for(int i = 0; i < size; i++)
    {

        numbers[i] = (i + 1) * 10;

    }





    printf("Values stored in heap:\n");



    for(int i = 0; i < size; i++)
    {

        printf(
            "numbers[%d] = %d\n",
            i,
            numbers[i]
        );

    }





    printf("\n");




    /*
        Heap memory diagram:


        Stack:

        +----------------+
        | numbers        |
        | address: 5000  |
        +----------------+

                 |
                 |
                 v


        Heap:

        Address 5000

        +----+----+----+----+----+
        |10  |20  |30  |40  |50  |
        +----+----+----+----+----+


    */





    /*
        Returning memory.

        Without this:

            memory leak


        The OS may reclaim memory after program termination,
        but long-running applications must manage this correctly.

    */

    free(numbers);





    /*
        After freeing:

            remove dangling pointer

    */

    numbers = NULL;



    printf("Memory released successfully.\n");



    return 0;
}