// Sum of n natural number using recursion

#include<bits/stdc++.h>
using namespace std;

// Using recursion
int sum(int n){
  if(n == 0){
    return 0;
  }
  else
    return sum(n-1)+ n;
} 

// Using loop finding sum of n natural numbers
int sumLoop(int n){
  int sum = 0;
  for(int i = 1; i <= n; i++){
    sum += i;
  }
  return sum;
}

// Using formula
int sumFormula(int n){
  return n*(n+1)/2;
}

int main(){
    cout << sum(5);
    cout << endl;
    cout << sumLoop(5);
    cout << endl;
    cout << sumFormula(5);
    return 0;
}

/*
Tree Diagram:
sum(5)
|
|-- sum(4)
|   |
|   |-- sum(3)
|       |
|       |-- sum(2)
|           |
|           |-- sum(1)
|               |
|               |-- sum(0)
*/

