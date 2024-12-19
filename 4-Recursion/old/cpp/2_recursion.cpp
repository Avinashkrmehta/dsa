// Given an array, check whether the array is in sorted order with recursion.

// Time Complexity: O(n). Space Complexity: O(n) for recursive stack space.
#include<bits/stdc++.h>
using namespace std;

int isArrayInSortedOrder(int A[],int n){
  if(n==1){
    return 1;
  }
    return (A[n-1] < A[n-2]) ? 0 : isArrayInSortedOrder(A, n - 1);
}

// int insertDataInArray(int n){
//   int A[n];
//   for(int i=0; i<n; i++){
//      cin >> A[i];
//   }
// }

// int printDataInArray(int A[], int n){
//   int A[n];
//   for(int i=0; i<n; i++){
//      cin >> A[i];
//   }
// }

int main(){
  int n;
  cin >> n;
  // insertDataInArray(n);
  int A [] = {3,4,5,6,7,8,9,1,2};

  cout << "Given array is sorted " << isArrayInSortedOrder(A,n);
  return 0;
}