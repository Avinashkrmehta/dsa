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

int count(struct Node *p){
  int l = 0;
  while(p){
    l++;
    p = p->next;
  }
  return l;
}

int Recursivecount(struct Node *p){
  if(p!=NULL){
    return Recursivecount(p->next) + 1;
  }else{
    return 0;
  }
}

int Sum(struct Node *p){
  int sum = 0;
  while(p){
    sum += p->data;
    p = p->next;
  }
  return sum;
}

int RecursiveSum(struct Node *p){
  if(p!=NULL){
    return RecursiveSum(p->next) + p->data;
  }else{
    return 0;
  }
}

int RecusiveSum2(struct Node *p){
  if(p==0){
    return 0;
  }else{
    return RecusiveSum2(p->next) + p->data;
  }
}

int Max(struct Node *p){
  int max = INT_MIN;
  while(p){
    if(p->data > max){
      max = p->data;
    }
    p = p->next;
  }
  return max;
}

int RecursiveMax(struct Node *p){
  int x = 0;
  if(p==0){
    return INT_MIN;
  }
  x = RecursiveMax(p->next);
  return x > p->data ? x : p->data;
}

struct Node *searchlinklist(struct Node *p, int key){
  while(p){
    if(key == p->data){
      return p;
    }
    p = p->next;
  }
  return NULL;
}

struct Node *searchlinklistOptimized(struct Node *p, int key){
  struct Node *temp;
  while(p){
    if(key == p->data){
      temp->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    temp=p;
    p = p->next;
  }
  return NULL;
}

struct Node *Recursivesearchlinklist(struct Node *p, int key){
  if(p==0){
    return NULL;
  }
  if(key == p->data){
    return p;
  }
  return Recursivesearchlinklist(p->next, key);
}

int main(){
  int A[] = {3,5,7,10,15};
  create(A,5);
  Display(first);
  cout << endl;
  struct Node *temp;
  temp = searchlinklistOptimized(first, 5);
  if(temp){
    cout << "Key is found " << temp->data << endl;
  }else{
    cout << "Key is not found" << endl;
  }
  cout << endl;
  Display(first);
  return 0;
}