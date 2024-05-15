// Combinations using nCr
#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==0) return 1;
    return fact(n-1)*n;
}
int nCr(int n, int r){
    int num,den;
    num = fact(n);
    den = fact(r)*fact(n-r);
    return num/den;
}

int nCrRec(int n, int r){
    if(r==0 || n==r){
        return 1;
    }else{
        return nCrRec(n-1,r-1)+nCrRec(n-1,r);
    }
}

int main(){
    cout << nCr(5,2)<< endl;
    cout << nCrRec(5,2) << endl;
    return 0;
}