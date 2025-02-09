// Menu Driven Program in an Array

#include<bits/stdc++.h>
using namespace std;

struct Array{
  int *A;
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
      swap(&arr->A[i], &arr->A[i-1]);
      return i;
    }
  }
  return -1;
}

int BinarySearch(struct Array arr, int key){
  int l = 0;
  int h = arr.length - 1;
  int mid;
  while(l <= h){
    mid = (l+h)/2;
    if(key == arr.A[mid]){
      return mid;
    }
    else if(key < arr.A[mid]){
      h = mid - 1;
    }
    else{
      l = mid + 1;
    }
  }
  return -1;
}

int BinarySearchRecursive(struct Array arr, int l, int h, int key){
  int mid;
  if(l <= h){
    mid = (l+h)/2;
    if(key == arr.A[mid]){
      return mid;
    }
    else if(key < arr.A[mid]){
      return BinarySearchRecursive(arr, l, mid-1, key);
    }
    else{
      return BinarySearchRecursive(arr, mid+1, h, key);
    }
  }
  return -1;
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
  struct Array arr1;
  int ch;
  cout << "Enter size of an array: ";
  cin >> arr1.size;
  cout << arr1.size;
  cout<< endl;
  arr1.A = new int[arr1.size];
  cout << "Menu\n";
  cout << "1. Display Array\n";
  cout << "2. Append\n";
  cout << "3. Insert\n";
  cout << "4. Delete\n";
  cout << "5. Linear Search\n";
  cout << "6. LinearSearchOptimize\n";
  cout << "7. Binary Search\n";
  cout << "8. Binary Search Recursive\n";
  cout << "9. Get\n";
  cout << "10. Set\n";
  cout << "11. Max\n";
  cout << "12. Min\n";
  cout << "13. Sum\n";
  cout << "14. Avg\n";
  cout << "15. Reverse\n";
  cout << "16. Reverse2\n";
  cout << "17. LeftShift\n";
  cout << "18. RightShift\n";
  cout << "19. Rotate\n";
  cout << "20. InsertSorted\n";
  cout << "21. isSorted\n";
  cout << "22. Rearrange\n";
  cout << "23. MergeArrays\n";
  cout << "24. UnionArray\n";
  cout << "25. IntersectionArray\n";
  cout << "26. DifferenceArray\n";
  cout << "27. Exit\n";
  cout << "Enter your choice: ";
  cin >> ch;
  cout << ch;
  cout << endl;


    switch(ch){
      case 1:
        Display(arr1);
        break;
      case 2:
        int x;
        cout << "Enter an element to append: ";
        cin >> x;
        Append(&arr1, x);
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
        Insert(&arr1, index, x);
        Display(arr1);
        break;
      case 4:
        cout << "Enter an index to delete: ";
        cin >> index;
        cout << Delete(&arr1, index);
        break;
      case 5:
        cout << "Enter an element to search: ";
        cin >> x;
        cout << LinearSearch(arr1, x);
        break;
      case 6:
        cout << "Enter an element to search: ";
        cin >> x;
        cout << LinearSearchOptimize(&arr1, x);
        break;
      case 7:
        cout << "Enter an element to search: ";
        cin >> x;
        cout << BinarySearch(arr1, x);
        break;
      case 8:
        cout << "Enter an element to search: ";
        cin >> x;
        cout << BinarySearchRecursive(arr1, 0, arr1.length, x);
        break;
      case 9:
        cout << "Enter an index to get: ";
        cin >> index;
        cout << Get(arr1, index);
        break;
      case 10:
        cout << "Enter an index to set: ";
        cin >> index;
        cout << "Enter an element to set: ";
        cin >> x;
        cout << Set(&arr1, index, x);
        break;
      case 11:
        cout << Max(arr1);
        break;
      case 12:
        cout << Min(arr1);
        break;
      case 13:
        cout << Sum(arr1);
        break;
      case 14:
        cout << Avg(arr1);
        break;
      case 15:
        Reverse(&arr1);
        break;
      case 16:
        Reverse2(&arr1);
        break;
      case 17:
        LeftShift(&arr1);
        break;
      case 18:
        RightShift(&arr1);
        break;
      case 19:
        rotate(&arr1);
        break;
      case 20:
        cout << "Enter an element to insert: ";
        cin >> x;
        InsertSorted(&arr1, x);
        break;
      case 21:
        cout << isSorted(arr1);
        break;
      case 22:
        Rearrange(&arr1);
        break;
      case 23:
        break;
    }
    cout << "Enter your choice: ";
    cin >> ch;

  return 0;
}