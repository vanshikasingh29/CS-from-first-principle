/*
    ============================================================
    Program: stack_vs_heap.c

    Purpose:
    Demonstrate the fundamental difference between:

        1. Stack memory
        2. Heap memory

    Concepts demonstrated:

    - Automatic memory allocation
    - Dynamic memory allocation
    - Variable lifetime
    - Address inspection
    - malloc()
    - free()
    - Pointer usage

    ============================================================
*/


#include <stdio.h>
#include <stdlib.h>


/*
    Function: stack_example

    Demonstrates stack allocation.

    Variables created inside a function are stored
    inside that function's stack frame.

    When this function returns:

        - the stack frame disappears
        - local variables are destroyed

*/
void stack_example(void)
{
    /*
        Local variables are automatically allocated.

        The programmer does not request memory.

        The compiler creates space on the stack
        when entering this function.
    */
    int stack_number = 42;


    printf("\n--- STACK MEMORY EXAMPLE ---\n");


    /*
        The '&' operator retrieves the memory address
        of the variable.

        This address belongs to the stack region.
    */
    printf("Value stored: %d\n", stack_number);

    printf("Memory address: %p\n",
           (void *)&stack_number);


    /*
        Once this function ends,
        stack_number no longer exists.

        Accessing it afterwards would be undefined behaviour.
    */
}


/*
    Function: heap_example

    Demonstrates heap allocation.

    Heap memory is manually controlled by the programmer.

    Lifecycle:

        malloc()
            |
            v
        Use memory
            |
            v
        free()

*/
void heap_example(void)
{
    printf("\n--- HEAP MEMORY EXAMPLE ---\n");


    /*
        malloc requests memory from the heap.

        sizeof(int) ensures we allocate enough bytes
        for an integer on the current architecture.

        malloc returns:

            - address of allocated memory
            - NULL if allocation fails
    */
    int *heap_number = malloc(sizeof(int));


    /*
        Always check whether allocation succeeded.

        Memory allocation can fail.
    */
    if (heap_number == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }


    /*
        Store a value inside the allocated memory.

        Dereferencing (*) follows the pointer
        and accesses the memory location.
    */
    *heap_number = 99;


    printf("Value stored: %d\n",
           *heap_number);


    printf("Memory address: %p\n",
           (void *)heap_number);


    /*
        Heap memory survives after the function
        that created it finishes.

        However, the programmer is responsible
        for releasing it.
    */
    free(heap_number);


    /*
        Good practice:

        After freeing memory, remove the possibility
        of accidentally using the old address.
    */
    heap_number = NULL;
}


/*
    Main program entry point.
*/
int main(void)
{

    printf("CS Foundations\n");
    printf("Stack vs Heap Demonstration\n");


    /*
        The stack example creates temporary memory.
    */
    stack_example();


    /*
        The heap example creates programmer-controlled memory.
    */
    heap_example();


    printf("\nProgram finished successfully.\n");


    return 0;
}