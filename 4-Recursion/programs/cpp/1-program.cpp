
// Recursion code
#include<bits/stdc++.h>
using namespace std;

void fun1(int n){
  if(n>0){
    cout << n << " ";
    fun1(n-1);
  }
}

void fun2(int n){
  if(n>0){
    fun2(n-1);
    cout << n << " ";
  }
}

void fun3(int n){
  if(n>0){
    cout << n << " ";
    fun3(n-1);
    cout << n << " ";
  }
}

void fun4(int n){
  if(n>0){
    fun4(n-1);
    cout << n << " ";
    fun4(n-1);
  }
}

int main(){
    cout << "fun1" << endl;
    fun1(3);
    cout << endl;
    cout << "fun2" << endl;
    fun2(3);
    cout << endl;
    cout << "fun3" << endl;
    fun3(3);
    cout << endl;
    cout << "fun4" << endl;
    fun4(3);
    cout << endl;
  return 0;
}