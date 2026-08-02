/*
    ============================================================
    Program: memory_layout.c

    Purpose:

    Observe the approximate locations of:

        - Text segment
        - Data segment
        - BSS segment
        - Heap
        - Stack


    Important:

    The exact addresses are different every execution.

    Modern operating systems use:

        ASLR
        (Address Space Layout Randomization)

    to make memory attacks harder.
    ============================================================
*/


#include <stdio.h>
#include <stdlib.h>


/*
    DATA SEGMENT

    Global variables with initial values
    are stored here.
    Used for the entire program execution
*/
int global_initialized = 100;


/*
    BSS SEGMENT

    Global variables without explicit
    initial values are stored here.

    The operating system automatically
    initializes them to zero.
*/
int global_uninitialized;


/*
    TEXT SEGMENT

    Functions are stored as machine instructions.

    The function itself has an address
    inside the executable code region.
*/
void example_function(void)
{
    printf("Inside example function.\n");
}



int main(void)
{

    /*
        STACK SEGMENT

        Local variables belong to
        the current function stack frame.
    */
    int stack_variable = 50;


    /*
        HEAP SEGMENT

        malloc requests memory dynamically.

        The returned pointer stores
        the address of heap memory.
    */
    int *heap_variable = malloc(sizeof(int));


    if (heap_variable == NULL)
    {
        printf("Heap allocation failed.\n");
        return 1;
    }


    *heap_variable = 200;



    printf("\n===== MEMORY ADDRESS MAP =====\n");


    /*
        TEXT SEGMENT

        Printing the address of a function.

        This represents executable code.
    */
    printf("\nText Segment:\n");

    printf("Function address:\t%p\n",
           (void *)example_function);



    /*
        DATA SEGMENT

        Initialized global variable.
    */
    printf("\nData Segment:\n");

    printf("Initialized global:\t%p\n",
           (void *)&global_initialized);



    /*
        BSS SEGMENT

        Uninitialized global variable.
    */
    printf("\nBSS Segment:\n");

    printf("Uninitialized global:\t%p\n",
           (void *)&global_uninitialized);



    /*
        HEAP SEGMENT

        Memory created with malloc().
    */
    printf("\nHeap Segment:\n");

    printf("Heap variable:\t\t%p\n",
           (void *)heap_variable);



    /*
        STACK SEGMENT

        Local variables created inside main.
    */
    printf("\nStack Segment:\n");

    printf("Stack variable:\t\t%p\n",
           (void *)&stack_variable);



    /*
        Release heap memory.

        Every malloc requires
        a matching free.
    */
    free(heap_variable);



    /*
        Avoid dangling pointers.

        The pointer no longer points
        to valid memory.
    */
    heap_variable = NULL;



    printf("\nMemory demonstration complete.\n");


    return 0;
}