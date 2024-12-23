## Arrays in C++: Declarations and Memory Allocation

### Declaration of Arrays

In C++, arrays are similar to those in C, with a collection of elements of the same type stored in contiguous memory locations. The syntax for declaring an array is the same:

```cpp
type arrayName[arraySize];
```

### Example

```cpp
int numbers[5]; // Declares an array of 5 integers
char letters[10]; // Declares an array of 10 characters
```

### Memory Allocation for Arrays

Memory allocation for arrays in C++ can be done both statically and dynamically.

#### Static Allocation

As in C, static allocation in C++ occurs at compile time, and the size of the array must be a constant expression.

#### Dynamic Allocation

In C++, dynamic memory allocation is typically done using the `new` operator, which allows the array size to be determined at runtime.

### Example

```cpp
#include <iostream>

int main() {
    int size = 5;
    int* dynamicArray = new int[size];

    if (dynamicArray == nullptr) {
        // Handle memory allocation failure
        return 1;
    }

    // Use the array
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = i * 2;
    }

    // Print the array elements
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }

    // Free the allocated memory
    delete[] dynamicArray;

    return 0;
}
```

In this example:
- `new` allocates memory for an array of 5 integers.
- `delete[]` deallocates the memory once it is no longer needed.

### Summary

- Arrays in C++ are declared similarly to C with a specific type and size.
- Memory for arrays can be allocated statically or dynamically.
- Dynamic allocation in C++ uses the `new` operator and allows for flexible array sizes determined at runtime.
- The `delete[]` operator is used to deallocate dynamically allocated memory.