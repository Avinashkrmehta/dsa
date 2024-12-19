// Generate all the strings of n bits. Assume A[0..n – 1] is an array of size n.

#include<bits/stdc++.h>
using namespace std;

string A = "Av";
int binary(int n){
  if(n<1){
    cout << A << endl;
  }else{
    A[n-1] = '0';
    binary(n -1);
    A[n-1] = '1';
    binary(n-1);
  }
}


int main(){
  int n;
  cin >> n;
  int arr[n];
  cout << "Given string " << A  << binary(n);
  return 0;
}