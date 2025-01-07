// Nested recursion

#include<bits/stdc++.h>
using namespace std;

int fun(int n){
  if(n > 100){
    cout << n-10 << " ";
    return n-10;
  }
  else
    return fun(fun(n+11));
} 

int main(){
    cout << "main" << endl;
    cout << fun(95);
    return 0;
}

/*
Tree Diagram:
fun(95)
|
|-- fun(fun(106))
|   |
|   |-- fun(96)
|       |
|       |-- fun(fun(107))
|           |
|           |-- fun(97)
|               |
|               |-- fun(fun(108))
|                   |
|                   |-- fun(98)
|                       |
|                       |-- fun(fun(109))
|                           |
|                           |-- fun(99)
|                               |
|                               |-- fun(fun(110))
|                                   |
|                                   |-- fun(100)
|                                       |
|                                       |-- fun(fun(111))
|                                           |
|                                           |-- fun(101)
|                                               |
|                                               |-- fun(91)
|
|-- fun(91)
*/

