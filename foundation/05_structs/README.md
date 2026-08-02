# 05 — Structs

> Creating custom data structures and understanding memory organisation.

---

# Overview

A structure (`struct`) allows programmers to group related data together into a single unit.

Unlike arrays, where every element has the same type, structures allow different data types to exist together.

Example:

```c
struct Student
{
    char name[50];
    int age;
    double grade;
};
```

This creates a custom data type containing:

- characters
- integers
- floating point numbers

---

# Why Structs Matter

Structs are the foundation of almost every complex system.

Examples:

## Operating Systems

A process can be represented internally as a structure:

```
Process

+----------------+
| PID            |
+----------------+
| Memory info    |
+----------------+
| State          |
+----------------+

```

---

## Databases

A database record:

```
User

+----------------+
| ID             |
+----------------+
| Name           |
+----------------+
| Email          |
+----------------+

```

is conceptually similar to a struct.

---

## Data Structures

Linked list node:

```
Node

+-------------+
| Data        |
+-------------+
| Next pointer|
+-------------+

```

is created using structs and pointers.

---

# Learning Objectives

After completing this folder, you should understand:

- Creating custom data types
- Struct memory layout
- Accessing struct members
- Struct pointers
- Passing structs to functions
- Why padding and alignment exist

---

# File

| File | Purpose |
|-|-|
| structs.c | Struct creation, memory layout, and pointer access |

---

# Basic Struct Syntax

Example:

```c
struct Person
{
    int age;
    char name[20];
};
```

Creating:

```c
struct Person user;
```

Accessing:

```c
user.age;
```

---

# Struct Memory Layout

Example:

```c
struct Example
{
    int id;
    char letter;
};
```

Memory:

```
Address

1000
+--------+
| int id |
+--------+

1004
+--------+
| char   |
+--------+

```

However, the compiler may insert padding bytes for performance.

---

# Padding and Alignment

Modern CPUs prefer aligned memory access.

Example:

```
Without padding:

int
char

5 bytes


With padding:

int
char
padding

8 bytes

```

The compiler adjusts layout for efficiency.

---

# Struct Pointers

A pointer can store the address of a struct.

Example:

```c
struct Person person;

struct Person *ptr = &person;
```

Access:

```c
ptr->age;
```

Equivalent:

```c
(*ptr).age;
```

---

---

# Why This Matters

Structs prepare you for:

```
Structs

↓

Linked Lists

↓

Trees

↓

Graphs

↓

Operating Systems

↓

Memory Management

```

Understanding structs means understanding how real software represents complex information.