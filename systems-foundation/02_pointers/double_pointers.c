/*
    ============================================================
    Program:
    double_pointers.c


    Purpose:

    Demonstrate pointers to pointers.

    Concepts:

    - Multiple levels of indirection
    - Memory addresses
    - Modifying pointers inside functions
    - Relationship between variables and addresses

    ============================================================
*/


#include <stdio.h>



int main(void)
{

    int number = 42;



    
//   Normal pointer - Stores the address of number.
    int *pointer = &number;



// Double pointer. - Stores the address of another pointer.

    int **double_pointer = &pointer;




    printf("=== Double Pointer Demonstration ===\n\n");




    printf("Number value:\n");

    printf("%d\n\n",
           number);



    printf("Pointer stores address:\n");

    printf("%p\n\n",
           (void *)pointer);



    printf("Double pointer stores pointer address:\n");

    printf("%p\n\n",
           (void *)double_pointer);




    /*
        Levels of access:


        number

            42


        pointer

            address of number


        double_pointer

            address of pointer



        Diagram:


        double_pointer
              |
              v

        +-------------+
        | pointer     |
        +-------------+
              |
              v

        +-------------+
        | number 42   |
        +-------------+

    */




    /*
        Accessing number directly:

    */
    printf("Direct value:\n");

    printf("%d\n\n",
           number);




    /*
        Accessing through pointer:

    */
    printf("Single dereference:\n");

    printf("%d\n\n",
           *pointer);




    /*
        Accessing through double pointer:


        First *:

            gets pointer


        Second *:

            gets number


    */
    printf("Double dereference:\n");

    printf("%d\n",
           **double_pointer);



    return 0;
}