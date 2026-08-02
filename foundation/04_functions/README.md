# 04 — Functions

> Understanding function execution, stack frames, and recursion.

---

# Overview

Functions are one of the fundamental abstractions in programming.

At a high level, a function allows us to:

- Organise code
- Reuse logic
- Separate responsibilities

However, at the systems level, a function represents something much deeper:

A function call requires the computer to:

1. Store the current execution location
2. Pass arguments
3. Allocate local memory
4. Execute instructions
5. Return control back to the caller

This process is managed through:

- The stack
- CPU registers
- Calling conventions

---

# Learning Objectives

After completing this chapter, you should understand:

- How functions execute internally
- Stack frames
- Function parameters
- Return addresses
- Local variable lifetime
- Recursion
- Recursive stack growth
- Why stack overflow occurs

---

# Files

| File | Purpose |
|-|-|
| notes.md | Theory of function execution |
| recursion.c | Recursive algorithms and stack behaviour |
| call_stack.c | Visualising nested function calls |

---

# Function Execution Model

Example:

```c
int result = add(5,3);
```

The computer performs:

```
Caller

↓

Place arguments

↓

Jump to function address

↓

Create stack frame

↓

Execute instructions

↓

Return value

↓

Destroy stack frame

↓

Continue execution

```

---

# Stack Frame

Every active function receives a stack frame.

Example:

```
main()

+----------------+
| variables      |
| return address |
+----------------+

      ↓

calculate()

+----------------+
| parameters     |
| local data     |
| return address |
+----------------+

```

---

# Recursion

A recursive function calls itself.

Example:

```c
factorial(5)
```

creates:

```
factorial(5)

 factorial(4)

  factorial(3)

   factorial(2)

    factorial(1)

```

Each call creates a new stack frame.

---

# Stack Overflow

Every process has limited stack memory.

Too much recursion:

```
function()

function()

function()

function()

...

```

eventually exhausts available stack space.

---


---

# Why This Matters

Function execution is the foundation of:

- Compilers
- Operating systems
- Assembly programming
- Debuggers
- Performance optimisation

Understanding functions internally makes later systems concepts much easier.
