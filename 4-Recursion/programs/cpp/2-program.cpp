// Static and Global variables in recursion

#include<bits/stdc++.h>
using namespace std;

int fun1(int n){
  if(n>0){
    return fun1(n-1) + n;
  }
  return 0;
} 

int fun2(int n){
static int x = 0;
  if(n>0){
    x++;
    return fun1(n-1) + x;
  }
  return 0;
} 

int main(){
    int x = 5;
    cout << fun1(x) << endl;
    cout << fun2(x) << endl;
    return 0;
}

/*
 Recursive tree
    fun1(5)
    |
    |--> fun1(4) + n
        |
        |--> fun1(3) + n 
            |
            |--> fun1(2) + n
                |
                |--> fun1(1) + n
                    |
                    |--> fun1(0) + n
                          |
                          |--> 0 + 0 = 0

*/