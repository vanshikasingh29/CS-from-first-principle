# 09 — Debugging

> Learning how to analyse, detect, and prevent software failures.

---

# Overview

Debugging is the process of identifying and correcting incorrect program behaviour.

A program can fail because of:

- incorrect logic
- invalid memory access
- incorrect assumptions
- unexpected input
- hardware limitations

---

# Debugging Mindset

A professional debugging process:

```
Observe Problem

↓

Reproduce Problem

↓

Collect Evidence

↓

Identify Cause

↓

Apply Fix

↓

Verify Solution

```

---

# Why Debugging Matters

Large systems are impossible to write perfectly.

Professional engineers spend significant time:

- reading code
- analysing crashes
- inspecting memory
- understanding failures

---

# Types of Bugs

## Compile-Time Bugs

Detected by compiler.

Example:

```c
missing ;
```

---

## Runtime Bugs

Occur while program executes.

Examples:

- segmentation faults
- memory errors
- crashes

---

## Logic Bugs

Program runs but produces wrong output.

Example:

Incorrect calculation.

---

# Debugging Tools

Professional developers use:

## Compiler Warnings

Example:

```bash
gcc -Wall -Wextra
```

Warnings reveal potential problems.

---

## Debuggers

Examples:

- GDB
- LLDB

Allow:

- breakpoints
- stepping through code
- inspecting variables

---

## Memory Tools

Examples:

- Valgrind
- AddressSanitizer

Detect:

- leaks
- invalid memory access
- use-after-free

---

# Assertions

Assertions verify assumptions.

Example:

```c
assert(value > 0);
```

Meaning:

"The program expects this condition to always be true."

---

# Why Assertions Matter

Without assertions:

```
Wrong State

↓

Program Continues

↓

Error Appears Later

```

With assertions:

```
Wrong State

↓

Immediate Failure

↓

Easier Diagnosis

```

---

# Assertions vs Error Handling

Assertions:

Used for programmer mistakes.

Example:

```
A function receives impossible data.

```

Error handling:

Used for expected failures.

Example:

```
File does not exist.

```

---

# File

| File | Purpose |
|-|-|
| assertions.c | Demonstrates defensive programming |

---

---

# Connection To Future Topics

Debugging prepares you for:

```
Operating Systems

↓

Memory Debugging

↓

Concurrency Debugging

↓

Compiler Errors

↓

Production Engineering
```

---

# Key Idea

Good programmers write code.

Great engineers understand failure.