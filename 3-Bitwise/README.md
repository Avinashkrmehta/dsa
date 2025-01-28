# Bit Masking and Manipulation

Bit masking and manipulation involve performing operations directly at the binary level (bits) of numbers. These techniques are widely used in competitive programming, system-level programming, and areas requiring optimization. Let’s explore these concepts step by step.

## 1. Basics of Bits

A bit is the smallest unit of data in a computer and can either be 0 or 1. Numbers in computers are represented in binary (base 2). For example:

- Decimal 5 → Binary: `101`
- Decimal 10 → Binary: `1010`

Each bit position represents a power of 2:

For `1010`:
- Leftmost bit (1) → \(2^3 = 8\)
- Next bit (0) → \(2^2 = 0\)
- Next bit (1) → \(2^1 = 2\)
- Rightmost bit (0) → \(2^0 = 0\)

Decimal value = \(8 + 0 + 2 + 0 = 10\)

## 2. Common Bitwise Operators

### AND (`&`):
- `1 & 1 = 1`, otherwise 0.
- Example: `1010 & 0110 = 0010`

### OR (`|`):
- `1 | 1 = 1`, `1 | 0 = 1`, `0 | 0 = 0`.
- Example: `1010 | 0110 = 1110`

### XOR (`^`):
- `1 ^ 1 = 0`, `1 ^ 0 = 1`, `0 ^ 1 = 1`, `0 ^ 0 = 0`.
- Example: `1010 ^ 0110 = 1100`

