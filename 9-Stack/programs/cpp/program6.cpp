// Program for evaluation of postfix expression
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

int eval(char *postfix){
  int i = 0;
  int x1, x2, r;
  for(i = 0; postfix[i] != '\0'; i++){
    if(isOperand(postfix[i])){
      push(postfix[i] - '0');
    }else{
      x2 = pop();
      x1 = pop();
      switch(postfix[i]){
        case '+': r = x1 + x2; break;
        case '-': r = x1 - x2; break;
        case '*': r = x1 * x2; break;
        case '/': r = x1 / x2; break;
      }
      push(r);
    }
  }
  return top->data;
}

int main(){
  char *postfix = "234*+82/-";
  cout << "Result is " << eval(postfix) << endl;
  return 0;
}
// Output:
// Result is 2
