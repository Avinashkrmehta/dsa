#include<bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  struct Node *next;
}*top=NULL;

void Push(int x){
  struct Node *t;
  t = new Node;
  if(t ==NULL)
    cout << "Stack is Full \n";
  else
    t->data = x;
    t->next = top;
    top = t;
}

int Pop(){
  struct Node *t;
  int x = -1;
  if(top == NULL)
    cout << "Stack is Empty \n";
  else
    t = top; 
    x = t->data;
    top = top->next;
    delete(t);
  return x;
}

void Display(){
  struct Node *p;
  p = top;
  while(p != NULL){
    cout << p->data << " ";
    p = p->next;
  }
  cout << "\n";
}

int main(){
  Push(5);
  Push(4);

  cout << "\n";
  Display();
  Pop();
  cout << "\n";
  Display();
  return 0;
}