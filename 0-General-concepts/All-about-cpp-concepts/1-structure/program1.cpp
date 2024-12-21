#include<bits/stdc++.h>
using namespace std;

struct Rectangle {
  int length;
  int breadth;
};
int main() {
  struct Rectangle r1;
  struct Rectangle r = {10, 5};

  cout << r.length << endl;
  cout << r.breadth << endl;
  cout << r1.length << endl;
  return 0;
}