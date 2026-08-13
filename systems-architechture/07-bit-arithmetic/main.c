/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 7 — Bit-Level Arithmetic

File:
main.c

Purpose:
Demonstrates bit-level arithmetic operations.

============================================================
*/

#include <stdio.h>
#include <stdint.h>

#include "bit_arithmetic.h"


int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Bit-Level Arithmetic Demonstration\n");
    printf("========================================\n\n");


    /*
    --------------------------------------------------------
    Basic bitwise operations
    --------------------------------------------------------
    */

    uint32_t a = 12;
    uint32_t b = 10;


    printf("1. Basic bitwise operations\n\n");


    printf("a = %u\n", a);
    printf("a = ");
    print_binary(a);


    printf("b = %u\n", b);
    printf("b = ");
    print_binary(b);


    printf("\na AND b = %u\n",
        bitwise_and(a, b)
    );


    printf("a OR  b = %u\n",
        bitwise_or(a, b)
    );


    printf("a XOR b = %u\n",
        bitwise_xor(a, b)
    );


    /*
    --------------------------------------------------------
    Shift operations
    --------------------------------------------------------
    */

    printf("\n2. Bit shifting\n\n");


    uint32_t value = 3;


    printf(
        "3 << 2 = %u\n",
        shift_left(value, 2)
    );


    printf(
        "12 >> 2 = %u\n",
        shift_right(12, 2)
    );


    /*
    --------------------------------------------------------
    Individual bit operations
    --------------------------------------------------------
    */

    printf("\n3. Individual bit operations\n\n");


    uint32_t bits = 8;


    printf("Original: ");
    print_binary(bits);


    bits = set_bit(bits, 1);


    printf("After setting bit 1: ");
    print_binary(bits);


    bits = clear_bit(bits, 3);


    printf("After clearing bit 3: ");
    print_binary(bits);


    bits = toggle_bit(bits, 0);


    printf("After toggling bit 0: ");
    print_binary(bits);


    /*
    --------------------------------------------------------
    Test individual bit
    --------------------------------------------------------
    */

    printf("\n4. Testing bits\n\n");


    printf(
        "Bit 3 is %s\n",
        test_bit(bits, 3)
            ? "set"
            : "clear"
    );


    printf(
        "Bit 1 is %s\n",
        test_bit(bits, 1)
            ? "set"
            : "clear"
    );


    /*
    --------------------------------------------------------
    Count set bits
    --------------------------------------------------------
    */

    printf("\n5. Counting set bits\n\n");


    uint32_t number = 29;


    printf(
        "Number: %u\n",
        number
    );


    printf(
        "Binary: "
    );


    print_binary(number);


    printf(
        "Set bits: %u\n",
        count_set_bits(number)
    );


    printf(
        "\nBit-level arithmetic demonstration complete.\n"
    );


    return 0;
}