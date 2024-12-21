#include<bits/stdc++.h>
using namespace std;

void passByValue(int x) {
  x += 10;
}

void passByReference(int &x) {
 x += 10;
}

void passByAddress(int *x) {
  *x += 10;
}

int main() {
  int a  = 10;
  int b = 10;
  int c = 10;

  cout << "Before passing to function" << endl;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;

  passByValue(a);
  passByReference(b);
  passByAddress(&c);
  

  cout << "After passing to function" << endl;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;

  return 0;
}