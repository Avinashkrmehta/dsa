#include<bits/stdc++.h>
using namespace std;

struct Node{
 int data;
 struct Node *next;
}*head=NULL;

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



int main(){
    int A[] = {1,3,100,5,7};
    struct Node * temp;
    Create(A,5);
    Display(head);
    cout << endl;
    temp = OptimizeLSearch(head, 100);
    if(temp)
      cout << "Element is found in Linklist" << temp->data;
    else
      cout << "Data not found in linklist";
    cout << endl;
    Display(head);
    cout << endl;
    temp = OptimizeLSearch(head, 3);
    Display(head);
  return 0;
}