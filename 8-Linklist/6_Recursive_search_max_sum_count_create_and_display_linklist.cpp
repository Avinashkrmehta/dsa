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

void RecursiveDisplay(struct Node *node){
  if(node!=NULL){
    cout << node->data << " ";
    RecursiveDisplay(node->next);
  }
}

void ReverseRecursiveDisplay(struct Node *node){
  if(node!=NULL){
    ReverseRecursiveDisplay(node->next);
    cout << node->data << " ";
  }
}

int Count(struct Node *node){
  if(node == 0)
    return 0;
  else{
    return Count(node->next) + 1;
  }
}

int Sum(struct Node *node){
  if(node == 0)
    return 0;
  else
    return Sum(node->next) + node->data;
}

int RMax(struct Node *node){
  int x;
  if(node == 0)
    return 0;
  else
    x = RMax(node->next);
    // if(x > node->data)
    //   return x;
    // else
    //   return node->data;

   return x>node->data? x : node->data;
}

struct Node * RecursiveSearch(struct Node * node, int key){
  if(node == NULL)
    return node;
  if(key == node->data)
    return node;
  return RecursiveSearch(node->next,key);
}

int main(){
    int A[] = {1,3,5,7,9};
    struct Node * temp;
    Create(A,6);
    RecursiveDisplay(head);
    cout << endl;
    temp = RecursiveSearch(head,9);
    if(temp)
      cout << "Element is found in Linklist" << temp->data;
    else
      cout << "Data not found in linklist";
  return 0;
}