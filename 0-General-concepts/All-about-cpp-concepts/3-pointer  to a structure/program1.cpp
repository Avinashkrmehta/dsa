#include<bits/stdc++.h>
using namespace std;

struct Rectangle
{
  int length;
  int breadth;
};


int main() {
  struct Rectangle r = {10, 5};
  struct Rectangle *p = &r;

  (*p).length = 15;
  p->breadth = 7;

  cout << r.length << endl;
  cout << r.breadth << endl;

  cout << p->length << endl;
  cout << p->breadth << endl;

  cout << (*p).length << endl;
  cout << (*p).breadth << endl;


  // # dynamically allocating memory for a structure

  struct Rectangle *ptr;
  ptr = new Rectangle;
  ptr->length = 20;
  ptr->breadth = 10;

  cout << ptr->length << endl;
  cout << ptr->breadth << endl;

  
  return 0;
}