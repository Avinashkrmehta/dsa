// Queue implementation using array in cpp

#include<bits/stdc++.h>
using namespace std;

class Queue{
  private:
    int size;
    int front;
    int rear;
    int *Q;
  public:
    Queue(){
      size = 10;
      front = rear = -1;
      Q = new int[this->size];
    }
    Queue(int size){
      this->size = size;
      front = rear = -1;
      Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void Display();
};

void Queue::enqueue(int x){
  if(rear == size-1){
    cout << "Queue is full" << endl;
  }else{
    rear++;
    Q[rear] = x;
  }
}

int Queue::dequeue(){
  int x = -1;
  if(front == rear){
    cout << "Queue is empty" << endl;
  }else{
    front++;
    x = Q[front];
  }
  return x;
}

void Queue::Display(){
  for(int i = front+1; i <= rear; i++){
    cout << Q[i] << " ";
  }
  cout << endl;
}

int main(){
  Queue q(5);
  q.enqueue(100);
  q.enqueue(200);
  q.enqueue(300);
  q.Display();
  cout << q.dequeue() << endl;
  q.Display();
  q.enqueue(400);
  q.Display();
  return 0;
}

// Output
// 10 20 30
// 10
// 20 30
// 20 30 40

