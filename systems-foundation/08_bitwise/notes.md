# Bitwise Operations Theory Notes

---

# 1. Everything Is Binary

Computers represent information using two states:

```
0

1

```

A single binary digit is a bit.

---

# 2. Bits and Bytes

8 bits:

```
10101010

```

equals:

```
1 byte

```

Example:

```
4 bytes = 32 bits

```

This is why many integers are represented as:

```
32-bit

or

64-bit

```

---

# 3. Decimal To Binary

Example:

Decimal:

```
13

```

Powers of 2:

```
8 4 2 1

```

Representation:

```
1101

```

Because:

```
8 + 4 + 0 + 1

= 13

```

---

# 4. AND Operator (&)

AND keeps only bits that are 1 in both values.

Example:

```
  1101

& 1011

------

  1001

```

Used for:

- checking bits
- extracting information

---

# 5. OR Operator (|)

OR combines bits.

Example:

```
  1000

| 0011

------

  1011

```

Used for:

- enabling flags
- setting bits

---

# 6. XOR Operator (^)

XOR produces 1 when bits differ.

Example:

```
  1010

^ 1100

------

  0110

```

Used in:

- encryption algorithms
- swapping values
- parity checking

---

# 7. NOT Operator (~)

Flips every bit.

Example:

```
1010

↓

0101

```

Important:

C integers have signed representation,
so results may appear negative.

---

# 8. Left Shift

Example:

```
00000101

<< 1

00001010

```

Moves bits left.

Mathematically:

```
x * 2

```

---

# 9. Right Shift

Example:

```
00001010

>> 1

00000101

```

Mathematically:

```
x / 2

```

---

# 10. Bit Masks

A mask controls specific bits.

Example:

Permissions:

```
READ    001
WRITE   010
EXECUTE 100

```

Combine:

```
READ | WRITE

001 | 010

011

```

---

# 11. Flags

Many systems store multiple states in one integer.

Example:

```
00000111

```

could represent:

```
Bit 0 = enabled

Bit 1 = connected

Bit 2 = active

```

---

# 12. CPU Connection

The CPU contains registers:

Example:

```
RAX

101010101010

```

Instructions manipulate these bits directly.

---

# 13. Security Connection

Incorrect bit handling can cause:

- permission bugs
- overflow issues
- cryptographic weaknesses

---

# Key Takeaways

✓ Computers operate using bits.

✓ Bitwise operators manipulate binary directly.

✓ Masks allow efficient flag management.

✓ Shifts modify binary representation.

✓ Bitwise knowledge bridges C and hardware.

---

# Next

The implementation will demonstrate:

- binary display
- AND/OR/XOR/NOT
- shifting
- creating masks
- toggling individual bits