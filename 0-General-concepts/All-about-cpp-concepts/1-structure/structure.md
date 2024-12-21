# Structure in C++

## Defining a Structure

A structure in C++ is a user-defined data type that allows grouping variables of different types under a single name. It is defined using the `struct` keyword.

```cpp
struct Person {
    std::string name;
    int age;
    float height;
};
```

## Size of a Structure

The size of a structure is the sum of the sizes of its members, but it may include padding for alignment. You can use the `sizeof` operator to determine the size of a structure.

```cpp
#include <iostream>

struct Person {
    std::string name;
    int age;
    float height;
};

int main() {
    std::cout << "Size of Person structure: " << sizeof(Person) << " bytes" << std::endl;
    return 0;
}
```

## Declaring a Structure

Once a structure is defined, you can declare variables of that structure type.

```cpp
Person person1;
Person person2 = {"Alice", 30, 5.5};
```

## Accessing Structure Members

You can access the members of a structure using the dot (`.`) operator.

```cpp
#include <iostream>

struct Person {
    std::string name;
    int age;
    float height;
};

int main() {
    Person person1;
    person1.name = "Bob";
    person1.age = 25;
    person1.height = 6.0;

    std::cout << "Name: " << person1.name << std::endl;
    std::cout << "Age: " << person1.age << std::endl;
    std::cout << "Height: " << person1.height << std::endl;

    return 0;
}
```
