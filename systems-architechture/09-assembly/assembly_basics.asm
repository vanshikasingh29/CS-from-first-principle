; ============================================================
;
; CS From First Principles
;
; Phase 2 — Systems Architecture
;
; Topic 9 — Assembly Language
;
; File:
; assembly_basics.asm
;
; Purpose:
; Demonstrate basic x86-64 assembly concepts.
;
; Architecture:
; x86-64
;
; Assembler:
; NASM
;
; Calling convention:
; System V AMD64
;
; ============================================================

global add_numbers
global multiply_numbers
global factorial
global stack_demo


; ============================================================
; add_numbers
;
; C equivalent:
;
; long add_numbers(long a, long b)
; {
;     return a + b;
; }
;
; Arguments:
;
; RDI = a
; RSI = b
;
; Return:
;
; RAX = a + b
;
; ============================================================

section .text

add_numbers:

    mov rax, rdi

    add rax, rsi

    ret


; ============================================================
; multiply_numbers
;
; C equivalent:
;
; long multiply_numbers(long a, long b)
; {
;     return a * b;
; }
;
; ============================================================

multiply_numbers:

    mov rax, rdi

    imul rax, rsi

    ret


; ============================================================
; factorial
;
; C equivalent:
;
; long factorial(long n)
; {
;     long result = 1;
;
;     while (n > 1)
;     {
;         result *= n;
;         n--;
;     }
;
;     return result;
; }
;
; RDI = n
; RAX = result
;
; ============================================================

factorial:

    mov rax, 1


factorial_loop:

    cmp rdi, 1

    jle factorial_done

    imul rax, rdi

    dec rdi

    jmp factorial_loop


factorial_done:

    ret


; ============================================================
; stack_demo
;
; Demonstrates:
;
; push
; pop
;
; The value returned in RAX is preserved through a stack
; operation.
;
; ============================================================

stack_demo:

    mov rax, 42

    push rax

    mov rax, 0

    pop rax

    ret