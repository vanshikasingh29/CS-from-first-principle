/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 7 — Bit-Level Arithmetic

File:
bit_arithmetic.h

Purpose:
Public interface for bit-level arithmetic operations.

============================================================
*/

#ifndef BIT_ARITHMETIC_H
#define BIT_ARITHMETIC_H

#include <stdint.h>
#include <stddef.h>


/*
============================================================
Basic Bitwise Operations
============================================================
*/

uint32_t bitwise_and(
    uint32_t a,
    uint32_t b
);

uint32_t bitwise_or(
    uint32_t a,
    uint32_t b
);

uint32_t bitwise_xor(
    uint32_t a,
    uint32_t b
);

uint32_t bitwise_not(
    uint32_t value
);


/*
============================================================
Bit Shifting
============================================================
*/

uint32_t shift_left(
    uint32_t value,
    unsigned int positions
);

uint32_t shift_right(
    uint32_t value,
    unsigned int positions
);


/*
============================================================
Individual Bit Operations
============================================================
*/

uint32_t set_bit(
    uint32_t value,
    unsigned int position
);

uint32_t clear_bit(
    uint32_t value,
    unsigned int position
);

uint32_t toggle_bit(
    uint32_t value,
    unsigned int position
);

int test_bit(
    uint32_t value,
    unsigned int position
);


/*
============================================================
Bit Counting
============================================================
*/

unsigned int count_set_bits(
    uint32_t value
);


/*
============================================================
Binary Display
============================================================
*/

void print_binary(
    uint32_t value
);

#endif
