// Set Operation in an Array

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

struct Array* mergeArrays(struct Array *arr1, struct Array *arr2){
  int i, j, k;
  i = j = k = 0;
  struct Array *arr3 = new struct Array;
  while(i < arr1->length && j < arr2->length){
    if(arr1->A[i] < arr2->A[j]){
      arr3->A[k++] = arr1->A[i++];
    }else{
      arr3->A[k++] = arr2->A[j++];
    }
  }

  for(; i < arr1->length; i++){
    arr3->A[k++] = arr1->A[i];
  }

  for(; j < arr2->length; j++){
    arr3->A[k++] = arr2->A[j];
  }
  arr3->length = arr1->length + arr2->length;
  arr3->size = 10;
  return arr3;
}

struct Array* unionArray(struct Array *arr1, struct Array *arr2){
  int i, j, k;
  i = j = k = 0;
  struct Array *arr3 = new struct Array;
  while(i < arr1->length && j < arr2->length){
    if(arr1->A[i] < arr2->A[j]){
      arr3->A[k++] = arr1->A[i++];
    }else if(arr2->A[j] < arr1->A[i]){
      arr3->A[k++] = arr2->A[j++];  
    }else{
      arr3->A[k++] = arr1->A[i++];
      j++;
    }
  }

  for(; i < arr1->length; i++){
    arr3->A[k++] = arr1->A[i];
  }

  for(; j < arr2->length; j++){
    arr3->A[k++] = arr2->A[j];
  }
  arr3->length = k;
  arr3->size = 10;
  return arr3;
}


struct Array* intersectionArray(struct Array *arr1, struct Array *arr2){
  int i, j, k;
  i = j = k = 0;
  struct Array *arr3 = new struct Array;
  while(i < arr1->length && j < arr2->length){
    if(arr1->A[i] < arr2->A[j]){
      i++;
    }else if(arr2->A[j] < arr1->A[i]){
      j++;  
    }else{
      arr3->A[k++] = arr1->A[i++];
      j++;
    }
  }

  arr3->length = k;
  arr3->size = 10;
  return arr3;
}

struct Array* differenceArray(struct Array *arr1, struct Array *arr2){
  int i, j, k;
  i = j = k = 0;
  struct Array *arr3 = new struct Array;
  while(i < arr1->length && j < arr2->length){
    if(arr1->A[i] < arr2->A[j]){
       arr3->A[k++] = arr1->A[i++];
    }else if(arr2->A[j] < arr1->A[i]){
      j++;  
    }else{
      i++;
      j++;
    }
  }
  for(; i < arr1->length; i++){
    arr3->A[k++] = arr1->A[i];
  }

  arr3->length = k;
  arr3->size = 10;
  return arr3;
}

int main(){
  struct Array arr1 = {{2,6,10,15,25}, 10, 5};
  struct Array arr2 = {{3,6,7,15,20}, 10, 5};
  // cout << "Union of the two arrays: ";
  // struct Array *arr3 = unionArray(&arr1, &arr2);
  // cout << endl;
  // cout << "Intersection of the two arrays: ";
  struct Array *arr3 = differenceArray(&arr1, &arr2);
  Display(*arr3);
  return 0;
}