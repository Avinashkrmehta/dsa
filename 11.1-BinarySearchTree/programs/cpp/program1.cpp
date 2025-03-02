// Binary search tree implementation in C++

#include<bits/stdc++.h>
using namespace std;

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

void insert(int key) {
    struct Node *t = root;
    struct Node *r = NULL, *p;

    if (root == NULL) {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while (t != NULL) {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }

    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data) r->lchild = p;
    else r->rchild = p;
}

void inorder(struct Node *p) {
    if (p) {
        inorder(p->lchild);
        cout << p->data << ", " << flush;
        inorder(p->rchild);
    }
}

struct Node *search(int key) {
    struct Node *t = root;

    while (t != NULL) {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

int main() {

    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);

    inorder(root);
    cout << endl;

    struct Node *temp = search(10);
    if (temp != NULL) {
        cout << temp->data << " is found" << endl;
    } else {
        cout << "Key not found" << endl;
    }

    return 0;
}




