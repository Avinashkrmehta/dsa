#include<bits/stdc++.h>
using namespace std;

template <class T>
class Operation {
  private:
    T num1;
    T num2;

  public:
    T add();
    T sub();
    Operation(T n1, T n2);
    ~Operation();
};

template <class T>
Operation<T>::Operation(T n1, T n2) {
  this->num1 = n1;
  this->num2 = n2;
}

template <class T>
T Operation<T>::add() {
  return num1 + num2;
}

template <class T>
T Operation<T>::sub() {
  return num1 - num2;
}
template <class T>
Operation<T>::~Operation() {
  cout << "Destructor" << endl;
};
int main() {
  Operation r(10.5, 1.55);
  cout << r.add() << endl;
  cout << r.sub() << endl;
  return 0;
}