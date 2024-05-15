// Fibonacci series using loop and recursion
#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n <= 1)
        return n;
    int t0=0, t1=1, sum=0;
    for(int i=2; i<=n; i++){
        sum = t0+t1;
        t0 = t1;
        t1 = sum;
    }
    return sum;
}

int rfib(int n)
{
    if(n<=1)return n;
    return rfib(n-2)+rfib(n-1);
}
int f[10];
int fibRec(int n){
    if(n<=1){
        f[n] = n;
        return n;
    }
    else{
        if(f[n-2] == -1)
            f[n-2] = fibRec(n-2);
        if(f[n-1] == -1)
            f[n-1] = fibRec(n-1);
        f[n] = f[n-2] + f[n-1];
        return f[n-2] + f[n-1];
    }
}

int F[10];
int mfib(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
            F[n-2]=mfib(n-2);
        if(F[n-1]==-1)F[n-1]=mfib(n-1);
            F[n]=F[n-2]+F[n-1];
        return F[n-2]+F[n-1];
    }
}

int main(){
    int f[10];
    cout << fib(5) << endl;
    cout << rfib(5) << endl;
    cout << mfib(5) << endl;
    cout << fibRec(5);
    return 0;
}