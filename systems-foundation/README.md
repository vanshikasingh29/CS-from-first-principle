<div align="center">

# C Systems Foundations
# Understanding The Machine Beneath The Code

### A first-principles exploration of memory, execution, and low-level software engineering using C.

<br>

![Language](https://img.shields.io/badge/Language-C17-blue)
![Focus](https://img.shields.io/badge/Focus-Systems%20Programming-green)
![Level](https://img.shields.io/badge/Approach-First%20Principles-red)
![Status](https://img.shields.io/badge/Progress-Complete-success)

</div>


---

# Project Overview

Modern software engineering relies on layers of abstraction.

Developers write applications using:

- frameworks,
- libraries,
- programming languages,
- operating systems.

However, beneath every application exists a fundamental layer:

```
Source Code

↓

Compiler

↓

Memory

↓

CPU Instructions

↓

Hardware
```

This project explores that foundation.

The objective is to understand **how software actually executes**, rather than only learning how to use higher-level technologies.

---

#  Project Mission

> Build a strong systems programming foundation by understanding memory, data representation, program execution, and low-level computer behaviour from first principles.

This stage represents the first stage of a wider Computer Science transformation journey.

Before studying:

- operating systems,
- compilers,
- computer architecture,
- algorithms,
- artificial intelligence,

it is essential to understand the machine that runs them.

---

# Learning Philosophy

This project follows an engineering approach:

```
Theory

↓

Implementation

↓

Experimentation

↓

Understanding
```

Every topic is explored through:

## 1. Conceptual Understanding

Learning:

- why the concept exists,
- how the computer implements it,
- common design decisions,
- engineering trade-offs.


## 2. Practical Implementation

Building:

- C programs,
- memory experiments,
- debugging examples,
- low-level demonstrations.


## 3. Documentation

Recording:

- technical notes,
- diagrams,
- explanations,
- lessons learned.


---

# Repository Architecture

The foundation is organised into progressive systems concepts.

```
00_c_systems_foundations/

│
├── 00_environment
│
├── 01_memory_model
│
├── 02_pointers
│
├── 03_arrays_strings
│
├── 04_functions
│
├── 05_structs
│
├── 06_file_io
│
├── 07_dynamic_memory
│
├── 08_bitwise
│
├── 09_debugging
│
└── 10_preprocessor
```

Each section contains:

```
README.md

↓

notes.md

↓

C implementations

↓

Practical experiments
```

---

# Topics Covered

## 01 — Memory Model

Understanding:

- program memory layout,
- stack memory,
- heap memory,
- static memory,
- execution regions.

Key idea:

> Programs are not just instructions. They are instructions operating on memory.


---

## 02 — Pointers

Understanding:

- memory addresses,
- pointer arithmetic,
- references,
- indirect access,
- double pointers.

Key idea:

> Pointers provide direct control over memory.


---

## 03 — Arrays & Strings

Understanding:

- contiguous memory,
- array decay,
- character storage,
- string representation.

Key idea:

> Data structures are ultimately memory layouts.


---

## 04 — Functions & Execution

Understanding:

- stack frames,
- function calls,
- recursion,
- return addresses.

Key idea:

> Every function call creates a temporary execution environment.


---

## 05 — Structures

Understanding:

- custom data types,
- memory organisation,
- alignment,
- abstraction in C.

Key idea:

> Complex data is built from simple memory representations.


---

## 06 — File I/O

Understanding:

- persistent storage,
- file streams,
- binary data,
- system interaction.

Key idea:

> Memory is temporary; files provide persistence.


---

## 07 — Dynamic Memory

Understanding:

- heap allocation,
- malloc,
- calloc,
- realloc,
- free,
- memory ownership.

Key idea:

> Manual memory management requires responsibility.


---

## 08 — Bitwise Operations

Understanding:

- binary representation,
- bit manipulation,
- masks,
- flags,
- hardware-level control.

Key idea:

> Computers ultimately operate on bits.


---

## 09 — Debugging

Understanding:

- runtime failures,
- assertions,
- defensive programming,
- debugging methodology.

Key idea:

> Engineering requires understanding failure, not avoiding it.


---

## 10 — C Preprocessor

Understanding:

- macros,
- compilation stages,
- header organisation,
- conditional compilation.

Key idea:

> Large software systems require structure before execution.


---

# Technologies Used

## Programming

- C17 Standard

## Development Tools

- GCC Compiler
- GDB Debugger
- VS Code
- Linux Command Line
- Git/GitHub


## Engineering Practices

- Documentation-driven development
- Version control
- Modular organisation
- Clean code principles


---

# Skills Developed

## Systems Programming

✓ Memory management  
✓ Pointer manipulation  
✓ Low-level debugging  
✓ Binary representation  
✓ File handling  


## Computer Science Foundations

✓ Understanding execution models  
✓ Reasoning about program behaviour  
✓ Connecting software and hardware  


## Software Engineering

✓ Technical documentation  
✓ Code organisation  
✓ Reproducible builds  
✓ Professional Git workflow  


---

# Featured Engineering Demonstrations

## Memory Exploration

Implemented programs exploring:

- stack vs heap behaviour,
- memory addresses,
- allocation patterns.


---

## Dynamic Memory Experiments

Built examples demonstrating:

- manual allocation,
- resizing memory,
- ownership management.


---

## Binary Manipulation Toolkit

Explored:

- bit operations,
- masks,
- permission-style flags.


---

## Defensive Programming Examples

Implemented:

- assertions,
- validation,
- safe failure handling.


---

# Core References

This foundation was developed alongside:

## Books

- *Computer Systems: A Programmer's Perspective*  
  Bryant & O'Hallaron

- *The C Programming Language*  
  Kernighan & Ritchie

- *Operating Systems: Three Easy Pieces*


---

#  Connection To The Larger Roadmap

This repository is the foundation layer for:

```
C Systems Foundations

        ↓

Discrete Mathematics

        ↓

Computer Architecture

        ↓

Data Structures & Algorithms

        ↓

Operating Systems

        ↓

Networking

        ↓

Artificial Intelligence Mathematics
```

Understanding the machine makes advanced computer science concepts easier to reason about.

---


---

# Next Stage

The next stage of the journey moves from:

```
How computers execute programs

↓

How computers reason about information
```

Next:

# Discrete Mathematics & Formal Reasoning

Topics:

- Predicate Logic
- Sets
- Relations
- Graph Theory
- Automata


---

# Engineering Principle

> The best engineers do not only know how to use abstractions. They understand what those abstractions are built upon.