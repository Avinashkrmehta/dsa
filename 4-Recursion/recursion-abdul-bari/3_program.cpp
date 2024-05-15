// Sum of n natural number
#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n==0)
        return 0;
    else
    return sum(n-1) + n;
}

int iSum(int n){
    int i,s=0;
    for(i=0; i<=n; i++)
        s+=i;
    return s;
}

int formulaSum(int n){
    return n*(n+1)/2;
}

int main(){
    int x = 5;
    cout << sum(x) << endl;
    cout << iSum(x) << endl;
      cout << formulaSum(x) << endl;
    return 0;
}