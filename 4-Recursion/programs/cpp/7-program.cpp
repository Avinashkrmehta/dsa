// Factorial of a given number using recursion

#include<bits/stdc++.h>
using namespace std;

// Using recursion
int factorial(int n){
  if(n == 0){
    return 1;
  }
  else
    return factorial(n-1)*n;
} 

// Using loop finding factorial of n natural numbers
int factorialLoop(int n){
  int factorial = 1;
  for(int i = 1; i <= n; i++){
    factorial *= i;
  }
  return factorial;
}

// Using formula

int main(){
    cout << factorial(5);
    cout << endl;
    cout << factorialLoop(5);
    cout << endl;
    return 0;
}

/*
Tree Diagram:
factorial(5)
|
|-- factorial(4)
|   |
|   |-- factorial(3)
|       |
|       |-- factorial(2)
|           |
|           |-- factorial(1)
|               |
|               |-- factorial(0)
*/

