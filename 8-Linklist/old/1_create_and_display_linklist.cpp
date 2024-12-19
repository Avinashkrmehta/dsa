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
    cout << node->data << "->";
    node = node->next;
  }
  cout << "NULL";
}

int main(){
    int A[] = {1,3,5,7,9};
    Create(A,5);
    Display(head);
  return 0;
}