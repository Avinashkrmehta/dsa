# Constructors in C++

A constructor in C++ is a special member function of a class that is automatically called when an object of that class is created. Constructors are used to initialize the objects of a class.

## Key Points

- **Name**: The constructor has the same name as the class.
- **No Return Type**: Constructors do not have a return type, not even `void`.
- **Automatic Call**: They are called automatically when an object is instantiated.
- **Overloading**: Constructors can be overloaded, meaning you can have multiple constructors with different parameters.

## Types of Constructors

1. **Default Constructor**: A constructor that takes no arguments.
    ```cpp
    class MyClass {
    public:
        MyClass() {
            // Initialization code
        }
    };
    ```

2. **Parameterized Constructor**: A constructor that takes arguments to initialize an object with specific values.
    ```cpp
    class MyClass {
    public:
        MyClass(int x, int y) {
            // Initialization code using x and y
        }
    };
    ```

3. **Copy Constructor**: A constructor that initializes an object using another object of the same class.
    ```cpp
    class MyClass {
    public:
        MyClass(const MyClass &obj) {
            // Initialization code using obj
        }
    };
    ```

## Example

```cpp
#include <iostream>
using namespace std;

class MyClass {
public:
    int a, b;

    // Default Constructor
    MyClass() {
        a = 0;
        b = 0;
    }

    // Parameterized Constructor
    MyClass(int x, int y) {
        a = x;
        b = y;
    }

    // Copy Constructor
    MyClass(const MyClass &obj) {
        a = obj.a;
        b = obj.b;
    }

    void display() {
        cout << "a: " << a << ", b: " << b << endl;
    }
};

int main() {
    MyClass obj1; // Default constructor called
    MyClass obj2(10, 20); // Parameterized constructor called
    MyClass obj3 = obj2; // Copy constructor called

    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}
```

In this example, three objects of `MyClass` are created using different constructors, and their values are displayed.
