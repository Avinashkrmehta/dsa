// Linear Search in an Array

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

void Swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

int LinearSearch(struct Array arr, int key){
  for(int i = 0; i < arr.length; i++){
    if(key == arr.A[i]){
      return i;
    }
  }
  return -1;
}

int LinearSearchOptimize(struct Array *arr, int key){
  for(int i = 0; i < arr->length; i++){
    if(key == arr->A[i]){
      Swap(&arr->A[i], &arr->A[i-1]);
      return i;
    }
  }
  return -1;
}

int main(){
  struct Array arr = {{2,3,4,5,6}, 10, 5};
  cout << LinearSearch(arr, 6);
  cout << endl;
  cout << LinearSearchOptimize(&arr, 6);
  Display(arr);
  return 0;
}