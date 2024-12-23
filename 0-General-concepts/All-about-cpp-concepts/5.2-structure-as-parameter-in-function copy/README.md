# Structure as a Parameter in Function in C++

In C++, structures (structs) can be passed to functions in several ways: by value, by reference, and by pointer. Each method has its own use cases and implications.

## Passing by Value

When a structure is passed by value, a copy of the structure is made. This means that changes made to the structure inside the function do not affect the original structure.

```cpp
#include <iostream>

struct Point {
    int x, y;
};

void printPoint(Point p) {
    std::cout << "Point(" << p.x << ", " << p.y << ")\n";
}

int main() {
    Point p1 = {10, 20};
    printPoint(p1);
    return 0;
}
```

## Passing by Reference

Passing a structure by reference allows the function to modify the original structure. This method avoids the overhead of copying the structure.

```cpp
#include <iostream>

struct Point {
    int x, y;
};

void movePoint(Point &p, int dx, int dy) {
    p.x += dx;
    p.y += dy;
}

int main() {
    Point p1 = {10, 20};
    movePoint(p1, 5, -3);
    std::cout << "Point(" << p1.x << ", " << p1.y << ")\n";
    return 0;
}
```

## Passing by Pointer

Passing a structure by pointer is similar to passing by reference, but it requires the use of the arrow operator (`->`) to access the structure's members.

```cpp
#include <iostream>

struct Point {
    int x, y;
};

void movePoint(Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

int main() {
    Point p1 = {10, 20};
    movePoint(&p1, 5, -3);
    std::cout << "Point(" << p1.x << ", " << p1.y << ")\n";
    return 0;
}
```

## Summary

- **By Value**: A copy of the structure is passed. Changes do not affect the original structure.
- **By Reference**: The original structure is passed. Changes affect the original structure.
- **By Pointer**: Similar to passing by reference but uses pointers and the arrow operator.

Choosing the appropriate method depends on whether you need to modify the original structure and the performance considerations of copying large structures.