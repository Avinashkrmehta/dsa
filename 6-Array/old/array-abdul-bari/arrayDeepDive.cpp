// Array Introduction
#include<bits/stdc++.h>
using namespace std;

class Array{
  private:
    int *A;
    int size;
    int length;
  public:
  Array(){
    size = 10;
    length=0;
    A = new int[size];
  }
  Array(int size){
    size = size;
    length=0;
    A = new int[size];
  }
  ~Array(){
    delete []A;
  }
  void DefaltElement();
  void Display();
  void Insert(int index, int n);
  void AddAppend(int n);
  int Delete(int index);
  int LinearSearch(int key);
  int BinarySearch(int key);
  int RecursiveBinarySearch(int low, int high,int key);
  int Get(int index);
  void Set(int index, int num);
  int Max();
  int Min();
  int Sum();
  int Average();
};

void Array::DefaltElement(){
  int i,j;
  for(i=0,j=1; i < 5; i++,j++){
    A[i] =j+1 ;
    length++;
  }
}

void Array::Display(){
  int i;
  cout << "Element of the Array are"<< endl;
  for(i=0; i < length; i++){
    cout << A[i] << " ";
  }
  cout <<endl << "length-->" << length << endl;
  cout << "size-->" << size << endl;
}

void Array::Insert(int index,int n){
  int i;
  if (index >=0 && index <=length){
    for(i = length;i >= index; i--){
      A[i] = A[i-1];
    }
    A[index] = n;
    length++;

  }
}

void Array::AddAppend(int n){
  A[length++] = n;
  
}

int Array::Delete(int index){
  int i;
  int x = A[index];
  for(i=index; i<length-1;i++)
    A[i] = A[i+1];
  length--;
}

int Array::LinearSearch(int key){
  int i;
  for(i =0; i<length;i++){
    if(A[i] == key)
      return i;
  }
  return -1;
}

int Array::BinarySearch(int key){
  int low,mid,high;
  low = 0;
  high = length-1;
  while(low<=high){
    mid = (low+high)/2;
    cout << "mid-->" << mid << endl;
    if(A[mid] == key)
      return mid;
    else if(A[mid] > key)
      high = mid-1;
    else
      low = mid+1;
  }
  return -1;
}


int Array::RecursiveBinarySearch(int low, int high,int key){
  int mid;
  if(low<=high){
    mid = (low+high)/2;
    if(A[mid] == key)
      return mid;
    else if(A[mid] > key)
      return RecursiveBinarySearch(low,mid-1,key);
    else
      return RecursiveBinarySearch(mid+1,high,key);
  }
  return -1;
}

int Array::Get(int index){
  if(index>=0 && index<length)
    return A[index];
  return -1;
}

void Array::Set(int index, int num){
  if(index>=0 && index< length)
    A[index]=num;
}

int Array::Min(){
  
}

int Array::Max(){
  
}

int Array::Sum(){
  
}

int Array::Average(){
  
}
int main(){
  Array array;
  array.DefaltElement();
  // array.AddAppend(9);
  // array.Insert(1,1);
  // array.Display();
  // array.Delete(2);
  array.Display();
  // cout << array.LinearSearch(6);
  // cout << array.BinarySearch(6);
  // cout << array.RecursiveBinarySearch(0,4,6);
  // cout << array.Get(1);
  array.Set(2,7);
  array.Display();
  return 0;
}