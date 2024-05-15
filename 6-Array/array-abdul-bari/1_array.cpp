// Array Introduction
#include<bits/stdc++.h>
using namespace std;
int main(){

  //Declaration of Array
  int arr[5]; // o/p --> 0 0 0 0 0
  int arr1[5] = {2,4,6,8,10}; // o/p --> 2 4 6 8 10
  int arr2[5] = {2,4}; // o/p --> 2 4 0 0 0 
  int arr3[5] = {0}; // o/p --> 0 0 0 0 0 
  int arr4[] = {2,4,6,8,10}; // o/p --> 2 4 6 8 10 

  for(int i=0; i<5; i++){
    cout << arr4[i] << " "; 
  }
  cout << endl;
  // printing array data in different way
  cout << arr4[2] << endl;
  cout << 2[arr4]<< endl;
  cout << *(arr4+2) << endl;
// Leet code problem 1662. Check If Two String Arrays are Equivalent
      vector<string> word1 = {"a", "cb"};
      vector<string> word2 = {"ab", "c"};
        string res1, res2;
        for(int i=0; i<word1.size(); i++){
            res1 += word1[i];
        }
        for(int i=0; i<word2.size(); i++){
            res2 += word2[i];
        }
        cout << res1<< endl;
        cout << res2 << endl;

  return 0;
}