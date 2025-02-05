// Doubly Link List

#include<bits/stdc++.h>
using namespace std;

struct Node{
  Node *prev;
  int data;
  Node *next;
}*first = NULL;

void create(int A[], int n){
  Node *t, *last;
  first = new Node;
  first->data = A[0];
  first->prev = first->next = NULL;
  last = first;

  for (int i = 1; i < n; i++)
  {
    t = new Node;
    t->data = A[i];
    t->next = last->next;
    t->prev = last;
    last->next = t;
    last = t;
  }
}

void Display(Node *p){
  while(p){
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

int Length(Node *p){
  int len = 0;
  while(p){
    len++;
    p = p->next;
  }
  return len;
}

void Insert(Node *p, int index, int x){
  Node *t;
  if(index < 0 || index > Length(p)) return;
  if(index == 0){
    t = new Node;
    t->data = x;
    t->prev = NULL;
    t->next = first;
    first->prev = t;
    first = t;
  }else{
    for (int i = 0; i < index-1; i++)
    {
      p = p->next;
    }
    t = new Node;
    t->data = x;
    t->prev = p;
    t->next = p->next;
    if(p->next) p->next->prev = t;
    p->next = t;
  }
}

void Delete(Node *p, int index){
  Node *q;
  if(index < 1 || index > Length(p)) return;
  if(index == 1){
    first = first->next;
    if(first) first->prev = NULL;
    delete p;
  }else{
    for (int i = 0; i < index-1; i++)
    {
      p = p->next;
    }
    p->prev->next = p->next;
    if(p->next) p->next->prev = p->prev;
    delete p;
  }
}

void Reverse(Node *p){
  Node *temp;
  while(p){
    temp = p->next;
    p->next = p->prev;
    p->prev = temp;
    p = p->prev;
    if(p != NULL && p->next == NULL) first = p;
  }
}

int main(){
  int A[] = {10, 20, 30, 40, 50};
  create(A, 5);
  Display(first);
  Reverse(first);
  Display(first);
  Insert(first, 0, 5);
  Display(first);
  Delete(first, 1);
  Display(first);
  Delete(first, 3);
  Display(first);
  Delete(first, 4);
  Display(first);
  return 0;
}