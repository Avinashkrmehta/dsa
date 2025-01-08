// Taylor series using Honer's rule

#include<bits/stdc++.h>
using namespace std;

// Using recursion 
double taylorSeries(int x, int n){
  static double s;
  if(n == 0){
    return s;
  }
  s = 1 + x*s/n;
  return taylorSeries(x, n-1);
}

// Using loop
double taylorSeriesLoop(int x, int n){
  double s = 1;
  for(; n > 0; n--){
    s = 1 + x*s/n;
  }
  return s;
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



