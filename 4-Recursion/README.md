# Recursion

Many functions and procedures can be implemented using recursion, allowing them to be written as recursive functions.

<img src="./images/image_a.png" width="600" />
<img src="./images/image_b.png" width="600" />

A function that calls itself is called a recursive function. Inside a recursive function, there must be a base condition to terminate the recursion.

<img src="./images/image_c.png" width="600" />
<img src="./images/image_d.png" width="600" />
<img src="./images/image_e.png" width="600" />
<img src="./images/image_f.png" width="600" />

## Generalizing Recursion

Recursion consists of two phases: the **calling phase** and the **returning phase**. 

While both loops and recursion involve repetition, a loop has only an ascending phase, whereas recursion has both ascending and descending phases.

<img src="./images/image_g.png" width="600" />

## How Recursion Uses Stack

Model of memory divided into three parts: heap, stack, and main memory. For `n` total, there will be `n+1` activation records.

<img src="./images/image_h.png" width="600" />
<img src="./images/image_i.png" width="600" />

## Recurrence Relation - Time Complexity of Recursion

Every statement in a program takes one unit of time. We don't mention seconds or milliseconds of time.

<img src="./images/image_j.png" width="600" />
<img src="./images/image_k.png" width="600" />

## TailHead

```ruby
Head Recursion
#include <stdio.h>
void fun(int n){
  if(n>0){
    fun(n-1);
    printf("%d ",n);
  }
}

int main() {
  int x=3;
  fun(x);
  return 0;
}

Tail Recursion
#include <stdio.h>
void fun(int n)
{
  if(n>0){
    printf("%d ",n);
    fun(n-1);
  }
}

int main() {
  int x=3;
  fun(x);
  return 0;
}
```

## Static and Global Variables in Recursion

<img src="./images/image_l.png" width="600" />
<img src="./images/image_m.png" width="600" />
<img src="./images/image_n.png" width="600" />

## Types of Recursion
<img src="./images/image_o.png" width="600" />

## Tail Recursion
In tail recursion, during the returning time, it doesn't perform any operation.

<img src="./images/image_p.png" width="600" />

Tail recursion can be easily converted into the form of a loop.

<img src="./images/image_r.png" width="600" />

## Head Recursion
In head recursion, the function doesn't do any operation at the time of calling; it performs operations at returning time.

<img src="./images/image_s.png" width="600" />

Head recursion can be easily converted into a loop by looking at the function.

<img src="./images/image_t.png" width="600" />

## Tree Recursion
If a function calls itself more than once, then it is tree recursion.

<img src="./images/image_u.png" width="600" />
<img src="./images/image_v.png" width="600" />
<img src="./images/image_w.png" width="600" />

## Indirect Recursion
In indirect recursion, there are multiple functions where it forms a circular loop of functions.

<img src="./images/image_x.png" width="600" />
<img src="./images/image_y.png" width="600" />

## Nested Recursion

In nested recursion, the recursive function's parameter passed is a recursive call. We can call recursion inside recursion.

<img src="./images/image_z.png" width="600" />
<img src="./images/image_za.png" width="600" />

## Sum of First n Natural Numbers

<img src="./images/image_zb.png" width="600" />
<img src="./images/image_zc.png" width="600" />
<img src="./images/image_zd.png" width="600" />

## Factorial of a Given Number

<img src="./images/image_ze.png" width="600" />

## Power Using Recursion (Exponent Using Recursion)

<img src="./images/image_zf.png" width="600" />
<img src="./images/image_zg.png" width="600" />
<img src="./images/image_zh.png" width="600" />

[Power using recursion](/4-Recursion/programs/cpp/8-program.cpp)

## Taylor Series Using Recursion

<img src="./images/image_zi.png" width="600" />
<img src="./images/image_zj.png" width="600" />
<img src="./images/image_zk.png" width="600" />
<img src="./images/image_zl.png" width="600" />

[Taylor Series using recursion](/4-Recursion/programs/cpp/9-program.cpp)

## Taylor Series Using Horner's Rule

<img src="./images/image_zm.png" width="600" />
<img src="./images/image_zn.png" width="600" />
<img src="./images/image_zo.png" width="600" />

[Taylor series using Horner's Rule](/4-Recursion/programs/cpp/10-program.cpp)

## Fibonacci Series Using Recursion

<img src="./images/image_zp.png" width="600" />
<img src="./images/image_zq.png" width="600" />
<img src="./images/image_zr.png" width="600" />
<img src="./images/image_zs.png" width="600" />

[Fibonacci Series using Memoization](/4-Recursion/programs/cpp/11-program.cpp)

## Combination Formula Using Recursion

<img src="./images/image_zt.png" width="600" />
<img src="./images/image_zu.png" width="600" />
<img src="./images/image_zv.png" width="600" />

[Combination Formula using recursion](/4-Recursion/programs/cpp/12-program.cpp)

## Tower of Hanoi Problem

<img src="./images/image_zw.png" width="600" />
<img src="./images/image_zx.png" width="600" />
<img src="./images/image_zy.png" width="600" />
<img src="./images/image_zz.png" width="600" />

## quiz problem

<img src="./images/image_zza.png" width="600" />
<img src="./images/image_zzb.png" width="600" />
<img src="./images/image_zzc.png" width="600" />
<img src="./images/image_zzd.png" width="600" />










---

## Recursion Notes

Recursion is a programming technique where a function calls itself in order to solve a problem. It is a powerful tool for solving problems that can be broken down into smaller, similar sub-problems.

### How Recursion Works

A recursive function typically has two main components:
1. **Base Case**: The condition under which the function stops calling itself. This prevents infinite recursion.
2. **Recursive Case**: The part of the function where it calls itself with a modified argument, moving towards the base case.

#### Example: Factorial Function

The factorial of a non-negative integer `n` is the product of all positive integers less than or equal to `n`. It is denoted by `n!`.

##### Factorial Function in Pseudocode
```pseudocode
function factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)
```

### Diagram of Recursive Calls

Consider the calculation of `factorial(3)`:

```
factorial(3)
|
|---> 3 * factorial(2)
          |
          |---> 2 * factorial(1)
                    |
                    |---> 1 * factorial(0)
                              |
                              |---> 1 (base case)
```

The recursive calls can be visualized as a tree:

```
factorial(3)
  |
  +---> 3 * factorial(2)
          |
          +---> 2 * factorial(1)
                    |
                    +---> 1 * factorial(0)
                              |
                              +---> 1 (base case)
```

### Advantages of Recursion
- Simplifies code for problems that have a natural recursive structure (e.g., tree traversal, factorial calculation).
- Reduces the need for complex loops and auxiliary data structures.

### Disadvantages of Recursion
- Can lead to high memory usage due to the call stack.
- May result in stack overflow if the base case is not reached or the recursion depth is too large.

## Conclusion

Recursion is a fundamental concept in computer science that provides a clear and concise way to solve problems that can be divided into similar sub-problems. Understanding how to implement and optimize recursive functions is essential for efficient problem-solving.
