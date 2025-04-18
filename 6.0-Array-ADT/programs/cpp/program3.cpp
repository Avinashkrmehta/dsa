// Delete element in Array

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

void Append(struct Array *arr, int x){
  if(arr->length < arr->size){
    arr->A[arr->length++] = x;
  }
}

void Insert(struct Array *arr, int index, int x){
  if(index >= 0 && index <= arr->length){
    for(int i = arr->length; i > index; i--){
      arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = x;
    arr->length++;
  }
}

int Delete(struct Array *arr, int index){
  int x = 0;
  if(index >= 0 && index < arr->length){
    x = arr->A[index];
    for(int i = index; i < arr->length-1; i++){
      arr->A[i] = arr->A[i+1];
    }
    arr->length--;
    return x;
  }
  return 0;
}

int main(){
  struct Array arr = {{2,3,4,5,6}, 10, 5};
  Display(arr);
  cout << endl;
  Append(&arr, 10);
  Display(arr);
  cout << endl;
  Insert(&arr, 2, 12);
  Display(arr);
  cout << endl;
  cout << Delete(&arr, 2);
  cout << endl;
  Display(arr);

  return 0;
}