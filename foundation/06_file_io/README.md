# 06 — File I/O

> Understanding how programs communicate with persistent storage.

---

# Overview

A program's memory is temporary.

When a program exits:

```
RAM is cleared
```

Any variables stored in memory disappear.

Files allow programs to store information permanently.

Example:

```
Program

↓

Create Data

↓

Write File

↓

Close Program

↓

Open Later

↓

Read Data

```

---

# Why File I/O Matters

Almost every real-world application uses files.

Examples:

## Databases

```
Database Engine

↓

Storage Files

↓

Disk

```

---

## Operating Systems

Files store:

- configuration
- user information
- logs
- executables

---

## Applications

Examples:

- text editors
- games
- browsers
- machine learning datasets

---

# Learning Objectives

After completing this chapter, you should understand:

- Opening files
- Closing files
- Reading data
- Writing data
- File streams
- Text vs binary files
- File permissions
- Operating system interaction

---

# Files

| File | Purpose |
|-|-|
| notes.md | File system theory |
| text_files.c | Reading and writing text |
| binary_files.c | Raw byte storage |

---

# File Streams

C represents files using:

```c
FILE *
```

Example:

```c
FILE *file;
```

This pointer represents a connection between:

```
Program

↓

Operating System

↓

File

```

---

# Opening Files

Example:

```c
fopen("data.txt","r");
```

Modes:

| Mode | Meaning |
|-|-|
| r | Read |
| w | Write |
| a | Append |
| rb | Read binary |
| wb | Write binary |

---

# Writing Process

Example:

```c
fprintf(file,"Hello");
```

Flow:

```
Variable

↓

C Library

↓

Operating System

↓

File System

↓

Disk

```

---

# Reading Process

Example:

```c
fscanf(file,"%s",buffer);
```

Flow:

```
Disk

↓

File System

↓

Operating System

↓

C Library

↓

Program Memory

```

---

# Text Files

Human-readable.

Example:

```
student.txt

Name: Alice
Age: 20

```

Advantages:

- Easy debugging
- Portable
- Simple

Disadvantages:

- Larger size
- Slower parsing

---

# Binary Files

Store raw bytes.

Example:

```
01010101 10101010

```

Advantages:

- Faster
- Smaller
- Exact memory representation

Disadvantages:

- Not human-readable

---

# Error Handling

Files can fail.

Examples:

- File does not exist
- Permission denied
- Disk failure

Always check:

```c
if(file == NULL)
{
    // error
}
```

---

---

# Connection To Later Topics

File I/O prepares you for:

```
Files

↓

File Descriptors

↓

System Calls

↓

Kernel

↓

File Systems

↓

Operating Systems
```

Understanding files means understanding how software interacts with hardware.