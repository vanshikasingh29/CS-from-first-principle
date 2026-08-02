/*
    ============================================================
    const_pointers.c


    Purpose:

    Demonstrate the three common forms of
    const pointer usage.

    Concepts:

    1. Pointer to constant data

    2. Constant pointer

    3. Constant pointer to constant data

    CRITICAL RULE FOR READING CONST POINTERS (Right-to-Left):
    1. const int *ptr       -> Pointer to a "const int"       [DATA IS LOCKED]
    2. int *const ptr       -> "const pointer" to an int      [ADDRESS IS LOCKED]
    3. const int *const ptr -> "const pointer" to a "const int"[BOTH ARE LOCKED]

    ============================================================
*/


#include <stdio.h>



int main(void)
{

    // Regular mutable variables stored on the stack
    int value_one = 10;
    int value_two = 20;
/*
        -----------------------------------------------------------------------
        CASE 1: Pointer to Constant Data (const int *ptr)
        -----------------------------------------------------------------------
        - Memory View: The data box is shielded, but the arrow can point elsewhere.
        - Rule: You cannot use this pointer to overwrite the value.
    */

    const int *pointer_one = &value_one;


    printf("Pointer to constant data:\n");

    printf("Value: %d\n\n",
           *pointer_one);



    // ALLOWED: Changing the destination address (moving the arrow)
    pointer_one = &value_two;


    /*
        Not allowed:   
             *pointer_one = 50;
        Because the data is protected through this pointer.
    */

   // COMPILER ERROR: Overwriting data through this pointer is banned



 /*
        -----------------------------------------------------------------------
        CASE 2: Constant Pointer (int *const ptr)
        -----------------------------------------------------------------------
        - Memory View: The arrow is glued to this address, but the data box is open.
        - Rule: You cannot change where this pointer points.
        -  Meaning:The address cannot change.The data can change.
    */

    int *const pointer_two = &value_one;


    printf("Constant pointer:\n");


    printf("Before: %d\n",
           *pointer_two);



     // ALLOWED: Overwriting the data at the locked address
    *pointer_two = 99;


    printf("After modification: %d\n\n",
           *pointer_two);



    /*
        Not allowed:
            pointer_two = &value_two;

        The pointer itself is constant.

    */
 // COMPILER ERROR (If uncommented): Reassigning the address is banned




    /*
        -----------------------------------------------------------------------
        CASE 3: Constant Pointer to Constant Data (const int *const ptr)
        -----------------------------------------------------------------------
        - Memory View: The arrow is glued AND the data box is shielded.
        - Rule: Complete system lockdown. Nothing can change.
        - Meaning: Meaning:Cannot move. Cannot modify data. Completely locked.
    */

    const int *const pointer_three = &value_two;


    printf("Constant pointer to constant data:\n");


    printf("Value: %d\n",
           *pointer_three);



    /*
        Neither of these are allowed:


        *pointer_three = 100;


        pointer_three = &value_one;


    */

    // COMPILER ERROR (*pointer_three = 100;): Modifying data is banned 

    // COMPILER ERROR (pointer_three = &value_one;If uncommented): Modifying address is banned

    return 0;
}