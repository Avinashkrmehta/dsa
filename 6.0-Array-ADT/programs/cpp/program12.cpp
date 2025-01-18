// Converting program to cpp from cMenu Driven Program in an Array

#include<bits/stdc++.h>
using namespace std;

class Array{
  private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);
  public:
    Array(){
      size = 10;
      length = 0;
      A = new int[size];
    }
    Array(int sz){
      size = sz;
      length = 0;
      A = new int[size];
    }
    ~Array(){
      delete []A;
    }
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
    int LinearSearchOptimize(int key);
    int BinarySearch(int key);
    int BinarySearchRecursive(int l, int h, int key);
    int Get(int index);
    int Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void LeftShift();
    void RightShift();
    void rotate();
    void InsertSorted(int x);
    int isSorted();
    void Rearrange();
    Array* mergeArrays(Array arr2);
    Array* unionArray(Array arr2);
    Array* intersectionArray(Array arr2);
    Array* differenceArray(Array arr2);
};

void  Array::swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void Array::Display(){
  cout << "Elements are: ";
  for(int i = 0; i < length; i++){
    cout << A[i] << " ";
  }
}

void  Array::Append(int x){
  if(length < size){
    A[length++] = x;
  }
}

void Array::Insert(int index, int x){
  if(index >= 0 && index <= length){
    for(int i = length; i > index; i--){
      A[i] = A[i-1];
    }
    A[index] = x;
    length++;
  }
}

int Array::Delete(int index){
  int x = 0;
  if(index >= 0 && index <length){
    x =A[index];
    for(int i = index; i <length-1; i++){
     A[i] =A[i+1];
    }
   length--;
    return x;
  }
  return 0;
}

int Array::LinearSearch(int key){
  for(int i = 0; i < length; i++){
    if(key == A[i]){
      return i;
    }
  }
  return -1;
}

int Array::LinearSearchOptimize(int key){
  for(int i = 0; i < length; i++){
    if(key == A[i]){
      swap(&A[i], &A[i-1]);
      return i;
    }
  }
  return -1;
}

int Array::BinarySearch(int key){
  int l = 0;
  int h =length - 1;
  int mid;
  while(l <= h){
    mid = (l+h)/2;
    if(key ==A[mid]){
      return mid;
    }
    else if(key <A[mid]){
      h = mid - 1;
    }
    else{
      l = mid + 1;
    }
  }
  return -1;
}

int Array::BinarySearchRecursive(int l, int h, int key){
  int mid;
  if(l <= h){
    mid = (l+h)/2;
    if(key == A[mid]){
      return mid;
    }
    else if(key < A[mid]){
      return Array::BinarySearchRecursive(l, mid-1, key);
    }
    else{
      return Array::BinarySearchRecursive( mid+1, h, key);
    }
  }
  return -1;
}

int  Array::Get(int index){
  if(index >= 0 && index <length){
    return A[index];
  }
  return -1;
}

int  Array::Set(int index, int x){
  if(index >= 0 && index < length){
    A[index] = x;
    return 1;
  }
  return -1;
}

int  Array::Max(){
  int max = A[0];
  for(int i = 1; i < length; i++){
    if(A[i] > max){
      max = A[i];
    }
  }
  return max;
}

int  Array::Min(){
  int min = A[0];
  for(int i = 1; i < length; i++){
    if(A[i] < min){
      min = A[i];
    }
  }
  return min;
}

int  Array::Sum(){
  int sum = 0;
  for(int i = 0; i < length; i++){
    sum += A[i];
  }
  return sum;
}

float  Array::Avg(){
  return (float)Sum()/length;
}

void  Array::Reverse(){
  int *B;
  int i, j;

  B = new int[length];
  for(i = length - 1, j = 0; i >= 0; i--, j++){
    B[j] = A[i];
  }
  for(i = 0; i < length; i++){
    A[i] = B[i];
  }
}

void Array::Reverse2(){
  int i, j;
  for(i = 0, j = length - 1; i < j; i++, j--){
    Array::swap(&A[i], &A[j]);
  }
}

void  Array::LeftShift(){
  for(int i = 0; i < length - 1; i++){
    A[i] = A[i+1];
  }
  A[length - 1] = 0;
}

void  Array::RightShift(){
  for(int i = length - 1; i > 0; i--){
    A[i] = A[i-1];
  }
  A[0] = 0;
}

void  Array::rotate(){
  int temp = A[0];
  for(int i = 0; i < length - 1; i++){
    A[i] = A[i+1];
  }
  A[length - 1] = temp;
}

