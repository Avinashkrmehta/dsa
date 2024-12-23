# Classes in C++

A class in C++ is a user-defined data type that serves as a blueprint for creating objects. It encapsulates data and functions that operate on the data, providing a way to model real-world entities.

## Defining a Class

A class is defined using the `class` keyword followed by the class name and a pair of curly braces. Inside the braces, you can declare member variables and member functions.

```cpp
class MyClass {
public:
    int myNumber; // Member variable
    void myFunction() { // Member function
        // Function implementation
    }
};
```

## Access Specifiers

Classes in C++ use access specifiers to control the visibility of their members. The three access specifiers are:
- `public`: Members are accessible from outside the class.
- `private`: Members are accessible only within the class.
- `protected`: Members are accessible within the class and by derived classes.

## Creating Objects

Once a class is defined, you can create objects of that class type.

```cpp
MyClass obj; // Creating an object of MyClass
obj.myNumber = 5; // Accessing member variable
obj.myFunction(); // Calling member function
```

## Constructors and Destructors

- **Constructor**: A special member function that is called when an object is created. It initializes the object.
- **Destructor**: A special member function that is called when an object is destroyed. It cleans up the resources used by the object.

```cpp
class MyClass {
public:
    MyClass() { // Constructor
        // Initialization code
    }
    ~MyClass() { // Destructor
        // Cleanup code
    }
};
```

## Inheritance

C++ supports inheritance, allowing a class to inherit properties and behaviors from another class.

```cpp
class Base {
public:
    int baseVar;
};

class Derived : public Base {
public:
    int derivedVar;
};
```

## Example

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    string model;
    int year;

    void displayInfo() {
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << endl;
    }
};

int main() {
    Car car1;
    car1.brand = "Toyota";
    car1.model = "Corolla";
    car1.year = 2020;
    car1.displayInfo();

    return 0;
}
```

In this example, `Car` is a class with three member variables and one member function. An object `car1` of the `Car` class is created and its members are accessed and modified.

Classes in C++ provide a powerful way to model complex systems by encapsulating data and functions, promoting code reusability and maintainability.