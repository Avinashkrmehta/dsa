Here’s a well-structured and easy-to-understand version of your notes on **Bitmask**, with added formatting, clarity, and additional context where helpful:

---

# 🧠 Understanding Bitmask in Programming

I struggled to grasp **Bitmask** concepts until I stumbled upon a random PDF that made things clear. I’m sharing these notes for beginners like me to get a better understanding of bitmasks and their applications, especially in competitive programming.

---

## 🚀 Motivation

Suppose you have a **set of items** and you want to represent a **subset** — indicating which items are **selected** and which are not. How do you do this efficiently?

### Common Methods:
- ✅ **Map** – Map each item to a boolean value.
- ✅ **Boolean array** – Use an array where `true` means selected.
- ❌ Both approaches **consume more memory** and may have **slower performance**.

### A Better Way: **Bitmasking**
- If the set is not too large, **bitmasking** is:
  - 🔋 **Memory-efficient**
  - ⚡ **Faster** (especially with bitwise operations)
  - 💻 Native support in C/C++/Java

---

## 🧩 What is a Bitmask?

A **Bitmask** is an integer used to represent a small set of boolean values using **binary representation**.

### Idea:
- Use the **bits** of an integer to denote presence (`1`) or absence (`0`) of elements in a subset.
- For example:
  - Set of 5 objects → picked 1st, 3rd, and 4th → Bitmask: `01101` (Binary) = `13` (Decimal)

### Why is it useful?
- 🧠 All set operations can be done using **bitwise operators**.
- 🚀 Much faster than using STL containers (`vector`, `set`, `bitset`), especially in **competitive programming**.

---

## 🔧 Bitmask Operations

### 1. 📦 Representation

Use a 32-bit or 64-bit signed integer:
- Safely represent up to:
  - 30 items using `int`
  - 62 items using `long long` (due to sign bit)

#### Example:
```text
Decimal A = 34
Binary     = 100010
Indexes    = [5][4][3][2][1][0]
Power 2    = [32][16][8][4][2][1]
Set        = {1, 5} (0-based index)
```

---

### 2. 🔁 Multiply/Divide by 2 (Shifting)
- Multiply: `A << 1` (left shift)
- Divide: `A >> 1` (right shift, rounds down)

```cpp
A = 34        → 100010
A << 1 = 68   → 1000100
A >> 1 = 17   → 10001
A >> 2 = 8    → 1000
```

---

### 3. ➕ Add j-th item to subset
Set j-th bit to `1`:
```cpp
A |= (1 << j)
```

---

### 4. ➖ Remove j-th item from subset
Clear j-th bit:
```cpp
A &= ~(1 << j)
```

---

### 5. ❓ Check if j-th item is in subset
Test j-th bit:
```cpp
T = A & (1 << j)
```
- If `T == 0` → not present
- If `T != 0` → present

---

### 6. 🔄 Toggle j-th item (flip 0 ↔ 1)
Flip j-th bit:
```cpp
A ^= (1 << j)
```

---

### 7. 🔍 Get least significant bit that is ON
```cpp
T = A & -A
```

---

### 8. ✅ Turn ON all bits in a set of size `n`
```cpp
A = (1 << n) - 1
```

---

### 9. 🔁 Iterate through all subsets of a set of size `n`
```cpp
for (int x = 0; x < (1 << n); ++x)
```

---

### 10. 🔁 Iterate through all subsets of a subset `y`
```cpp
for (int x = y; x > 0; x = (y & (x - 1)))
```

---

### 11. 📊 Example: Sum of all subsets

```cpp
int sum_of_all_subset(vector<int> s) {
    int n = s.size();
    int results[1 << n];
    memset(results, 0, sizeof(results));

    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j)) != 0)
                results[i] += s[j];
        }
    }
}
```

---

## ⚠️ Limitations & Best Practices

### a. ⚠️ Bitmask Size Limit:
- Use `int` or `long long` based on the number of items.

### b. 🧠 Use Parentheses in Bitwise Operations:
Operator precedence can cause unexpected results.

Example:
```cpp
x = 5;
x - 1 << 2 = 16       // Wrong due to precedence
x - (1 << 2) = 1      // Correct
```

---

## ✅ Summary

| Operation                     | Code                        | Description                                |
|------------------------------|-----------------------------|--------------------------------------------|
| Add element j                | `A |= (1 << j)`             | Set j-th bit to 1                          |
| Remove element j             | `A &= ~(1 << j)`            | Clear j-th bit                             |
| Check if j-th is set         | `A & (1 << j)`              | Non-zero if j-th bit is 1                  |
| Toggle j-th bit              | `A ^= (1 << j)`             | Flip bit                                   |
| Multiply by 2                | `A << 1`                    | Shift bits left                            |
| Divide by 2                  | `A >> 1`                    | Shift bits right                           |
| Least significant bit        | `A & -A`                    | Gets the lowest set bit                    |
| All bits ON (n items)        | `(1 << n) - 1`              | Bitmask with all bits set                  |
| All subsets of set           | `for x in 0 to (1 << n)`    | Iterates all subsets                       |
| All subsets of subset y      | `for x = y; x > 0; x = (y & (x - 1))` | Fast subset iteration              |
