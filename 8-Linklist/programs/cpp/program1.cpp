// Link List

#include<bits/stdc++.h>
using namespace std;


struct Node{
  int data;
  struct Node *next;
}*first=NULL;


void create(int A[], int n){
  int i;
  struct Node *t, *last;
  first = new Node;
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++)
  {
    t = new Node;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
  
}

void Display(struct Node *p){
  while(p!=NULL){
    cout<< p->data << " ";
    p = p->next;
  }
}

void recursiveDisplay(struct Node *p){
  if(p!=NULL){
    cout<< p->data << " ";
    recursiveDisplay(p->next);
  }
}

void recursiveDisplay1(struct Node *p){
  if(p!=NULL){
    recursiveDisplay1(p->next);
    cout<< p->data << " ";
  }
}

int 

int main(){
  int A[] = {3,5,7,10,15};
  create(A,5);
  Display(first);
  cout << endl;
  recursiveDisplay(first);
  cout << endl;
  recursiveDisplay1(first);
  return 0;
}