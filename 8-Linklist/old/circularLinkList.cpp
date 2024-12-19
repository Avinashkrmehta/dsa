// Array Introduction
#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node *next;
};

class CircularLinkList{
  private: 
    Node *head;
  public:
    CircularLinkList(){head=NULL;}
    CircularLinkList(int A[], int n);
    ~CircularLinkList();

    void Display();
    void Insert(int index,int x);
    int Delete(int index);
    int Length();
};

CircularLinkList::CircularLinkList(int A[], int n){
  int i;
  Node *t, *last;
  head = new Node;
  head->data = A[0];
  head->next = head;
  last = head;
  for(i=1; i<n;i++){
    t = new Node;
    t->data = A[i];
    t->next = last->next;
    last->next = t;
    last = t;
  }
}

CircularLinkList::~CircularLinkList(){
  Node *p = head;
  while(head){
    head = head->next;
    delete p;
    p = head;
  }
}

int main(){
    
  return 0;
}