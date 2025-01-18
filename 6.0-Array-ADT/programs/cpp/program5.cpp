// Binary Search in an Array

#include<bits/stdc++.h>
using namespace std;

struct Array{
  int A[10];
  int size;
  int length;
};

void Display(struct Array arr){
  cout << "Elements are: ";
  for(int i = 0; i < arr.length; i++){
    cout << arr.A[i] << " ";
  }
}

int BinarySearch(struct Array arr, int key){
  int l = 0;
  int h = arr.length - 1;
  int mid;
  while(l <= h){
    mid = (l+h)/2;
    if(key == arr.A[mid]){
      return mid;
    }
    else if(key < arr.A[mid]){
      h = mid - 1;
    }
    else{
      l = mid + 1;
    }
  }
  return -1;
}

int BinarySearchRecursive(struct Array arr, int l, int h, int key){
  int mid;
  if(l <= h){
    mid = (l+h)/2;
    if(key == arr.A[mid]){
      return mid;
    }
    else if(key < arr.A[mid]){
      return BinarySearchRecursive(arr, l, mid-1, key);
    }
    else{
      return BinarySearchRecursive(arr, mid+1, h, key);
    }
  }
  return -1;
}


int main(){
  struct Array arr = {{2,3,4,5,6}, 10, 5};
  cout << BinarySearch(arr, 6);
  cout << endl;
  cout << BinarySearchRecursive(arr, 0, arr.length-1, 6);
  cout << endl;
  Display(arr);
  return 0;
}