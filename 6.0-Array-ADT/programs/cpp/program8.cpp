// Inserting element in sorted element in an Array

#include<bits/stdc++.h>
using namespace std;

struct Array{
  int A[10];
  int size;
  int length;
};

void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void Display(struct Array arr){
  cout << "Elements are: ";
  for(int i = 0; i < arr.length; i++){
    cout << arr.A[i] << " ";
  }
}

void InsertSorted(struct Array * arr, int x){
  int i = arr->length - 1;
  if(arr->length == arr->size){
    return;
  }
  while(i >= 0 && arr->A[i] > x){
    arr->A[i+1] = arr->A[i];
    i--;
  }
  arr->A[i+1] = x;
  arr->length++;
}

int isSorted(struct Array arr){
  for(int i = 0; i < arr.length - 1; i++){
    if(arr.A[i] > arr.A[i+1]){
      return 0;
    }
  }
  return 1;
}

void Rearrange(struct Array *arr){
  int i = 0;
  int j = arr->length - 1;
  while(i < j){
    while(arr->A[i] < 0) i++;
    while(arr->A[j] >= 0) j--;
    if(i < j) swap(&arr->A[i], &arr->A[j]);
  }
}

int main(){
  struct Array arr = {{2,3,5,6,7}, 10, 5};
  InsertSorted(&arr, 4);
  cout << isSorted(arr);
  cout << endl;
  Display(arr);
  struct Array arr1 = {{-2,2,3,-4,5,6,-7,7}, 10, 7};
  Rearrange(&arr1);
  cout << endl;
  Display(arr1);
  return 0;
}