### NOT (`~`):
- Flips all bits: `~1010 = 0101` (but note it's system-dependent due to signed representation).

### Left Shift (`<<`):
- Shifts bits to the left, filling right with 0.
- Example: `101 << 2 = 10100` (multiplies by \(2^2 = 4\)).

### Right Shift (`>>`):
- Shifts bits to the right, discarding rightmost bits.
- Example: `1010 >> 2 = 10` (divides by \(2^2 = 4\)).

## 3. Bit Masking

A bitmask is a binary number used to isolate, set, clear, or toggle bits in another binary number.

### a. Setting a Bit
Set the \(i\)-th bit of a number to 1: `number |= (1 << i)`

Example:
- Number: `1010` (decimal 10)
- Set 1st bit: `1010 | (1 << 1) = 1010 | 0010 = 1010`

### b. Clearing a Bit
Clear the \(i\)-th bit of a number: `number &= ~(1 << i)`

Example:
- Number: `1010` (decimal 10)
- Clear 1st bit: `1010 & ~(1 << 1) = 1010 & 1101 = 1000`

### c. Checking a Bit
Check if the \(i\)-th bit is 1: `number & (1 << i)`

Example:
- Number: `1010`
- Check 3rd bit: `1010 & (1 << 3) = 1010 & 1000 = 1000` (non-zero → bit is 1)

### d. Toggling a Bit
Flip the \(i\)-th bit: `number ^= (1 << i)`

Example:
- Number: `1010`
- Toggle 1st bit: `1010 ^ (1 << 1) = 1010 ^ 0010 = 1000`

## 4. Advanced Bit Manipulation

### a. Counting Set Bits
Count the number of 1s in a number’s binary representation.

```python
def count_set_bits(n):
  count = 0
  while n:
    n &= (n - 1)  # Removes the rightmost set bit
    count += 1
  return count
```
```cpp
// C++ implementation to count set bits
int count_set_bits(int n) {
  int count = 0;
  while (n) {
    n &= (n - 1);  // Removes the rightmost set bit
    count++;
  }
  return count;
}
```

```ruby
# Ruby implementation to count set bits
def count_set_bits(n)
  count = 0
  while n != 0
  n &= (n - 1)  # Removes the rightmost set bit
  count += 1
  end
  count
end
```

### b. Checking Power of 2
A number is a power of 2 if it has exactly one set bit: `n & (n - 1) == 0`

Example:
- `8 = 1000`: `8 & 7 = 0` → Power of 2.

### c. Getting Lowest Set Bit
Find the rightmost 1 in a number: `n & -n`

Example:
- Number: `1010`
- Lowest set bit: `1010 & -1010 = 0010`

### d. Reversing Bits
Reverse the bits of a number.

```python
def reverse_bits(n):
  result = 0
  for _ in range(32):  # Assuming 32-bit integers
    result = (result << 1) | (n & 1)
    n >>= 1
  return result
```
```cpp
// C++ implementation to reverse bits
unsigned int reverse_bits(unsigned int n) {
  unsigned int result = 0;
  for (int i = 0; i < 32; i++) {
    result <<= 1;
    result |= (n & 1);
    n >>= 1;
  }
  return result;
}
```

```ruby
# Ruby implementation to reverse bits
def reverse_bits(n)
  result = 0
  32.times do
    result = (result << 1) | (n & 1)
    n >>= 1
  end
  result
end
```

### e. Swapping Two Numbers Without Temp Variable

```python
a = a ^ b
b = a ^ b
a = a ^ b
```

```cpp
// C++ implementation to swap two numbers without a temp variable
void swap(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
```

```ruby
# Ruby implementation to swap two numbers without a temp variable
a = a ^ b
b = a ^ b
a = a ^ b
```

### f. Gray Code
A sequence where consecutive numbers differ by one bit. Convert a number to its Gray Code: `gray = n ^ (n >> 1)`

## 5. Practical Applications

### a. Subset Generation
Using bitmasking to generate subsets:

```python
def generate_subsets(nums):
  n = len(nums)
  subsets = []
  for mask in range(1 << n):
    subset = [nums[i] for i in range(n) if mask & (1 << i)]
    subsets.append(subset)
  return subsets
```
```cpp
// C++ implementation to generate subsets
#include <vector>
using namespace std;

vector<vector<int>> generate_subsets(vector<int>& nums) {
  int n = nums.size();
  vector<vector<int>> subsets;
  for (int mask = 0; mask < (1 << n); ++mask) {
    vector<int> subset;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        subset.push_back(nums[i]);
      }
    }
    subsets.push_back(subset);
  }
  return subsets;
}
```

```python
# Python implementation to generate subsets
def generate_subsets(nums):
  n = len(nums)
  subsets = []
  for mask in range(1 << n):
    subset = [nums[i] for i in range(n) if mask & (1 << i)]
    subsets.append(subset)
  return subsets
```

### b. Finding Unique Element
In an array where every element appears twice except one: `unique = a[0] ^ a[1] ^ ...`

Example:
- Array: `[2, 3, 5, 2, 3]`
- Unique: `2 ^ 3 ^ 5 ^ 2 ^ 3 = 5`

### c. Bitmask Dynamic Programming (DP)
Used in problems like the Traveling Salesman Problem (TSP), scheduling, and state compression.

## 6. Optimizations and Tips
- **Precompute Masks**: For repeated operations, precompute masks to save time.
- **Use Built-in Functions**: Many languages provide optimized bit manipulation methods, e.g., Python’s `bin()`, `int.bit_count()`, or C++’s `__builtin_popcount()`.
- **Understand Signed vs. Unsigned**: Bitwise operations behave differently for signed integers (negative numbers).

## 7. Practice Problems
1. Count the number of set bits in a number.
2. Check if a number is a power of 2.
3. Find the only non-repeating element in an array.
4. Generate all subsets of a set.
5. Solve TSP using bitmask DP.
6. Find the XOR of all numbers in a range.

Let me know if you'd like explanations, implementations, or help with any specific problems!

## What is a Bit Mask?
A bit mask is a sequence of bits (like 1010, 1111, etc.) used to perform operations on specific bits of another binary number. The mask acts like a "filter" or "template" that we apply to another binary number to manipulate specific bits.

## Why Use Bit Masks?
Bit masking is useful when you need to:

- Extract specific bits from a number.
- Modify specific bits (set, clear, or toggle them).
- Perform compact operations on binary representations.
- Optimize space and time by encoding multiple boolean flags in a single integer.

## Bit Mask Operations

### 1. Setting a Bit
You can set a specific bit (turn it into 1) using a bit mask.

**How?**
Create a mask where only the \(i\)-th bit is 1, and then perform a bitwise OR (|).

**Formula:**
`number = number | (1 << i)`

**Example:**
- Task: Set the 2nd bit (0-indexed) of the number 5 (binary: 0101).
  - Mask: `1 << 2 = 0100`
  - Operation: `0101 | 0100 = 0101`
  - Result: 5 (no change since the bit was already 1).

- Task: Set the 1st bit (0-indexed) of the number 4 (binary: 0100).
  - Mask: `1 << 1 = 0010`
  - Operation: `0100 | 0010 = 0110`
  - Result: 6.

### 2. Clearing a Bit
You can clear a specific bit (turn it into 0) using a bit mask.

**How?**
Create a mask where only the \(i\)-th bit is 0 and all other bits are 1, and then perform a bitwise AND (&).

**Formula:**
`number = number & ~(1 << i)`

**Example:**
- Task: Clear the 2nd bit (0-indexed) of the number 7 (binary: 0111).
  - Mask: `1 << 2 = 0100`, `~(1 << 2) = 1011`
  - Operation: `0111 & 1011 = 0011`
  - Result: 3.

- Task: Clear the 0th bit of the number 5 (binary: 0101).
  - Mask: `1 << 0 = 0001`, `~(1 << 0) = 1110`
  - Operation: `0101 & 1110 = 0100`
  - Result: 4.

### 3. Checking a Bit
You can check if a specific bit is 1 or 0.

**How?**
Create a mask where only the \(i\)-th bit is 1, and then perform a bitwise AND (&). If the result is non-zero, the bit is 1.

**Formula:**
`result = number & (1 << i)`

**Example:**
- Task: Check if the 2nd bit (0-indexed) of the number 5 (binary: 0101) is set.
  - Mask: `1 << 2 = 0100`
  - Operation: `0101 & 0100 = 0100` (non-zero)
  - Result: The bit is 1.

- Task: Check if the 1st bit of the number 4 (binary: 0100) is set.
  - Mask: `1 << 1 = 0010`
  - Operation: `0100 & 0010 = 0000` (zero)
  - Result: The bit is 0.

### 4. Toggling a Bit
You can flip a specific bit (change 1 to 0 or 0 to 1).

**How?**
Create a mask where only the \(i\)-th bit is 1, and then perform a bitwise XOR (^).

**Formula:**
`number = number ^ (1 << i)`

**Example:**
- Task: Toggle the 2nd bit (0-indexed) of the number 5 (binary: 0101).
  - Mask: `1 << 2 = 0100`
  - Operation: `0101 ^ 0100 = 0001`
  - Result: 1.

- Task: Toggle the 0th bit of the number 4 (binary: 0100).
  - Mask: `1 << 0 = 0001`
  - Operation: `0100 ^ 0001 = 0101`
  - Result: 5.

### 5. Extracting the Lowest Set Bit
You can isolate the rightmost 1 in a binary number.

**How?**
`lowest_bit = number & -number`

**Example:**
- Task: Extract the lowest set bit of 10 (binary: 1010).
  - Operation: `1010 & -1010 = 0010`
  - Result: 2 (binary: 0010).

### 6. Counting Set Bits
Count the number of 1s in a binary number.

**Method:**
Repeatedly remove the rightmost 1 using `n = n & (n - 1)` until `n = 0`.

**Example:**
- Task: Count the set bits in 13 (binary: 1101).
  - Iteration 1: `1101 & 1100 = 1100` → 1 set bit.
  - Iteration 2: `1100 & 1011 = 1000` → 2 set bits.
  - Iteration 3: `1000 & 0111 = 0000` → 3 set bits.
  - Result: 3.

## Practical Applications of Bit Masking

### Subset Generation
Each subset of a set can be represented as a bitmask. If the set has \(n\) elements, the subsets correspond to numbers from 0 to \(2^n - 1\) in binary.

**Example:** For {a, b, c}, the subsets are:
- `000` → {}
- `001` → {c}
- `010` → {b}
- `011` → {b, c}
- `100` → {a}
- ...

### Permissions and Flags
A single integer can encode multiple permissions:
- `0001`: Read
- `0010`: Write
- `0100`: Execute
- `1000`: Admin

To check if "Write" is enabled, use bit masking.

### Optimizing Space
Instead of using an array of booleans, use a single integer to store multiple flags.

### Finding Odd or Even Numbers
Check the least significant bit:
- `n & 1 = 0`: Even
- `n & 1 = 1`: Odd

### Solving Problems with Constraints
**Example:** The Traveling Salesman Problem can use bitmask DP to represent visited cities compactly.

## Key Takeaways
- Bit masking is a compact and efficient way to manipulate specific bits.
- Use operations like |, &, ^, and shifts (<<, >>) to create, apply, and manipulate masks.
- Practical applications span from subset generation to system programming.



## Bit Manipulation: A Comprehensive Guide

Bit manipulation involves directly working with the binary representation of numbers using bitwise operators. It is widely used for tasks like toggling, setting, clearing, and querying specific bits, often for performance optimization in algorithms.

### Why Learn Bit Manipulation?

- **Efficiency**: Bit operations are faster and use less memory compared to other operations.
- **Space Optimization**: Multiple flags or states can be stored compactly in a single integer.
- **Algorithm Design**: Many problems (like subset generation, parity checks, or advanced dynamic programming) rely on bit manipulation.
- **Practical Applications**: Cryptography, graphics, low-level programming, and competitive coding.

### Binary Representation

All integers are stored in binary form in computers. For example:

- Decimal 5 → Binary: `101`
- Decimal 10 → Binary: `1010`

### Bitwise Operators

1. **AND (`&`)**
  - Performs a logical AND between corresponding bits of two numbers.
  - Truth Table: `0 AND 0 = 0`, `0 AND 1 = 0`, `1 AND 0 = 0`, `1 AND 1 = 1`
  - Example: `5 (101) & 3 (011) = 1 (001)`

2. **OR (`|`)**
  - Performs a logical OR between corresponding bits of two numbers.
  - Truth Table: `0 OR 0 = 0`, `0 OR 1 = 1`, `1 OR 0 = 1`, `1 OR 1 = 1`
  - Example: `5 (101) | 3 (011) = 7 (111)`

3. **XOR (`^`)**
  - Performs a logical XOR (exclusive OR) between corresponding bits of two numbers.
  - Truth Table: `0 XOR 0 = 0`, `0 XOR 1 = 1`, `1 XOR 0 = 1`, `1 XOR 1 = 0`
  - Example: `5 (101) ^ 3 (011) = 6 (110)`

4. **NOT (`~`)**
  - Inverts all bits (flips 0 to 1 and 1 to 0).
  - Formula: `~x = -(x + 1)` (Two's complement representation).
  - Example: `~5 (101) = -6` (Two's complement form)

5. **Left Shift (`<<`)**
  - Shifts all bits to the left by a specified number of positions.
  - Effect: Multiplies the number by `2^n` (where `n` is the number of shifts).
  - Example: `5 (101) << 2 = 20 (10100)`

6. **Right Shift (`>>`)**
  - Shifts all bits to the right by a specified number of positions.
  - Effect: Divides the number by `2^n` (where `n` is the number of shifts).
  - Example: `5 (101) >> 1 = 2 (10)`

### Common Bit Manipulation Techniques

1. **Check if a Number is Even or Odd**
  - Use `n & 1`:
    - If `n & 1 = 1`, the number is odd.
    - If `n & 1 = 0`, the number is even.
  - Example: `10 (1010) & 1 = 0` (Even)

2. **Toggle a Bit**
  - Flip the `i`-th bit using XOR: `number = number ^ (1 << i)`
  - Example: Toggle the 2nd bit of 5 (binary `101`): `101 ^ 100 = 001`

3. **Turn Off the Rightmost 1**
  - Use `n & (n - 1)`:
    - Clears the rightmost 1.
  - Example: For 12 (binary `1100`): `n & (n - 1) = 1100 & 1011 = 1000`

4. **Check if a Number is a Power of 2**
  - A number is a power of 2 if it has exactly one 1 bit.
  - Use `n & (n - 1) = 0`.
  - Example: For 16 (binary `10000`): `16 & 15 = 10000 & 01111 = 0`

5. **Count the Number of Set Bits**
  - Use a loop and `n = n & (n - 1)` to repeatedly remove the rightmost 1.
  - Example: Count the set bits in 13 (binary `1101`):
    - Iteration 1: `1101 & 1100 = 1100`
    - Iteration 2: `1100 & 1011 = 1000`
    - Iteration 3: `1000 & 0111 = 0000`
    - Result: 3

6. **Reverse Bits**
  - Reverse the bits of a number using bitwise operations and shifting.
  - Example: Reverse 5 (binary `101`): `Reversed: 101 → 10100000 → 160`

7. **Find the Most Significant Bit (MSB)**
  - Use a loop or logarithmic method.
  - Approach: Keep right-shifting until only the MSB is left.

8. **Find the Least Significant Bit (LSB)**
  - Isolate the rightmost 1 using `n & -n`.
  - Example: For 10 (binary `1010`): `n & -n = 0010`

### Advanced Bit Manipulation Applications

1. **Subsets of a Set**
  - Generate all subsets of a set using numbers from 0 to `2^n - 1` (binary representation of each number corresponds to a subset).

2. **Dynamic Programming with Bit Masks**
  - Solve problems like the Traveling Salesman Problem using bit masks to represent visited states.

3. **Gray Code Generation**
  - Convert binary to Gray code: `gray = n ^ (n >> 1)`

4. **Hamming Distance**
  - Count the differing bits between two numbers using XOR: `distance = CountSetBits(x ^ y)`

5. **Encoding and Decoding States**
  - Efficiently encode multiple boolean flags or states into a single integer.

### Practical Tips for Bit Manipulation

- **Visualize Binary Representation**: Write numbers in binary form to understand operations better.
- **Use Standard Libraries**: Many programming languages (like Python, C++, and Java) have built-in functions for tasks like counting set bits.
- **Memorize Common Patterns**: Patterns like `n & (n - 1)` and `n & -n` frequently appear in problems.
- **Practice!**: Solve problems on platforms like LeetCode, Codeforces, or HackerRank to strengthen your understanding.