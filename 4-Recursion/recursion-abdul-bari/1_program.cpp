// Tail Recursion
#include<bits/stdc++.h>
using namespace std;

void func1(int n){
    if(n >0){
        cout << n << " ";
        func1(n-1);
    }
}

int main(){
    int x = 3;
    func1(x);
    return 0;
}