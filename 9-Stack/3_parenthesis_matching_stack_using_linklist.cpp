#include<bits/stdc++.h>
using namespace std;
struct Node{
  char data;
  struct Node *next;
}*top=NULL;

void Push(char x){
  struct Node *t;
  t = new Node;
  if(t ==NULL)
    cout << "Stack is Full \n";
  else
    t->data = x;
    t->next = top;
    top = t;
}

char Pop(){
  struct Node *t;
  char x = -1;
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

int isBalanced(char *exp){
  int i;
  for(i=0; exp[i] !='\0'; i++){
    if(exp[i] =='(')
      Push(exp[i]);
    else if(exp[i] == ')'){
      if(top==NULL)
        return 0;
      Pop();
    }
  }
  return (top==NULL) ? 1 : 0;
}
int main(){

  char *exp = "((a+b)*(c-d))))";
  cout << isBalanced(exp);
  return 0;
}