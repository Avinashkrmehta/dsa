#include<bits/stdc++.h>
using namespace std;


class Rectangle {
  private:
    int length;
    int breadth;

  public:
    Rectangle();
    Rectangle(int l, int b);
    void setLength(int l);
    void setBreadth(int b);
    int getLength();
    int getBreadth();
    int area();
    int perimeter();
    ~Rectangle();
};

Rectangle::Rectangle() {
  length = 0;
  breadth = 0;
}

Rectangle::Rectangle(int l, int b) {
  setLength(l);
  setBreadth(b);
}

void Rectangle::setLength(int l) {
  if (l >= 0) {
    length = l;
  } else {
    length = 0;
  }
}

void Rectangle::setBreadth(int b) {
  if (b >= 0) {
    breadth = b;
  } else {
    breadth = 0;
  }
}

int Rectangle::getLength() {
  return length;
}

int Rectangle::getBreadth() {
  return breadth;
}

int Rectangle::area() {
  return length * breadth;
}

int Rectangle::perimeter() {
  return 2 * (length + breadth);
}

Rectangle::~Rectangle() {
  cout << "Destructor" << endl;
};
int main() {
  Rectangle r(10, 5);
  cout << r.area() << endl;
  cout << r.perimeter() << endl;
  r.setLength(20);
  r.setBreadth(10);
  cout << r.area() << endl;
  cout << r.perimeter() << endl;

  Rectangle r1;
  cout << r1.area() << endl;
  cout << r1.perimeter() << endl;
  r1.setLength(30);
  r1.setBreadth(15);
  cout << r1.area() << endl;
  cout << r1.perimeter() << endl;
  return 0;
}