// Implementation of Queue using linked list

#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node *next;
}*front=NULL, *rear=NULL;

void enqueue(int x){
  struct Node *t;
  t = new Node;
  if(t == NULL){
    cout << "Queue is full" << endl;
  }else{
    t->data = x;
    t->next = NULL;
    if(front == NULL){
      front = rear = t;
    }else{
      rear->next = t;
      rear = t;
    }
  }
}

int dequeue(){
  int x = -1;
  struct Node *t;
  if(front == NULL){
    cout << "Queue is empty" << endl;
  }else{
    x = front->data;
    t = front;
    front = front->next;
    delete t;
  }
  return x;
}

void Display(){
  struct Node *p = front;
  while(p){
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}


int main(){
  enqueue(10);
  enqueue(20);
  enqueue(30);
  Display();
  cout << dequeue() << endl;
  Display();
  return 0;
}

// Output
// 10 20 30
// 10 20
// Compare this snippet from 10-Queue/programs/cpp/program3.cpp: