// Combination Formula using Recursion

#include<bits/stdc++.h>
using namespace std;

// Factorial formula n! = n*(n-1)*(n-2)*...*1
int fact(int n){
  if(n == 0){
    return 1;
  }
  return fact(n-1)*n;
}


// Combination formula nCr = n!/(r!*(n-r)!)
int nCr(int n, int r){
  int num, den;
  num = fact(n);
  den = fact(r)*fact(n-r);
  return num/den;
}

// Recursive formula for nCr
int nCrRecursion(int n, int r){
  if(n == r || r == 0){
    return 1;
  }
  return nCrRecursion(n-1, r-1) + nCrRecursion(n-1, r);
}

int main(){
  cout << nCr(5, 2);
  cout << endl;
  cout << nCrRecursion(5, 2);
  return 0;
}

