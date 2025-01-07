// Power of given number using recursion

#include<bits/stdc++.h>
using namespace std;

// Using recursion
int power(int m, int n){
  if(n == 0){
    return 1;
  }
  else
    return power(m, n-1)*m;
}

// Using loop finding power of a number
int powerLoop(int m, int n){
  int power = 1;
  for(int i = 1; i <= n; i++){
    power *= m;
  }
  return power;
}

// Using formula
int powerFormula(int m, int n){
  if(n == 0){
    return 1;
  }
  if(n%2 == 0){
    return powerFormula(m*m, n/2);
  }
  else
    return m*powerFormula(m*m, (n-1)/2);
}


int main(){
    cout << power(5,4);
    cout << endl;
    cout << powerLoop(5,4);
    cout << endl;
    cout << powerFormula(5,4);
    return 0;
}

