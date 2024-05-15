// Power using recursion(Exponent)
#include<bits/stdc++.h>
using namespace std;

int power(int m, int n){
    if(n==0)
        return 1;
    return power(m,n-1)*m;
}


// Reducing number of function call by below code

int powerR(int m, int n){
    if(n==0)
        return 1;
    if(n%2==0)
        return powerR(m*m,n/2);
    else
        return m*powerR(m*m, (n-1)/2);
}
int main(){
    string s = "";
    // cout << power(2,5) << endl;
    // cout << powerR(2,5);
    return 0;
}