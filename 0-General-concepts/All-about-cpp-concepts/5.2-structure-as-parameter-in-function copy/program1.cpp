#include<bits/stdc++.h>
using namespace std;

struct Rectangle {
  int length;
  int breadth;
};

// call by value
int area(struct Rectangle r) {
  int area =  r.length * r.breadth;
  r.length++;
  r.breadth++;
  cout << "Indide function" << endl;
  cout << r.length << " " << r.breadth << endl;
  return area;
}

// call by reference
int area1(struct Rectangle &r) {
  int area =  r.length * r.breadth;
  r.length++;
  r.breadth++;
  cout << "Indide function" << endl;
  cout << r.length << " " << r.breadth << endl;
  return area;
}

// call by address
int area2(struct Rectangle *r) {
  int area =  r->length * r->breadth;
  r->length++;
  r->breadth++;
  cout << "Indide function" << endl;
  cout << r->length << " " << r->breadth << endl;
  return area;
}

int main() {
  struct Rectangle r = {10, 6};
  cout << "Before passing struct to function" << endl;
  cout << r.length << " " << r.breadth << endl;
  // cout << area(r) << endl;
  // cout << area1(r) << endl;
  cout << area2(&r) << endl;
  cout << "Before passing struct to function" << endl;
  cout << r.length << " " << r.breadth << endl;
  return 0;
}