/*
    ============================================================
    bitwise.c


    Purpose:

    Demonstrate binary manipulation
    using bitwise operators.


    Concepts:

    - Binary representation
    - AND
    - OR
    - XOR
    - NOT
    - Left shift
    - Right shift
    - Bit masks
    - Flags
    ============================================================
*/


#include <stdio.h>
#include <stdint.h>





/*
    Function:
    print_binary


    Purpose:
    Display an integer as binary.


    Example:
    Number:
        5

    Binary:
        00000101

    This helps visualise what the CPU actually stores.

*/


void print_binary(uint8_t value)
{


    for(int i = 7; i >= 0; i--)
    {


        /*
            Create a mask.

            Example:

            10000000

            01000000

            etc.

        */

        uint8_t mask = 1 << i;



        /*
            AND checks whether
            the current bit is 1.

        */

        if(value & mask)
        {

            printf("1");

        }
        else
        {

            printf("0");

        }

    }


    printf("\n");

}



int main(void)
{


    printf("=== Bitwise Operations ===\n\n");



    uint8_t a = 12;

    uint8_t b = 10;




    /*
        Decimal:

            12

        Binary:

            00001100


        Decimal:

            10

        Binary:

            00001010

    */


    printf("a = ");

    print_binary(a);


    printf("b = ");

    print_binary(b);



    printf("\n=== AND Operation ===\n");



    /*
        AND:

        00001100

        00001010

        --------

        00001000


        Only bits that are 1 in both remain.

    */


    uint8_t and_result = a & b;


    print_binary(and_result);


    printf("\n=== OR Operation ===\n");



    /*
        OR:

        00001100

        00001010

        --------

        00001110


        Any bit that is 1 becomes 1.

    */


    uint8_t or_result = a | b;


    print_binary(or_result);


    printf("\n=== XOR Operation ===\n");



    /*
        XOR:

        00001100

        00001010

        --------

        00000110


        Different bits become 1.

    */


    uint8_t xor_result = a ^ b;


    print_binary(xor_result);




    printf("\n=== NOT Operation ===\n");



    /*
        NOT flips every bit.

        Example:

        00001100

        becomes

        11110011


        Because uint8_t is unsigned, only 8 bits are considered.

    */


    uint8_t not_result = (uint8_t)~a;


    print_binary(not_result);


    printf("\n=== Bit Shifting ===\n");



    uint8_t number = 5;



    printf("Original: ");

    print_binary(number);




    /*
        Left shift:

        00000101

        << 1

        00001010


        Equivalent:

        multiply by 2

    */

    uint8_t left_shift = number << 1;


    printf("Left shift: ");

    print_binary(left_shift);





    /*
        Right shift:

        00001010

        >> 1

        00000101


        Equivalent:

        divide by 2

    */


    uint8_t right_shift = left_shift >> 1;


    printf("Right shift: ");

    print_binary(right_shift);








    printf("\n=== Bit Masks ===\n");



    /*
        Masks allow specific bits
        to be changed.


        Example:

        Permission system:


        READ:

        00000001


        WRITE:

        00000010


        EXECUTE:

        00000100


    */



    const uint8_t READ = 1 << 0;

    const uint8_t WRITE = 1 << 1;

    const uint8_t EXECUTE = 1 << 2;




    uint8_t permissions = 0;



    /*
        Enable permissions.
        OR sets bits.

    */


    permissions |= READ;

    permissions |= WRITE;



    printf("Current permissions: ");

    print_binary(permissions);







    /*
        Checking a bit.

        AND determines whether a flag exists.

    */


    if(permissions & READ)
    {

        printf("Read permission enabled\n");

    }



    if(permissions & EXECUTE)
    {

        printf("Execute enabled\n");

    }
    else
    {

        printf("Execute disabled\n");

    }







    /*
        Removing a bit.

        AND with inverted mask.

    */


    permissions &= ~WRITE;



    printf("\nAfter removing WRITE: ");

    print_binary(permissions);






    /*
        Toggling a bit.

        XOR flips the bit.

    */


    permissions ^= EXECUTE;



    printf("After toggling EXECUTE: ");

    print_binary(permissions);






    printf("\n");



    return 0;

}