// Link List

#include<bits/stdc++.h>
using namespace std;


struct Node{
  int data;
  struct Node *next;
}*first=NULL, *second=NULL, *third=NULL;


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

void create2(int A[], int n){
  int i;
  struct Node *t, *last;
  second = new Node;
  second->data = A[0];
  second->next = NULL;
  last = second;

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

int deleteElement(struct Node *p, int index){
  struct Node *q;
  int x =1;
  if(index < 1 || index > count(p)){
    return -1;
  }
  if(index == 1){
    q = first;
    x = first->data;
    first = first->next;
    delete q;
    return x;
  }
  else{
    for(int i=0; i< index-1;i++){
      q=p;
      p=p->next;
    }
    q->next = p->next;
    x = p->data;
    delete p;
    return x;
  }
}

bool isSorted(struct Node *q){
  int x=-65536;
  while(q !=NULL){
    if(q->data < x){
      return 0;
    }
      x = q->data;
      q = q->next;
  }
 return true;
}


void  removingDuplicates(struct Node *p){
  struct Node *q = p->next;
  while(q!=NULL){
    if(p->data != q->data){
      p = q;
      q = q->next;
    }else{
      p->next = q->next;
      delete q;
      q = p->next;
    }
  }
}


void reverse1(struct Node *p){
  struct Node *q = NULL, *r = NULL;
  while(p!=NULL){
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  first = q;
}

void reverse2(struct Node *q, struct Node *p){
  if(p){
    reverse2(p, p->next);
    p->next = q;
  }else{
    first = q;
  }
}

void reverse3(struct Node *p){
  int *A, i = 0;
  struct Node *q = p;
  A = new int[count(p)];
  while(q!=NULL){
    A[i] = q->data;
    q = q->next;
    i++;
  }
  q = p;
  i--;
  while(q!=NULL){
    q->data = A[i];
    q = q->next;
    i--;
  }

}

void concat(struct Node *p, struct Node *q){
  third = p;
  while(p->next != NULL){
    p = p->next;
  }
  p->next = q;
}

void merge(struct Node *p, struct Node *q){
  struct Node *last;
  if(p->data < q->data){
    third = last = p;
    p = p->next;
    third->next = NULL;
  }else{
    third = last = q;
    q = q->next;
    third->next = NULL;
  }
  while(p && q){
    if(p->data < q->data){
      last->next = p;
      last = p;
      p = p->next;
      last->next = NULL;
    }else{
      last->next = q;
      last = q;
      q = q->next;
      last->next = NULL;
    }
  }
  if(p) last->next = p;
  if(q) last->next = q;
} 

bool isLoop(struct Node *f){
  struct Node *p, *q;
  p = q = f;
  do{
    p = p->next;
    q = q->next;
    q = q?q->next:q;
  }while(p && q && p!=q);
  if(p == q){
    return true;
  }else{
    return false;
  }
}

int main(){

  int A[] = {10,20,30,40,50};
  create(A,5);
  struct Node *t1, *t2;
  t1 = first->next->next;
  t2 = first->next->next->next->next;
  t2->next = t1;
  cout << isLoop(first);
  


  // int A[] = {10,20,30,40,50};
  // int B[] = {5,15,25,35,45};
  // create(A,5);
  // create2(B,5);
  // Display(first);
  // Display(second);

  // concat(first, second);
  // Display(third);
  // Display(first);


  // int A[] = {10,20,30,40,50};
  // create(A,5);
  // reverse3(first);
  // Display(first);

  // int A[] = {10,20,20,40,50};
  // create(A,5);
  // removingDuplicates(first);
  // Display(first);

  // int A[] = {10,20,30,40,50};
  // create(A,5);
  // cout << isSorted(first);
  // cout << endl;
  // Display(first);


  // deleteElement(first, 3);
  // deleteElement(first, 1);
  // Display(first);







  // int A[] = {3,5,7,9};
  // create(A,4);
  // Display(first);
  // insertInSorted(first,2);
  // Display(first);




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