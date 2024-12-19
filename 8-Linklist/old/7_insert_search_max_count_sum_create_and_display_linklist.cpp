#include<bits/stdc++.h>
using namespace std;

struct Node{
 int data;
 struct Node *next;
}*head=NULL,*second=NULL,*third=NULL;

void Create(int A[],int n){
  int i;
  struct Node *temp, *last;
  head = new Node;
  head->data = A[0];
  head->next = NULL;
  last = head;

  for(i=1; i<n; i++){
    temp = new Node;
    temp->data = A[i];
    temp->next = NULL;
    last->next = temp;
    last = temp;
  }

}

void Create1(int A[],int n){
  int i;
  struct Node *temp, *last;
  second = new Node;
  second->data = A[0];
  second->next = NULL;
  last = second;

  for(i=1; i<n; i++){
    temp = new Node;
    temp->data = A[i];
    temp->next = NULL;
    last->next = temp;
    last = temp;
  }

}

void Display(struct Node *node){
  while(node!= NULL){
    cout << node->data << " ";
    node = node->next;
  }
}

int Count(struct Node *node){
   int l=0;
   while(node){
    l++;
    node =node->next;
   }
   return l;
}

int Sum(struct Node *node){
  int sum=0;
  while(node){
    sum = sum+node->data;
    node = node->next;
  }
  return sum;
}
int Max(struct Node * node){
  int max = INT_MIN;
  while(node){
    if(node->data > max)
      max = node->data;
    node = node->next;
  }
  return max;
}

struct Node * LSearch(struct Node *node, int key){
  while(node != NULL){
    if(key == node->data){
      return node;
    }
    node = node->next;
  }
  return NULL;

}

struct Node * OptimizeLSearch(struct Node *node, int key){
  struct Node *temp;
  while(node != NULL){
    if(key == node->data){
      temp->next = node->next;
      node->next = head;
      head = node;
      return node;
    }
    temp = node;
    node = node->next;
  }
  return NULL;

}

void Insert(struct Node *p, int pos, int val){
  struct Node *t;
  int i;
  if(pos < 0 || pos > Count(p))
    return;
  t = new Node;
  t->data = val;

  if(pos == 0){
    t->next = head;
    head = t;
  }else{
    for(i=0; i<pos-1;i++)
      p = p->next;
    t->next = p->next;
    p->next = t;
    
  }
}

void Insertlast(struct Node *node, int val){
  struct Node *t, *first, *last;
  t = new Node;
  t->data = val;
  t->next = NULL;
  if(head == NULL){
    first = last = t;
  }else{
    last->next = t;
    last = t;
  }
}


void SortedInsert(struct Node *node, int val){
  struct Node *temp, *q=NULL;
  temp = new Node;
  temp->data = val;
  temp->next = NULL;
  if(head == NULL){
    head = temp;
  }
  else{
    while(node && node->data < val){
      q = node;
      node = node->next;
    }
    if(node == head){
      temp->next = head;
      head = temp;
    }else{
      temp->next = q->next;
      q->next = temp;
    }
  }
}

int Delete(struct Node *node,int pos){
  struct Node *q=NULL;
  int x=-1, i;
  if(pos < 1 || pos > Count(node)){
    return -1;
  }
  if(pos == 1){
    q = head;
    x = head->data;
    head = head->next;
    delete q;
    return x;
  }
  else{
    for(i=0; i<pos-1;i++){
      q = node;
      node = node->next;
    }
    q->next = node->next;
    x = node->data;
    delete node;
    return x;
  }
}

int IsSorted(struct Node *node){
  int x = INT_MIN;
  while(node != NULL){
    if(node->data < x)
      return 0;
    x = node->data;
    node = node->next;
  }
  return 1;
}

void RemoveDuplicate(struct Node *node){
  struct Node *q = node->next;
  while(q != NULL){
    if(node->data != q->data){
      node = q;
      q = q->next;
    }else{
      node->next = q->next;
      delete q;
      q = node->next;
    }
  }
}

void ReverseLinkList1(struct Node *p){
  int *A, i=0;
  struct Node *q = p;
  A = new int[Count(p)];
  while(q != NULL){
    A[i] = q->data;
    q = q->next;
    i++;
  }
  q = p;
  i--;
  while(q != NULL){
    q->data = A[i];
    q = q->next;
    i--;
  }
}

void ReverseLinkList2(struct Node *p){
  struct Node *q=NULL, *r=NULL;
  while(p != NULL){
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  head = q;
}

void ReverseLinkListUsingRecursion(struct Node *q,struct Node *p){
  if(p != NULL){
    ReverseLinkListUsingRecursion(p, p->next);
    p->next = q;
  }
  else{
    head = q;
  }
}

void ConcatLinkList(struct Node *first, struct Node *sec){
  struct Node *temp;
  temp = first;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = sec;
  sec = NULL;
}


void MergeLinkList(struct Node *p, struct Node *q){
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


int IsLoop(struct Node *f){
  struct Node *p, *q;
  p=q=f;
  do{
    p = p->next;
    q = q->next;
    q = q? q->next : q;
  }while(p && q && p!=q);
  return (p ==q) ? true : false;
}
int main(){
    int A[] = {10,20,30,40,50};
    int B[] = {1,3,4,7,450};
    struct Node * temp;
    Create(A,5);
    Create1(B,5);
    cout << "First link list is \n";
    Display(head);
    struct Node *t1, *t2;

   t1 = head->next->next;
   t2 =  head->next->next->next->next;
   t2->next = t1;
    // cout << "Second link list is \n";
    // Display(second);
    // SortedInsert(head,2);
    // Delete(head,1);

    cout << endl;
    cout << IsLoop(head);
    // Display(head);
    // cout << IsSorted(head);
    // RemoveDuplicate(head);
    // ReverseLinkList2(head);
    // struct Node *t = NULL;
    // ReverseLinkListUsingRecursion(NULL,head);
    // MergeLinkList(head,second);
    // cout << endl;
    // Display(third);
  return 0;
}