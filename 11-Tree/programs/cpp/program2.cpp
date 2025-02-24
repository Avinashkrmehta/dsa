// Creating binary tree in cpp


#include<bits/stdc++.h>
using namespace std;

struct Node{
  struct Node *lchild;
  int data;
  struct Node *rchild;
}; 


struct Queue{
    int size;
    int front;
    int rear;
    Node **Q;
  };
  

  void create(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new Node *[q->size];
  }
  
  void enqueue(struct Queue *q, Node * x){
    if((q->rear+1)%q->size == q->front){
      cout << "Queue is full" << endl;
    }else{
      q->rear = (q->rear+1)%q->size;
      q->Q[q->rear] = x;
    }
  }
  
  Node * dequeue(struct Queue *q){
    Node * x = NULL;
    if(q->front == q->rear){
      cout << "Queue is empty" << endl;
    }else{
      q->front = (q->front+1)%q->size;
      x = q->Q[q->front];
    }
    return x;
  }

  int isEmpty(struct Queue q){
    return q.front == q.rear;
  }


struct Node *root = NULL;

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    cout << "Enter root value: ";
    cin >> x;
    cout << x << endl;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while(!isEmpty(q)){
        p = dequeue(&q);
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        cout << x << endl;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        cout << x << endl;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
   
void preOrder(struct Node *p){
    if(p){
        cout << p->data << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void inOrder(struct Node *p){
    if(p){
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

void postOrder(struct Node *p){
    if(p){
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data << " ";
    }
}

int main(){
    Treecreate();
    cout << "Preorder: ";
    preOrder(root);
    cout << endl;
    cout << "Inorder: ";
    inOrder(root);
    cout << endl;
    cout << "Postorder: ";
    postOrder(root);
    cout << endl;
    return 0;
}
