// Generating BST from preorder

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* constructTree(int pre[], int n){
    stack<Node*> s;
    Node* root = newNode(pre[0]);
    s.push(root);

    for(int i=1; i<n; i++){
        Node* temp = NULL;

        while(!s.empty() && pre[i] > s.top()->data){
            temp = s.top();
            s.pop();
        }

        if(temp != NULL){
            temp->right = newNode(pre[i]);
            s.push(temp->right);
        }
        else{
            s.top()->left = newNode(pre[i]);
            s.push(s.top()->left);
        }
    }
    return root;
}

void printInorder(Node* root){
    if(root == NULL)
        return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}





