/*
    ============================================================
    realloc.c


    Purpose:

    Demonstrate resizing heap memory.


    Concepts:

    - Dynamic arrays
    - realloc()
    - Memory resizing
    - Pointer replacement
    - Safe allocation patterns
    ============================================================
*/


#include <stdio.h>
#include <stdlib.h>



int main(void)
{


    printf("=== Dynamic Resizing Demonstration ===\n\n");



    //Initial array size.
    int size = 3;




    //Allocate initial memory.
    int *numbers = malloc(
        sizeof(int) * size
    );



    if(numbers == NULL)
    {

        printf("Initial allocation failed.\n");

        return 1;

    }




    // Store initial values.

    numbers[0] = 10;

    numbers[1] = 20;

    numbers[2] = 30;




    printf("Initial array:\n");



    for(int i = 0; i < size; i++)
    {

        printf("%d\n",
               numbers[i]);

    }




    printf("\n");





    /*
        Increase required size.

        Old:

        +----+----+----+
        |10  |20  |30  |
        +----+----+----+


        New:

        +----+----+----+----+----+
        |10  |20  |30  |40  |50  |
        +----+----+----+----+----+

    */


    int new_size = 5;





    /*
        Important:

        Do not directly do:


            numbers = realloc(numbers,...)


        because if realloc fails,
        the original pointer is lost.


        Safer method:

            temporary pointer

    */


    int *temporary = realloc(
        numbers,
        sizeof(int) * new_size
    );





    if(temporary == NULL)
    {

        printf("Reallocation failed.\n");


        //Original memory still exists.
        free(numbers);


        return 1;

    }





    // Update pointer only after success.

    numbers = temporary;





    // Add new values.

    numbers[3] = 40;

    numbers[4] = 50;





    printf("Resized array:\n");



    for(int i = 0; i < new_size; i++)
    {

        printf("%d\n",
               numbers[i]);

    }




    printf("\n");





    // Final memory release.

    free(numbers);

    numbers = NULL;

    printf("Memory released.\n");



    return 0;
}