# File I/O Theory Notes

---

# 1. Memory vs Storage

A running program uses RAM.

Example:

```c
int value = 10;
```

Stored:

```
RAM
```

When the program closes:

```
value disappears
```

Files provide persistence.

---

# 2. File Abstraction

A file is an abstraction provided by the operating system.

The program does not directly control the disk.

Instead:

```
Application

↓

Library

↓

Operating System

↓

File System

↓

Storage Hardware

```

---

# 3. FILE Pointer

C represents an open file using:

```c
FILE *
```

Example:

```c
FILE *fp;
```

The pointer does not contain the file data.

It represents a connection to the OS-managed file stream.

---

# 4. Opening Files

Function:

```c
fopen()
```

Example:

```c
FILE *fp = fopen("data.txt","r");
```

Arguments:

```
filename

mode

```

---

# 5. File Modes

## Read

```c
r
```

Requires existing file.

---

## Write

```c
w
```

Creates file or overwrites existing content.

---

## Append

```c
a
```

Adds data to the end.

---

## Binary

```c
rb
wb
```

Used for raw bytes.

---

# 6. Closing Files

Always close:

```c
fclose(fp);
```

Why?

Because:

- releases resources
- flushes buffers
- prevents corruption

---

# 7. Buffering

The OS does not always immediately write data.

Example:

```
Program

↓

Buffer

↓

Disk

```

The buffer improves performance.

---

# 8. Text vs Binary

## Text

Example:

```
12345
```

Stored as:

```
characters:

1
2
3
4
5

```

---

## Binary

Stored directly:

```
00000000
00000001
```

---

# 9. File Descriptors

At the operating system level:

Files are represented by numbers.

Example:

```
stdin  = 0

stdout = 1

stderr = 2

```

Other opened files receive descriptors.

---

# 10. Relationship To Operating Systems

When C calls:

```c
fopen()
```

eventually the OS performs actions similar to:

```
open()

read()

write()

close()

```

These are system calls.

---

# 11. Security Considerations

File handling mistakes can cause:

- data corruption
- privilege issues
- information leaks

Important practices:

- validate paths
- check permissions
- handle errors

---

# Key Takeaways

✓ RAM is temporary.

✓ Files provide permanent storage.

✓ FILE pointers represent streams.

✓ The OS controls actual storage.

✓ Text files store characters.

✓ Binary files store raw bytes.

✓ File I/O is the bridge between programs and operating systems.

---

# Next

Implementation files will demonstrate:

1. Creating and writing text files.
2. Reading existing files.
3. Storing structures as binary data.
4. Understanding raw memory representation.