# Templates in C++

Templates are a powerful feature in C++ that allows you to write generic and reusable code. They enable functions and classes to operate with generic types, which means you can create a function or a class to work with any data type.

## Function Templates

Function templates allow you to create a single function that can work with different data types. Here is an example:

```cpp
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add<int>(2, 3) << endl;       // Output: 5
    cout << add<double>(2.5, 3.5) << endl; // Output: 6.0
    return 0;
}
```

In this example, the `add` function template can add two integers or two doubles.

## Class Templates

Class templates allow you to create a class that can handle any data type. Here is an example:

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Container {
private:
    T element;
public:
    Container(T arg) : element(arg) {}
    T getElement() {
        return element;
    }
};

int main() {
    Container<int> intContainer(42);
    Container<string> stringContainer("Hello, World!");

    cout << intContainer.getElement() << endl;       // Output: 42
    cout << stringContainer.getElement() << endl;   // Output: Hello, World!
    return 0;
}
```

In this example, the `Container` class template can store and return an element of any type.

## Template Specialization

Template specialization allows you to define a different implementation of a template for a specific type. Here is an example:

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Container {
public:
    T element;
    Container(T arg) : element(arg) {}
    void show() {
        cout << element << endl;
    }
};

// Specialization for char type
template <>
class Container<char> {
public:
    char element;
    Container(char arg) : element(arg) {}
    void show() {
        cout << "Character: " << element << endl;
    }
};

int main() {
    Container<int> intContainer(42);
    Container<char> charContainer('A');

    intContainer.show();       // Output: 42
    charContainer.show();      // Output: Character: A
    return 0;
}
```

In this example, the `Container` class template has a specialized implementation for the `char` type.

## Conclusion

Templates in C++ provide a way to write generic and reusable code. They are essential for creating functions and classes that can work with any data type, making your code more flexible and easier to maintain.