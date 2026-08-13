# Topic 9 — Assembly Language

## CS From First Principles

Phase 2 — Systems Architecture

This lab introduces x86-64 assembly language and connects high-level programming concepts to CPU-level instructions.

---

## Learning Objectives

This lab explores:

- CPU registers
- arithmetic instructions
- memory operands
- stack operations
- function calls
- return values
- calling conventions
- the relationship between C and assembly

---

## Architecture

Target architecture:

x86-64

Assembler:

NASM

Operating system:

Linux

---

## Core Concepts

### Registers
x86-64 provides general-purpose registers including:

```
RAX
RBX
RCX
RDX
RSI
RDI
RSP
RBP
```
Registers provide extremely fast storage directly accessible by the CPU.

### Function Arguments

Under the System V AMD64 calling convention, integer/pointer arguments are passed using registers such as:
```
RDI
RSI
RDX
RCX
R8
R9
```
The return value is normally placed in:
```
RAX
```
Therefore a C function such as:
```
long add(long a, long b);
```
can conceptually map to:
```
RDI = a
RSI = b

RAX = result
```

### Stack

The stack is used for:

- function call state
- local data
- saved registers
- return addresses

Important registers include:

- RSP

- Stack pointer.

- RBP

- Frame/base pointer.