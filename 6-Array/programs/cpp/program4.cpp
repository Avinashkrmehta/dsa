// 2D Array in C++ using new operator
#include<bits/stdc++.h>
using namespace std;


int main(){

    int A[3][4] = {{1,2,3,4}, {2,4,6,8}, {1,3,5,7}}; // 3x4 array in stack

    int *B[3]; // 3x4 array in heap
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    int **C; // 3x4 array in heap
    C = new int*[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}