// Array Introduction
#include<bits/stdc++.h>
using namespace std;

struct Array{
 int A[10];
 int size;
 int length;
};

void Display(struct Array arr){
   int i;
   for( i =0; i<arr.length;i++)
        cout << arr.A[i] << " ";
};

void DisplayArrayDetails(struct Array arr){
    cout << endl << "Below are the Array details" << endl;
    cout << "Size--->" << arr.size<< endl;
    cout << "Length--->" << arr.length<< endl;
};

int Append(struct Array *arr, int x){
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int val){
    int i;
    if(index >=0 && index <= arr->length){
        for(i = arr->length; i>index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = val;
        arr->length++;
    }
}
 int Delete(struct Array *arr, int index){
    int x=0;
    if(index>=0 && index < arr->length)
        x = arr->A[index];
        for(int i=index; i<arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
 }

int BinarySearch(struct Array arr,int key){
    int l =0, h= arr.length-1, mid;
    while(l<=h){
         mid = (l+h)/2;
        if(arr.A[mid] == key){
            return mid;
        }else if(key < arr.A[mid]){
            h = mid -1;
        }else{
            l = mid+1;
        }
    }
    return -1;

}

int main(){
    int n,i;
    struct Array arr = {{2,3,4,5,6},10,5};
    // DisplayArrayDetails(arr);
    // Display(arr);
    // Append(&arr,10);
    // Insert(&arr,0,11);
    // Display(arr);    
    // Delete(&arr,1);
    // cout << endl;
    // Display(arr);
   cout << BinarySearch(arr,6);
    // DisplayArrayDetails(arr);
    return 0;
}