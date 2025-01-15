// Set, Get, Max in an Array

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

int Get(struct Array arr, int index){
  if(index >= 0 && index < arr.length){
    return arr.A[index];
  }
  return -1;
}

int Set(struct Array *arr, int index, int x){
  if(index >= 0 && index < arr->length){
    arr->A[index] = x;
    return 1;
  }
  return -1;
}

int Max(struct Array arr){
  int max = arr.A[0];
  for(int i = 1; i < arr.length; i++){
    if(arr.A[i] > max){
      max = arr.A[i];
    }
  }
  return max;
}

int Min(struct Array arr){
  int min = arr.A[0];
  for(int i = 1; i < arr.length; i++){
    if(arr.A[i] < min){
      min = arr.A[i];
    }
  }
  return min;
}

int Sum(struct Array arr){
  int sum = 0;
  for(int i = 0; i < arr.length; i++){
    sum += arr.A[i];
  }
  return sum;
}

float Avg(struct Array arr){
  return (float)Sum(arr)/arr.length;
}


int main(){
  struct Array arr = {{2,3,4,5,6}, 10, 5};
  Display(arr);
  cout << endl;
  cout << Get(arr, 2);
  cout << endl;
  cout << Set(&arr, 2, 10);
  cout << endl;
  cout << Max(arr);
  cout << endl;
  cout << Min(arr);
  cout << endl;
  cout << Sum(arr);
  cout << endl;
  cout << Avg(arr);
  cout << endl;

  Display(arr);
  return 0;
}