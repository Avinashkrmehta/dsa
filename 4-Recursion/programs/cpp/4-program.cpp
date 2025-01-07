// Indirect recursion

#include<bits/stdc++.h>
using namespace std;
void funB(int n);

void funA(int n){
  if(n > 0){
    cout << n << " ";
    funB(n-1);
  }
} 

void funB(int n){
  if(n > 0){
    cout << n << " ";
    funA(n/2);
  }
}

int main(){
    cout << "main" << endl;
    funA(20);
    return 0;
}



/*
Tree Diagram:
funA(20)
|
|-- funB(19)
|   |
|   |-- funA(9)
|       |
|       |-- funB(8)
|           |
|           |-- funA(4)
|               |
|               |-- funB(3)
|                   |
|                   |-- funA(1)
|                       |
|                       |-- funB(0)
|
|-- funB(0)
*/
