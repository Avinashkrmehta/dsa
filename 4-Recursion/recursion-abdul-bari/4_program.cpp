// Factorial of a number
#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==0)
        return 1;
    else
    return fact(n-1)*n;
}

int iFact(int n){
    int i,s=1;
    if(n ==0){
        return 1;
    }
    for(i=1; i<=n; i++)
        s*=i;
    return s;
}

int main(){
    int x = 5;
    cout << fact(x) << endl;
    cout << iFact(x) << endl;
    return 0;
}