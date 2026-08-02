# Function Execution Theory Notes

---

# 1. What Happens During A Function Call?

Consider:

```c
result = add(10,20);
```

The processor must:

1. Save current location
2. Transfer execution
3. Provide parameters
4. Execute function instructions
5. Return result

---

# 2. The Call Stack

The stack stores active function calls.

Example:

```c
main()

calls:

functionA()

calls:

functionB()

```

Memory:

```
Top

+----------------+
| functionB     |
+----------------+
| functionA     |
+----------------+
| main          |
+----------------+

Bottom

```

The newest function is always on top.

---

# 3. Stack Frames

A stack frame contains information required for one function execution.

Usually includes:

- Local variables
- Function parameters
- Return address
- Saved registers

Example:

```c
void example()
{
    int x = 10;
}

```

Memory:

```
Stack Frame

+----------------+
| x = 10         |
+----------------+
| return address |
+----------------+

```

When the function returns:

The frame disappears.

---

# 4. Return Address

The CPU needs to know:

"Where do I continue after this function finishes?"

Example:

```
main

calls

calculate

returns here

```

The location of that next instruction is stored as the return address.

---

# 5. Parameters

Functions need input.

Example:

```c
sum(5,10)
```

The values:

```
5

10

```

must be passed to the function.

Depending on architecture, this may happen through:

- CPU registers
- Stack memory

---

# 6. Recursion

A recursive function solves a problem by reducing it into smaller versions of itself.

Example:

Factorial:

\[
n! = n \times (n-1)!
\]

Base case:

\[
1! = 1
\]

---

# Recursive Memory

Example:

```
factorial(4)

+----------------+
| n = 4          |
+----------------+

factorial(3)

+----------------+
| n = 3          |
+----------------+

factorial(2)

+----------------+
| n = 2          |
+----------------+

factorial(1)

+----------------+
| n = 1          |
+----------------+

```

Each call has independent variables.

---

# 7. Stack Overflow

Infinite recursion:

```c
void crash()
{
    crash();
}

```

creates:

```
Frame

Frame

Frame

Frame

...

```

Eventually:

```
Stack memory exhausted

```

---

# 8. Relationship To Assembly

In assembly:

Function calls become instructions:

```
CALL function

...

RET

```

CALL:

- stores return address
- jumps to function

RET:

- retrieves return address
- continues execution

---

# 9. Relationship To Operating Systems

Operating systems must manage:

- Stack memory
- Process execution
- Registers
- Context switching

Every program uses functions constantly.

Understanding function calls means understanding program execution.

---

# Key Takeaways

✓ Functions require memory management.

✓ Every function call creates a stack frame.

✓ Recursion creates multiple stack frames.

✓ Return addresses control execution flow.

✓ Stack behaviour explains many programming errors.

✓ Functions are the bridge between software and CPU execution.

---

# Next

The implementation files will demonstrate:

1. Recursive stack growth.
2. Nested function calls.
3. How execution moves through the call stack.