// Reverse, left shift, right shift and reverse in an Array

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

void Reverse(struct Array *arr){
  int *B;
  int i, j;

  B = new int[arr->length];
  for(i = arr->length - 1, j = 0; i >= 0; i--, j++){
    B[j] = arr->A[i];
  }
  for(i = 0; i < arr->length; i++){
    arr->A[i] = B[i];
  }
}

void Reverse2(struct Array *arr){
  int i, j;
  for(i = 0, j = arr->length - 1; i < j; i++, j--){
    swap(arr->A[i], arr->A[j]);
  }
}

void LeftShift(struct Array *arr){
  for(int i = 0; i < arr->length - 1; i++){
    arr->A[i] = arr->A[i+1];
  }
  arr->A[arr->length - 1] = 0;
}

void RightShift(struct Array *arr){
  for(int i = arr->length - 1; i > 0; i--){
    arr->A[i] = arr->A[i-1];
  }
  arr->A[0] = 0;
}

void rotate(struct Array *arr){
  int temp = arr->A[0];
  for(int i = 0; i < arr->length - 1; i++){
    arr->A[i] = arr->A[i+1];
  }
  arr->A[arr->length - 1] = temp;
}



int main(){
  struct Array arr = {{2,3,4,5,6}, 10, 5};
  Display(arr);
  cout << endl;
  Reverse2(&arr);
  Display(arr);
  cout << endl;
  LeftShift(&arr);
  Display(arr);
  cout << endl;
  RightShift(&arr);
  Display(arr);
  cout << endl;
  rotate(&arr);
  Display(arr);
  
  return 0;
}