// Array declaration and initialization in C++
#include<bits/stdc++.h>
using namespace std;


int main(){
    int A[5];
    int B[5] = {1,2,3,4,5};
    int C[10] = {1,2,3};
    int D[5] = {0};
    int E[] = {1,2,3,4,5};

    int i;
    for(i = 0; i < 5; i++){
        cout << &A[i] << endl;
    }
    return 0;
}