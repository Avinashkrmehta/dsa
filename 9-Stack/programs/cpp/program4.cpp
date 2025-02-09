// Stack implementation

#include<bits/stdc++.h>
using namespace std;

struct Node{
  char data;
  struct Node *next;
}*top = NULL;

void push(char x){
  struct Node *t;
  t = new Node;
  if(t == NULL){
    cout << "Stack is full" << endl;
  }else{
    t->data = x;
    t->next = top;
    top = t;
  }
}

char pop(){
  char x = -1;
  if(top == NULL){
    cout << "Stack is Empty" << endl;
  }else{
    struct Node *t = top;
    top = top->next;
    x = t->data;
    delete t;
  }
  return x;
}

void Display(){
  struct Node *p = top;
  while(p != NULL){
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

int peek(int pos){
  struct Node *p = top;
  for(int i = 0; p != NULL && i < pos-1; i++){
    p = p->next;
  }
  if(p != NULL){
    return p->data;
  }else{
    return -1;
  }
}


int stackTop(){
  if(top != NULL){
    return top->data;
  }else{
    return -1;
  }
}

int isEmpty(){
  return top ? 0 : 1;
}

int isFull(){
  struct Node *t = new Node;
  int r = t ? 0 : 1;
  delete t;
  return r;
}

int isBalanced(char *exp){
  for(int i = 0; exp[i] != '\0'; i++){
    if(exp[i] == '('){
      push(exp[i]);
    }else if(exp[i] == ')'){
      if(top == NULL){
        return 0;
      }
      pop();
    }
  }
  return top == NULL ? 1 : 0;
}


int main(){
 char *exp = "((a+b)*(c-d))))";
 cout << isBalanced(exp) << endl;
  return 0;
}



