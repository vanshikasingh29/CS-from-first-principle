/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 7 — Bit-Level Arithmetic

File:
bit_arithmetic.c

Purpose:
Implements low-level bit manipulation operations.

============================================================
*/

#include <stdio.h>
#include <stdint.h>

#include "bit_arithmetic.h"


/*
============================================================
Basic Bitwise AND

AND produces 1 only when both corresponding bits are 1.

Example:

1010
1100
----
1000

============================================================
*/

uint32_t bitwise_and(
    uint32_t a,
    uint32_t b
)
{
    return a & b;
}


/*
============================================================
Basic Bitwise OR

OR produces 1 when at least one corresponding bit is 1.

============================================================
*/

uint32_t bitwise_or(
    uint32_t a,
    uint32_t b
)
{
    return a | b;
}


/*
============================================================
Basic Bitwise XOR

XOR produces 1 when the corresponding bits differ.

============================================================
*/

uint32_t bitwise_xor(
    uint32_t a,
    uint32_t b
)
{
    return a ^ b;
}


/*
============================================================
Bitwise NOT

Flips every bit.

0 -> 1
1 -> 0

============================================================
*/

uint32_t bitwise_not(
    uint32_t value
)
{
    return ~value;
}


/*
============================================================
Left Shift

Moves bits toward the most significant side.

For unsigned integers:

value << n

is equivalent to multiplication by 2^n
when no significant bits are discarded.

============================================================
*/

uint32_t shift_left(
    uint32_t value,
    unsigned int positions
)
{
    if (positions >= 32)
    {
        return 0;
    }

    return value << positions;
}


/*
============================================================
Right Shift

Moves bits toward the least significant side.

Unsigned integers use logical right shifting,
meaning zeros are introduced from the left.

============================================================
*/

uint32_t shift_right(
    uint32_t value,
    unsigned int positions
)
{
    if (positions >= 32)
    {
        return 0;
    }

    return value >> positions;
}


/*
============================================================
Set Bit

Sets the bit at position to 1.

Example:

value      = 00001000
position   = 2

mask       = 00000100

result     = 00001100

============================================================
*/

uint32_t set_bit(
    uint32_t value,
    unsigned int position
)
{
    if (position >= 32)
    {
        return value;
    }

    return value | (UINT32_C(1) << position);
}


/*
============================================================
Clear Bit

Sets the selected bit to 0.

============================================================
*/

uint32_t clear_bit(
    uint32_t value,
    unsigned int position
)
{
    if (position >= 32)
    {
        return value;
    }

    return value & ~(UINT32_C(1) << position);
}


/*
============================================================
Toggle Bit

Flips the selected bit.

1 -> 0
0 -> 1

============================================================
*/

uint32_t toggle_bit(
    uint32_t value,
    unsigned int position
)
{
    if (position >= 32)
    {
        return value;
    }

    return value ^ (UINT32_C(1) << position);
}


/*
============================================================
Test Bit

Returns:

1 if the selected bit is set
0 otherwise

============================================================
*/

int test_bit(
    uint32_t value,
    unsigned int position
)
{
    if (position >= 32)
    {
        return 0;
    }

    return
        (value & (UINT32_C(1) << position)) != 0;
}


/*
============================================================
Count Set Bits

Counts the number of 1 bits.

This implementation uses Brian Kernighan's algorithm.

Each iteration removes the lowest set bit:

x = x & (x - 1)

Therefore the loop executes once per set bit.

============================================================
*/

unsigned int count_set_bits(
    uint32_t value
)
{
    unsigned int count = 0;

    while (value != 0)
    {
        value &= value - 1;

        count++;
    }

    return count;
}


/*
============================================================
Print Binary

Displays all 32 bits of the unsigned integer.

============================================================
*/

void print_binary(
    uint32_t value
)
{
    for (int i = 31; i >= 0; i--)
    {
        uint32_t bit =
            (value >> i) & UINT32_C(1);

        printf(
            "%u",
            bit
        );

        /*
        Add spacing between groups of 8 bits
        to make the representation easier to read.
        */

        if (i % 8 == 0 && i != 0)
        {
            printf(" ");
        }
    }

    printf("\n");
}