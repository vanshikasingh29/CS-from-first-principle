# Struct Theory Notes

---

# 1. What Is A Struct?

A structure is a programmer-defined data type.

It combines multiple variables into one object.

Example:

```c
struct Car
{
    char model[50];
    int year;
    float price;
};
```

The structure represents a real-world entity.

---

# 2. Memory Layout

A struct is stored as one continuous block of memory.

Example:

```c
struct Student
{
    int id;
    char grade;
};
```

Memory:

```
Address

2000
+-------------+
| id          |
+-------------+

2004
+-------------+
| grade       |
+-------------+

```

Each field has an offset.

---

# 3. Field Offsets

Example:

```c
student.id
```

means:

```
base address + offset of id
```

Example:

```
Student address = 1000

id offset = 0

grade offset = 4

```

The compiler calculates these offsets.

---

# 4. Struct Alignment

CPUs access memory efficiently when data is aligned.

Example:

Without alignment:

```
Address 1001

```

may require multiple memory operations.

Aligned:

```
Address 1004

```

is faster.

Therefore compilers insert padding.

---

# 5. Padding Example

Struct:

```c
struct Example
{
    char a;
    int b;
};
```

Possible memory:

```
+-----+
| a   |
+-----+
| pad |
+-----+
| pad |
+-----+
| pad |
+-----+
| b   |
+-----+

```

The struct may become 8 bytes instead of 5.

---

# 6. Struct Access

Using a normal variable:

```c
person.age;
```

Using pointer:

```c
person_ptr->age;
```

The arrow operator:

```c
->
```

means:

```
dereference pointer then access member
```

Equivalent:

```c
(*person_ptr).age;
```

---

# 7. Passing Structs

A struct can be passed:

## By Value

Copies the entire structure.

```c
function(person);
```

Cost:

Large structs require copying.

---

## By Pointer

Pass address.

```c
function(&person);
```

Advantages:

- Faster
- Allows modification
- Avoids copying

---

# 8. Structs and Data Structures

Linked list:

```c
struct Node
{
    int data;
    struct Node *next;
};
```

Memory:

```
Node

+---------+
| data    |
+---------+
| next -> |
+---------+

```

Trees:

```c
struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};
```

---

# 9. Relationship To Operating Systems

Operating systems represent information using structures.

Examples:

- Process Control Blocks
- File metadata
- Network packets
- Device information

A kernel is full of structs.

---

# Key Takeaways

✓ Structs create custom data types.

✓ Struct fields have memory offsets.

✓ Padding exists for CPU efficiency.

✓ Struct pointers avoid copying.

✓ Complex data structures are built using structs.

✓ Understanding structs is understanding data representation.

---

# Next

The implementation will demonstrate:

- Creating structs
- Initialising values
- Accessing members
- Using pointers
- Inspecting memory size
- Understanding alignment