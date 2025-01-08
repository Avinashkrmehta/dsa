// Fibonacci Series using Recursion

#include<bits/stdc++.h>
using namespace std;

// Using recursion
int fib(int n){
  if(n <= 1){
    return n;
  }
  return fib(n-2) + fib(n-1);
}

// Using loop
int fibLoop(int n){
  int t0 = 0, t1 = 1, s = 0;
  if(n <= 1){
    return n;
  }
  for(int i = 2; i <= n; i++){
    s = t0 + t1;
    t0 = t1;
    t1 = s;
  }
  return s;
}

// Using memoization
int F[10];
int fibMemoization(int n){
  if(n <= 1){
    F[n] = n;
    return n;
  }
  if(F[n-2] == -1){
    F[n-2] = fibMemoization(n-2);
  }
  if(F[n-1] == -1){
    F[n-1] = fibMemoization(n-1);
  }
  return F[n-2] + F[n-1];
}

int main(){
  for(int i = 0; i < 10; i++){
    F[i] = -1;
  }
  cout << fib(10);
  cout << endl;
  cout << fibLoop(10);
  cout << endl;
  cout << fibMemoization(10);
  return 0;
}

/*
Tree Diagram:
fib(10)
|
|-- fib(8)
|   |
|   |-- fib(6)
|       |
|       |-- fib(4)
|           |
|           |-- fib(2)
|           |   |
|           |   |-- fib(0)
|           |
|           |-- fib(1)
|       
|       |-- fib(3)
|           |
|           |-- fib(1)
|           |
|           |-- fib(2)
|               |
|               |-- fib(0)
|
|-- fib(9)
|   |
|   |-- fib(7)
|       |
|       |-- fib(5)
|           |
|           |-- fib(3)
|               |
|               |-- fib(1)
|               |
|               |-- fib(2)
|                   |
|                   |-- fib(0)
|       
|       |-- fib(4)
|           |
|           |-- fib(2)
|           |   |
|           |   |-- fib(0)
|           |
|           |-- fib(1)
*/



