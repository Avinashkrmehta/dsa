// Taylor Series e^x
#include<bits/stdc++.h>
using namespace std;

int expon(int x, int n){
    static double p =1, f=1;
    double r;
    if(n==0){
        return 1;
    }else{
        r = expon(x,n-1);
        p= p*x;
        f=f*n;
        return r+p/f;
    }
}

int main(){
    cout << expon(2,15);
    return 0;
}