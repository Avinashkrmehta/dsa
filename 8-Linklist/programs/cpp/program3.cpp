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
  cout << endl;
}

int count(struct Node *p){
  int l = 0;
  while(p){
    l++;
    p = p->next;
  }
  return l;
}

void insert(struct Node *p, int index, int x){
  struct Node *t;
  if(index < 0 || index > count(p)){
    return;
  }
  t = new Node;
  t->data = x;
  if(index == 0){
    t->next = first;
    first = t;
  }else{
    for (int i = 0; i < index-1; i++)
    {
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}

void insertLast(struct Node *p, int x){
  struct Node *t, *last;
  t = new Node;
  t->data = x;
  t->next = NULL;
  if(first == NULL){
    first = last = t;
  }else{
    last->next = t;
    last = t;
  }
}

void insertInSorted(struct Node *p, int x){
  struct Node *t, *q = NULL;
  p = first;
  t = new Node;
  t->data = x;
  t->next = NULL;

  if (first == NULL)
  {
    first = t;
  }
  else{
    while(p && p->data < x){
      q = p;
      p = p->next;
    }
    if(p == first){
      t->next = first;
      first = t;
    }
    else{
    t->next = q->next;
    q->next = t;
    }
  }
}


int main(){
  int A[] = {3,5,7,9};
  create(A,4);
  Display(first);
  insertInSorted(first,2);
  Display(first);




  // create(A,5);
  // Display(first);
  // cout << endl;
  // insert(first, 0, 11);
  // Display(first); //{11,3,5,7,10,15}
  // insert(first, 3, 12);
  // cout << endl;
  // Display(first); //{11,3,5,12,7,10,15}

  // insertLast(first, 20);
  // Display(first); //{20}
  // insertLast(first, 30);
  // Display(first); //{20,30}
  // insertLast(first, 40);
  // Display(first); //{20,30,40}
  // insertLast(first, 50);
  // Display(first); //{20,30,40}
  return 0;
}