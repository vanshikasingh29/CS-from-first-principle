# Debugging Theory Notes

---

# 1. What Is Debugging?

Debugging is the process of finding the cause of incorrect behaviour.

The goal is not simply fixing symptoms.

The goal is finding:

```
Root Cause

```

---

# 2. Bug Categories

## Syntax Errors

The compiler cannot understand the program.

Example:

```c
printf("Hello"
```

---

## Runtime Errors

The program crashes while executing.

Examples:

- segmentation fault
- divide by zero
- invalid memory access

---

## Logic Errors

The program runs but produces incorrect results.

Example:

Expected:

```
10

```

Actual:

```
11

```

---

# 3. The Debugging Cycle

Professional workflow:

```
1. Reproduce

2. Observe

3. Hypothesise

4. Test

5. Fix

6. Verify

```

---

# 4. Compiler Warnings

Compilers can detect suspicious behaviour.

Example:

```bash
gcc -Wall -Wextra
```

Important warnings:

- unused variables
- type conversion issues
- missing returns

Warnings should be treated seriously.

---

# 5. Assertions

An assertion checks assumptions.

Example:

```c
assert(pointer != NULL);
```

The program stops if the condition fails.

---

# 6. Defensive Programming

Instead of assuming:

```
Input is correct

```

verify:

```
Input satisfies requirements

```

Example:

```c
if(pointer == NULL)
{
    return;
}
```

---

# 7. Debugging Memory

Common memory problems:

---

## Memory Leak

Allocated memory is never released.

```
malloc()

↓

Lose pointer

↓

Cannot free

```

---

## Dangling Pointer

Pointer refers to released memory.

```
free(ptr)

↓

ptr still exists

```

---

## Buffer Overflow

Writing beyond allocated space.

Example:

```
Array size:

5


Write:

10 elements

```

---

# 8. Debuggers

A debugger allows controlled execution.

Features:

## Breakpoints

Pause execution.

---

## Step Execution

Run one instruction at a time.

---

## Variable Inspection

View memory values.

---

# 9. Debugging Philosophy

A bug is evidence.

The program is showing:

```
Your mental model

≠

Actual behaviour

```

Debugging updates your understanding.

---

# 10. Engineering Principle

The best debugging strategy:

Prevent bugs before they happen.

Methods:

- clear design
- assertions
- testing
- compiler warnings
- code review

---

# Key Takeaways

✓ Debugging is investigation.

✓ Errors have root causes.

✓ Assertions protect assumptions.

✓ Warnings reveal hidden problems.

✓ Memory debugging is essential in C.

✓ Professional engineers design for failure.

---

# Next

Implementation:

`assertions.c`

will demonstrate:

- defensive programming
- validating assumptions
- catching invalid states early
- professional error checking