// Static and Global variables in recursion

#include<bits/stdc++.h>
using namespace std;

void fun(int n){

  if(n > 0){
    cout << n << " ";
    fun(n-1);
    fun(n-1);
  }
} 

int main(){
    cout << "main" << endl;
    fun(5);
    return 0;
}

/*

main
 └── fun(5)
    5──├── fun(4)
       │  4──├── fun(3)
       │     │  3──├── fun(2)
       │     │     │  2──├── fun(1)
       │     │     │     │  1──├── fun(0)
       │     │     │     │     └── fun(0)
       │     │     │  2──└── fun(1)
       │     │     │        1──├── fun(0)
       │     │     │           └── fun(0)
       │     │     └── fun(2)
       │     │        1──├── fun(1)
       │     │           │     ├── fun(0)
       │     │           │     └── fun(0)
       │     │        1──└── fun(1)
       │     │                 ├── fun(0)
       │     │                 └── fun(0)
       │     └── fun(3)
       │        3──├── fun(2)
       │           │  2──├── fun(1)
       │           │     │  1──├── fun(0)
       │           │     │     └── fun(0)
       │           │     └── fun(1)
       │           │        1──├── fun(0)
       │           │           └── fun(0)
       │           └── fun(2)
       │                 ├── fun(1)
       │                 │     ├── fun(0)
       │                 │     └── fun(0)
       │                 └── fun(1)
       │                       ├── fun(0)
       │                       └── fun(0)
       └── fun(4)
             ├── fun(3)
             │     ├── fun(2)
             │     │     ├── fun(1)
             │     │     │     ├── fun(0)
             │     │     │     └── fun(0)
             │     │     └── fun(1)
             │     │           ├── fun(0)
             │     │           └── fun(0)
             │     └── fun(2)
             │           ├── fun(1)
             │           │     ├── fun(0)
             │           │     └── fun(0)
             │           └── fun(1)
             │                 ├── fun(0)
             │                 └── fun(0)
             └── fun(3)
                   ├── fun(2)
                   │     ├── fun(1)
                   │     │     ├── fun(0)
                   │     │     └── fun(0)
                   │     └── fun(1)
                   │           ├── fun(0)
                   │           └── fun(0)
                   └── fun(2)
                         ├── fun(1)
                         │     ├── fun(0)
                         │     └── fun(0)
                         └── fun(1)
                               ├── fun(0)
                               └── fun(0)


*/