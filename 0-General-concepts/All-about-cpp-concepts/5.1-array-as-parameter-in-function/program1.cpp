#include<bits/stdc++.h>
using namespace std;

void fun(int A[], int n) {
  for(int i = 0; i < n; i++) {
    cout << A[i] << endl;
  }
}

void fun1(int *A, int n) {
  for(int i = 0; i < n; i++) {
    cout << A[i] << endl;
  }
}


int* fun2(int n){
  int *p;
  p = new int[n];
  for(int i = 0; i < n; i++) {
    p[i] = i + 1;
  }
  return p;
}

int main() {
  int A[] = {2, 4, 6, 8, 10};
  int n = 5;
  fun(A, n);
  fun1(A, n);
  fun2(n);
  int *ptr = fun2(n);
  for(int i = 0; i < n; i++) {
    cout << ptr[i] << endl;
  }
  return 0;
}