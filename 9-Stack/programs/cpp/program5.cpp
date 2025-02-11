// Program to convert  Infix to postfix Conversion
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

int pre(char x){
  if(x == '+' || x == '-'){
    return 1;
  }else if(x == '*' || x == '/'){
    return 2;
  }
  return 0;
}

int isOperand(char x){
  if(x == '+' || x == '-' || x == '*' || x == '/'){
    return 0;
  }else{
    return 1;
  }
}


string InToPost(string infix){
  string postfix = "";
  int i = 0;
  while(i < infix.length()){
    if(isOperand(infix[i])){
      postfix += infix[i];
      i++;
    }else{
      if(pre(infix[i]) > pre(top->data)){
        push(infix[i++]);
      }else{
        postfix += pop();
      }
    }
  }
  while(top != NULL){
    postfix += pop();
  }
  return postfix;
}

int main(){
  string infix = "a+b*c-d/e";
  push('#');
  cout << InToPost(infix) << endl;
  return 0;
}

// Output
// abc*+de/-#