// Taylor series using recursion

#include<bits/stdc++.h>
using namespace std;

// Using recursion
double taylorSeries(int x, int n){
  static double p = 1, f = 1;
  double r;
  if(n == 0){
    return 1;
  }
  else{
    r = taylorSeries(x, n-1);
    p = p*x;
    f = f*n;
    return r + p/f;
  }
}

// Using loop
double taylorSeriesLoop(int x, int n){
  double r = 1;
  double p = 1;
  double f = 1;
  for(int i = 1; i <= n; i++){
    p *= x;
    f *= i;
    r += p/f;
  }
  return r;
}

int main(){
    cout << taylorSeries(1,10);
    cout << endl;
    cout << taylorSeriesLoop(1,10);
    return 0;
}

/*
Tree Diagram:
taylorSeries(1, 10)
|
|-- taylorSeries(1, 9)
|   |
|   |-- taylorSeries(1, 8)
|       |
|       |-- taylorSeries(1, 7)
|           |
|           |-- taylorSeries(1, 6)
|               |
|               |-- taylorSeries(1, 5)
|                   |
|                   |-- taylorSeries(1, 4)
|                       |
|                       |-- taylorSeries(1, 3)
|                           |
|                           |-- taylorSeries(1, 2)
|                               |
|                               |-- taylorSeries(1, 1)
|                                   |
|                                   |-- taylorSeries(1, 0)
*/


