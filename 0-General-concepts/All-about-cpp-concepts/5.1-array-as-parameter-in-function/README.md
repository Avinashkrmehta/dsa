# Array as Parameter in Function

In C++, arrays can be passed to functions as parameters. When passing an array to a function, you are actually passing a pointer to the first element of the array. This means that any changes made to the array elements within the function will affect the original array.

## Syntax

```cpp
void functionName(dataType arrayName[], int size);
```

### Example

```cpp
#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int myArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    printArray(myArray, size);
    return 0;
}
```

# Returning Array from Function

In C++, you cannot return an entire array from a function directly. However, you can return a pointer to the array or use structures or classes to encapsulate the array.

## Returning a Pointer to an Array

### Syntax

```cpp
dataType* functionName();
```

### Example

```cpp
#include <iostream>
using namespace std;

int* createArray(int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

int main() {
    int size = 5;
    int* myArray = createArray(size);
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;
    delete[] myArray; // Don't forget to free the allocated memory
    return 0;
}
```

In this example, `createArray` function returns a pointer to a dynamically allocated array. The caller is responsible for freeing the allocated memory using `delete[]`.
