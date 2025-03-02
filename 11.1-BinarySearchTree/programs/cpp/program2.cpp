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

// Recursive inserting in Binary Sarach Tree

struct Node *Rinsert(struct Node *p, int key) {
    struct Node *t = NULL;

    if (p == NULL) {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
        p->lchild = Rinsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = Rinsert(p->rchild, key);

    return p;
}

// Height of a Binary Search Tree

int height(struct Node *p) {
    int x, y;
    if (p == NULL)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
}


// Inorder Predecessor in a Binary Search Tree

struct Node *InPre(struct Node *p) {
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

// Inorder Successor in a Binary Search Tree

struct Node *InSucc(struct Node *p) {
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}


struct Node *DeleteNode(struct Node *p, int key) {
    struct Node *q;

    if (p == NULL)
        return NULL;

    if (p->lchild == NULL && p->rchild == NULL) {
        if (p == root)
            root = NULL;
        delete p;
        return NULL;
    }

    if (key < p->data)
        p->lchild = DeleteNode(p->lchild, key);
    else if (key > p->data)
        p->rchild = DeleteNode(p->rchild, key);
    else {
        if (height(p->lchild) > height(p->rchild)) {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = DeleteNode(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = DeleteNode(p->rchild, q->data);
        }
    }
    return p;
}


int main() {

    // insert(10);
    // insert(5);
    // insert(20);
    // insert(8);
    // insert(30);

    root = Rinsert(root, 10);
    Rinsert(root, 5);
    Rinsert(root, 20);
    Rinsert(root, 8);
    Rinsert(root, 30);


    inorder(root);
    cout << endl;

    struct Node *temp = search(10);
    if (temp != NULL) {
        cout << temp->data << " is found" << endl;
    } else {
        cout << "Key not found" << endl;
    }

    DeleteNode(root, 20);
    inorder(root); 

    return 0;
}




