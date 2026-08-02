/*
    ============================================================

    strings.c


    Purpose:

    Demonstrate how C strings are stored
    and manipulated in memory.


    Concepts:

    - Character arrays
    - Null terminators
    - ASCII representation
    - String traversal
    - Safe string handling
    ============================================================
*/


#include <stdio.h>
#include <string.h>



int main(void)
{


    /*
        A C string is simply:

            Array of characters

        ending with:

            '\0'


        Memory:

        Index

        0  H
        1  e
        2  l
        3  l
        4  o
        5  \0


    */

    // Allocates 6 bytes in memory: 'H', 'e', 'l', 'l', 'o', and '\0'
    char message[] = "Hello";



    printf("=== C String Demonstration ===\n\n");



    /*
        strlen counts characters.

        It does NOT include the null terminator. '\0'

        Example:

        H e l l o \0

        length = 5

    */

   // strlen() counts printable characters only; it ignores the '\0'
    printf("String length: %zu\n\n",
           strlen(message));




    /*
        Accessing characters using indexing.

        Strings behave like arrays.

    */
    printf("Characters using indexing:\n");

    // Loops until it hits the hidden '\0' marker at the end
    for(int i = 0; message[i] != '\0'; i++)
    {

        printf(
            "Index %d: %c\n",
            i,
            message[i]
        );

    }



    printf("\n");




    //Accessing the same string using a pointer.
    //The string name represents the address of the first character.

   // 'pointer' stores the address of the first character ('H')
    char *pointer = message;



    printf("Characters using pointer traversal:\n");


    //Standard C pattern: process the character, then advance the pointer
    while(*pointer != '\0')
    {
        // Dereference the pointer to get the current character
        
        printf("%c\n", *pointer); // Read the character at current address
        pointer++; // Move forward by exactly 1 byte (sizeof char)

    }



    printf("\n");




    /*
        Demonstrating the null terminator.

        The final byte is not a visible
        character.

    */

    // Prints '0' because '\0' is just an alias for the number 0. Tells the string ends here 
    printf("Null terminator value: %d\n",
           message[5]);



    printf("\n");




   // Destination array must be large enough to hold the text + '\0'
    char copied[20];

    // Copies bytes from 'message' to 'copied' until it replicates the '\0'
    strcpy(copied, message);



    printf("Copied string: %s\n",
           copied);


   /*
        CRITICAL WARNING:
        strcpy() is dangerous. It does not check if the destination is too small.
        In modern code, use strncpy() or snprintf() to prevent memory corruption.
    */




    return 0;
}