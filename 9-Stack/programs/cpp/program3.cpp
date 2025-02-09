// Stack implementation

#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node *next;
};

class Stack{
  private:
    Node *top;
  public:
    Stack(){
      top = NULL;
    }
    void push(int x);
    int pop();
    void Display();
    int peek(int pos);
    int stackTop();
};

void Stack::push(int x){
  Node *t = new Node;
  if(t == NULL){
    cout << "Stack is full" << endl;
  }else{
    t->data = x;
    t->next = top;
    top = t;
  }
}

int Stack::pop(){
  int x = -1;
  if(top == NULL){
    cout << "Stack is Empty" << endl;
  }else{
    Node *t = top;
    top = top->next;
    x = t->data;
    delete t;
  }
  return x;
}

void Stack::Display(){
  Node *p = top;
  while(p != NULL){
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

int Stack::peek(int pos){
  Node *p = top;
  for(int i = 0; p != NULL && i < pos-1; i++){
    p = p->next;
  }
  if(p != NULL){
    return p->data;
  }else{
    return -1;
  }
}

int Stack::stackTop(){
  if(top != NULL){
    return top->data;
  }else{
    return -1;
  }
}


int main(){
  Stack stk;
  stk.push(10);
  stk.push(20);
  stk.push(30);
  stk.push(40);
  stk.push(50);
  stk.Display();
  cout << stk.pop() << endl;
  stk.Display();
  cout << stk.peek(2) << endl;
  cout << stk.stackTop() << endl;
  return 0;
}
