# 02 — Pointers

> Understanding direct memory manipulation in C.

---

# Overview

Pointers are one of the defining features of the C programming language.

Unlike many modern languages that hide memory addresses behind abstractions, C allows programmers to directly interact with memory.

A pointer is not simply a variable that stores data.

A pointer stores:

```
The memory address of another object
```

This allows programs to:

- Modify memory directly
- Build complex data structures
- Manage dynamic memory
- Communicate efficiently with hardware
- Interact with operating systems

---

# Why Pointers Matter

Pointers are fundamental to:

- Operating systems
- Embedded systems
- Game engines
- Databases
- Compilers
- Network programming
- High-performance computing

Examples:

Linux kernel:

```
C code
 ↓
Pointers
 ↓
Memory addresses
 ↓
Hardware resources
```
C Code: You write abstract logic and variables (e.g., int x = 5;).

Pointers: The compiler translates those variables into variables that hold locations instead of values (e.g., int *ptr = &x;).

Memory Addresses: The CPU interprets pointers as numeric indexes (like 0x7FFF1234) representing specific bytes in Virtual Memory.

Hardware Resources: The Linux Kernel and the CPU’s Memory Management Unit (MMU) map that virtual address to a physical electrical circuit on a RAM stick or a hardware register to read or write the actual data.

---


# Learning Objectives

After completing this chapter, you should understand:

- What an address is
- What a pointer stores
- Dereferencing
- Address-of operator
- Pointer arithmetic
- Pointer types
- Constant pointers
- Pointers to pointers
- Why arrays and pointers are connected

---

# Files

| File | Purpose |
|-|-|
| notes.md | Theory and memory concepts |
| pointer_arithmetic.c | Moving through memory using pointers |
| const_pointers.c | Understanding pointer restrictions |
| double_pointers.c | Understanding pointers to pointers |

---

# Basic Pointer Model

Dereferencing is the act of accessing the actual data stored at the memory address held by a pointer.

Think of a pointer as a address written on a piece of paper; dereferencing is the act of actually walking to that house and looking inside.

Example:

```c
int value = 10;

int *pointer = &value;
```
How it Works in C-

The Pointer: int *ptr = &x; (Stores the memory address of x).

The Dereference: int value = *ptr; (Uses the * operator to go to that address and grab the value).

Memory:

```
value

+---------+
|   10    |
+---------+
    |
    |
    v

pointer

+---------+
| address |
+---------+

```

The pointer does not contain 10.

It contains the location where 10 exists.

---

---

# Common Pointer Errors

## Dereferencing NULL

Bad:

```c
int *ptr = NULL;

*ptr = 10;
```

The program attempts to access invalid memory.

---

## Dangling pointers

Example:

```c
free(ptr);

*ptr = 5;
```

The address exists.

The memory does not.

---

## Uninitialised pointers

Bad:

```c
int *ptr;

*ptr = 100;
```

The pointer contains a random address.

---

# Why This Folder Exists

Pointers are the foundation for:

```
Pointers

↓

Dynamic Memory

↓

Linked Lists

↓

Trees

↓

Graphs

↓

Operating Systems

↓

Virtual Memory

```

Without pointer mastery, advanced Computer Science becomes much harder.