void  Array::InsertSorted(int x){
  int i = length - 1;
  if(length == size){
    return;
  }
  while(i >= 0 && A[i] > x){
    A[i+1] = A[i];
    i--;
  }
  A[i+1] = x;
  length++;
}

int  Array::isSorted(){
  for(int i = 0; i < length - 1; i++){
    if(A[i] > A[i+1]){
      return 0;
    }
  }
  return 1;
}

void  Array::Rearrange(){
  int i = 0;
  int j = length - 1;
  while(i < j){
    while(A[i] < 0) i++;
    while(A[j] >= 0) j--;
    if(i < j) swap(&A[i], &A[j]);
  }
}

Array* Array::mergeArrays(Array arr2){
  int i, j, k;
  i = j = k = 0;
  Array *arr3 = new Array(length + arr2.length);
  while(i < length && j < arr2.length){
    if(A[i] < arr2.A[j]){
      arr3->A[k++] = A[i++];
    }else{
      arr3->A[k++] = arr2.A[j++];
    }
  }

  for(; i < length; i++){
    arr3->A[k++] = A[i];
  }

  for(; j < arr2.length; j++){
    arr3->A[k++] = arr2.A[j];
  }
  arr3->length = length + arr2.length;
  return arr3;
}

Array*  Array::unionArray(struct Array arr2){
  int i, j, k;
  i = j = k = 0;
 Array *arr3 = new Array(length + arr2.length);
  while(i < length && j < arr2.length){
    if(A[i] < arr2.A[j]){
      arr3->A[k++] = A[i++];
    }else if(arr2.A[j] < A[i]){
      arr3->A[k++] = arr2.A[j++];  
    }else{
      arr3->A[k++] = A[i++];
      j++;
    }
  }

  for(; i < length; i++){
    arr3->A[k++] = A[i];
  }

  for(; j < arr2.length; j++){
    arr3->A[k++] = arr2.A[j];
  }
  arr3->length = k;
  arr3->size = 10;
  return arr3;
}


Array* Array::intersectionArray(struct Array arr2){
  int i, j, k;
  i = j = k = 0;
  Array *arr3 = new Array(length + arr2.length);
  while(i < length && j < arr2.length){
    if(A[i] < arr2.A[j]){
      i++;
    }else if(arr2.A[j] < A[i]){
      j++;  
    }else{
      arr3->A[k++] = A[i++];
      j++;
    }
  }

  arr3->length = k;
  arr3->size = 10;
  return arr3;
}

Array* Array::differenceArray(struct Array arr2){
  int i, j, k;
  i = j = k = 0;
  Array *arr3 = new Array(length + arr2.length);
  while(i < length && j < arr2.length){
    if(A[i] < arr2.A[j]){
       arr3->A[k++] = A[i++];
    }else if(arr2.A[j] < A[i]){
      j++;  
    }else{
      i++;
      j++;
    }
  }
  for(; i < length; i++){
    arr3->A[k++] = A[i];
  }

  arr3->length = k;
  arr3->size = 10;
  return arr3;
}

int main(){
  Array *arr1;
  int ch,sz;
  int x, index;

  cout << "Enter size of an array: ";
  cin >> sz;
  cout << sz;
  cout<< endl;
  arr1 = new Array(sz);
  cout << "Menu\n";
  cout << "1. Display Array\n";
  cout << "2. Append\n";
  cout << "3. Insert\n";
  cout << "4. Delete\n";
  cout << "5. Linear Search\n";
  cout << "6. Exit\n";
  cout << "Enter your choice: ";
  cin >> ch;
  cout << ch;
  cout << endl;
    switch(ch){
      case 1:
        arr1->Display();
        break;
      case 2:
        int x;
        cout << "Enter an element to append: ";
        cin >> x;
        arr1->Append(x);
        break;
      case 3:
        int index;
        cout << "Enter an index to insert: ";
        cin >> index;
        cout << index;
        cout << endl;
        cout << "Enter an element to insert: ";
        cin >> x;
        cout << x;
        cout<< endl;
        arr1->Insert(index, x);
        break;
      case 4:
        cout << "Enter an index to delete: ";
        cin >> index;
        cout << arr1->Delete(index);
        break;
      case 5:
        cout << "Enter an element to search: ";
        cin >> x;
        cout << arr1->LinearSearch(x);
        break;
      case 6:
      break;
    }
    cout << "Enter your choice: ";
    cin >> ch;

  return 0;
}