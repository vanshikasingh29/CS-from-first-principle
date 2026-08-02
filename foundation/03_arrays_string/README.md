# 03 — Arrays & Strings

> Understanding contiguous memory and character representation in C.

---

# Overview

Arrays and strings are some of the most commonly used structures in programming.

However, in C they reveal how computers actually store data.

An array is not a magical container.

It is:

```
A sequence of elements stored next to each other in memory.
```

A string is not a special data type.

It is:

```
An array of characters terminated by '\0'.
```

Understanding this is essential for:

- Memory management
- Data structures
- Buffer handling
- Operating systems
- Cybersecurity
- Performance optimisation

---

# Learning Objectives

After completing this chapter, you should understand:

- How arrays are stored in memory
- Why array indexing begins at zero
- The relationship between arrays and pointers
- Pointer arithmetic with arrays
- Stack allocated arrays
- Character arrays
- Null terminated strings
- Common string vulnerabilities

---

# Files

| File | Purpose |
|-|-|
| notes.md | Theory and memory models |
| arrays.c | Array storage and pointer relationships |
| strings.c | Character arrays and string handling |

---

# Array Memory Layout

Example:

```c
int numbers[4] = {10,20,30,40};
```

Memory:

```
Address

1000
 |
 v
+----+
|10  |
+----+

1004
 |
 v
+----+
|20  |
+----+

1008
 |
 v
+----+
|30  |
+----+

1012
 |
 v
+----+
|40  |
+----+

```

Each element is stored sequentially.

---

# Why Indexing Starts At Zero

An array name represents the address of the first element.

Example:

```c
numbers[0]
```

means:

```
start address + 0 elements
```

while:

```c
numbers[3]
```

means:

```
start address + 3 elements
```

---

# Array and Pointer Relationship

Given:

```c
int numbers[3];

int *ptr = numbers;
```

These are equivalent:

```c
numbers[2]
```

and:

```c
*(ptr + 2)
```

The compiler converts indexing into pointer arithmetic.

---

# Strings in C

C does not have a built-in string object.

A string:

```c
"Hello"
```

is stored as:

```
H
e
l
l
o
\0

```

The final:

```
\0
```

marks the end.

---

# Common String Problems

## Buffer Overflow

Example:

```c
char name[5];

strcpy(name,"Computer");
```

The data exceeds the allocated memory.

---

## Missing Null Terminator

Incorrect:

```c
char text[5] = {'H','e','l','l','o'};
```

No terminating:

```
\0
```

The program does not know where the string ends.

---


---

# Why This Matters

Arrays and strings appear everywhere:

- Databases
- Operating systems
- File systems
- Network packets
- Cryptography
- Machine learning data processing

Understanding memory representation makes debugging much easier.