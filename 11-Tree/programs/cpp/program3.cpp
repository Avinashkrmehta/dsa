// Creating binary tree in cpp with using class


#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue{
  private:
    int size;
    int front;
    int rear;
    Node **Q;
  public:
    Queue(){
      size = 10;
      front = rear = -1;
      Q = new Node*[this->size];
    }
    Queue(int size){
      this->size = size;
      front = rear = -1;
      Q = new Node*[this->size];
    }
    void enqueue(Node* x);
    Node * dequeue();
    void Display();
    int isEmpty();
};

void Queue::enqueue(Node* x){
  if(rear == size-1){
    cout << "Queue is full" << endl;
  }else{
    rear++;
    Q[rear] = x;
  }
}

Node* Queue::dequeue(){
  Node* x = NULL;
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

int Queue::isEmpty(){
  return front == rear;
}

class Tree{
  public:
    Node *root;
    Tree(){
      root = NULL;
    }
    void createTree();
    void preOrder(Node *p);
    void inOrder(Node *p);
    void postOrder(Node *p);
    void levelOrder(Node *p);
    int height(Node *p);
};

void Tree::createTree(){
  Node *p, *t;
  int x;
  Queue q(100);
  cout << "Enter root value: ";
  cin >> x;
  cout << x << endl;
  root = new Node;
  root->data = x;
  root->lchild = root->rchild = NULL;
  q.enqueue(root);
  while(!q.isEmpty()){
    p = q.dequeue();
    cout << "Enter left child of " << p->data << ": ";
    cin >> x;
    cout << x << endl;
    if(x != -1){
      t = new Node;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      q.enqueue(t);
    }
    cout << "Enter right child of " << p->data << ": ";
    cin >> x;
    cout << x << endl;
    if(x != -1){
      t = new Node;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      q.enqueue(t);
    }
  }
} 

void Tree::preOrder(Node *p){
  if(p){
    cout << p->data << " ";
    preOrder(p->lchild);
    preOrder(p->rchild);
  }
}

void Tree::inOrder(Node *p){
  if(p){
    inOrder(p->lchild);
    cout << p->data << " ";
    inOrder(p->rchild);
  }
}

void Tree::postOrder(Node *p){
  if(p){
    postOrder(p->lchild);
    postOrder(p->rchild);
    cout << p->data << " ";
  }
}

void Tree::levelOrder(Node *p){
  Queue q(100);
  cout << root->data << " ";
  q.enqueue(root);
  while(!q.isEmpty()){
    p = q.dequeue();
    if(p->lchild){
      cout << p->lchild->data << " ";
      q.enqueue(p->lchild);
    }
    if(p->rchild){
      cout << p->rchild->data << " ";
      q.enqueue(p->rchild);
    }
  }
}

int Tree::height(Node *p){
  int x = 0, y = 0;
  if(p == NULL){
    return 0;
  }
  x = height(p->lchild);
  y = height(p->rchild);
  if(x > y){
    return x+1;
  }else{
    return y+1;
  }
}

int main(){
  Tree t;
  t.createTree();
  t.preOrder(t.root);
  cout << endl;
  t.inOrder(t.root);
  cout << endl;
  t.postOrder(t.root);
  cout << endl;
  t.levelOrder(t.root);
  cout << endl;
  cout << t.height(t.root) << endl;
  
  return 0;
}
// Output:
// Enter root value: 1
// 1
// Enter left child of 1: 2
// 2
// Enter right child of 1: 3
// 3
// Enter left child of 2: 4
// 4
// Enter right child of 2: 5
// 5
// Enter left child of 3: 6
// 6
// Enter right child of 3: 7
// 7
// 1 2 4 5 3 6 7
