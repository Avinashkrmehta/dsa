// Structure of an Array

#include<bits/stdc++.h>
using namespace std;

struct Arraypointer{
  int *A;
  int size;
  int length;
};

struct Array{
  int A[20];
  int size;
  int length;
};

void Display(struct Array arr){
  cout << "Elements are: ";
  for(int i = 0; i < arr.length; i++){
    cout << arr.A[i] << " ";
  }
}

int main(){
  struct Array arr = {{2,3,4,5,6}, 20, 5};
  Display(arr);



  struct Arraypointer arrpointer;
  cout << "Enter the size of the array: ";
  cin >> arr.size;
  arrpointer.A = new int[arr.size];
  arrpointer.length = 0;
  cout << "Enter the number of elements: ";
  cin >> arr.length;
  cout <<  arr.length;
  cout << endl;

  for(int i = 0; i < arr.length; i++){
    cin >> arr.A[i];
  }
  Display(arr);



  return 0;
}