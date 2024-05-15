// Static Vs Dynamic Array
#include<bits/stdc++.h>
using namespace std;
int main(){
  int A[5]; 
  int n;
  cin >> n;
  int B[n];

  for(int i=0; i< n; i++){
    cout<< B[i] << " ";
  }

cout << endl;
// creating Array in Heap memory
  int *P;
  P = new int[5];

  for(int i=0; i< n; i++){
    cout<< P[i] << " ";
  }
  return 0;
}