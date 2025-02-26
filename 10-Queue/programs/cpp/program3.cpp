// Implementation of circular queue using array

#include<bits/stdc++.h>
using namespace std;

struct Queue{
  int size;
  int front;
  int rear;
  int *Q;
};

void create(struct Queue *q, int size){
  q->size = size;
  q->front = q->rear = 0;
  q->Q = new int[q->size];
}

void enqueue(struct Queue *q, int x){
  if((q->rear+1)%q->size == q->front){
    cout << "Queue is full" << endl;
  }else{
    q->rear = (q->rear+1)%q->size;
    q->Q[q->rear] = x;
  }
}

int dequeue(struct Queue *q){
  int x = -1;
  if(q->front == q->rear){
    cout << "Queue is empty" << endl;
  }else{
    q->front = (q->front+1)%q->size;
    x = q->Q[q->front];
  }
  return x;
}

void Display(struct Queue q){
  int i = q.front+1;
  do{
    cout << q.Q[i] << " ";
    i = (i+1)%q.size;
  }while(i != (q.rear+1)%q.size);
  cout << endl;
}

int main(){
  struct Queue q;
  create(&q, 5);
  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  Display(q);
  cout << dequeue(&q) << endl;
  Display(q);
  enqueue(&q, 40);
  Display(q);
  return 0;
}