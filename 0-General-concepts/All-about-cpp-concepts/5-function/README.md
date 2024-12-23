# Functions in C++

A function is a block of code that performs a specific task. It is defined with a name and can be called to execute the code it contains. Functions help in organizing code, making it reusable, and improving readability.

## Syntax of a Function

```cpp
return_type function_name(parameters) {
    // function body
}
```

- `return_type`: The type of value the function returns. Use `void` if the function does not return a value.
- `function_name`: The name of the function.
- `parameters`: A list of parameters the function takes (optional).

## Parameter Passing

In C++, parameters can be passed to functions in three ways:

1. **Pass by Value**
2. **Pass by Address**
3. **Pass by Reference**

### Pass by Value

When parameters are passed by value, a copy of the actual parameter's value is made in memory. Changes made to the parameter inside the function do not affect the original value.

```cpp
void passByValue(int x) {
    x = 10; // This change will not affect the original value
}

int main() {
    int a = 5;
    passByValue(a);
    // a is still 5
}
```

### Pass by Address

When parameters are passed by address, the address of the actual parameter is passed to the function. This allows the function to modify the original value.

```cpp
void passByAddress(int *x) {
    *x = 10; // This change will affect the original value
}

int main() {
    int a = 5;
    passByAddress(&a);
    // a is now 10
}
```

### Pass by Reference

When parameters are passed by reference, an alias for the actual parameter is passed to the function. This also allows the function to modify the original value.

```cpp
void passByReference(int &x) {
    x = 10; // This change will affect the original value
}

int main() {
    int a = 5;
    passByReference(a);
    // a is now 10
}
```

Each method of parameter passing has its own use cases and benefits. Choose the appropriate method based on whether you need to modify the original value or just work with a copy.