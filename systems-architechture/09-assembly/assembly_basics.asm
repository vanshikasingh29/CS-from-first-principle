/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 9 — Assembly Language

File:
assembly_basics.asm

Purpose:
Demonstrate basic x86-64 assembly concepts.

Assembler:
GNU Assembler syntax

Architecture:
x86-64

Calling convention:
System V AMD64

============================================================
*/

    .text


/*
============================================================
add_numbers

C equivalent:

long add_numbers(long a, long b)
{
    return a + b;
}

System V AMD64:

RDI = first argument
RSI = second argument
RAX = return value

============================================================
*/

    .globl add_numbers
    .type add_numbers, @function

add_numbers:

    movq %rdi, %rax
    addq %rsi, %rax

    ret


/*
============================================================
multiply_numbers

C equivalent:

long multiply_numbers(long a, long b)
{
    return a * b;
}

============================================================
*/

    .globl multiply_numbers
    .type multiply_numbers, @function

multiply_numbers:

    movq %rdi, %rax
    imulq %rsi, %rax

    ret


/*
============================================================
factorial

C equivalent:

long factorial(long n)
{
    long result = 1;

    while (n > 1)
    {
        result *= n;
        n--;
    }

    return result;
}

RDI = n
RAX = result

============================================================
*/

    .globl factorial
    .type factorial, @function

factorial:

    movq $1, %rax


factorial_loop:

    cmpq $1, %rdi

    jle factorial_done

    imulq %rdi, %rax

    decq %rdi

    jmp factorial_loop


factorial_done:

    ret


/*
============================================================
stack_demo

Demonstrates:

push
pop

The value is stored on the stack and then restored.

============================================================
*/

    .globl stack_demo
    .type stack_demo, @function

stack_demo:

    movq $42, %rax

    pushq %rax

    movq $0, %rax

    popq %rax

    ret


/*
============================================================
End of assembly file
============================================================
*/