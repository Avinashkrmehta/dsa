// Array in stack and heap
#include<bits/stdc++.h>
using namespace std;


int main(){
    int A[5] = {2,4,6,8,10}; // Array of 5 integers in stack
    int *p; // Pointer to integer in stack
    p = new int[5]; // Array of 5 integers in heap
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    for(int i = 0; i < 5; i++){
        cout << A[i] << " ";
    }
    cout << endl;
    
    for(int i = 0; i < 5; i++){
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}