// Lets code LL Rotation on AVL tree

#include<bits/stdc++.h>
using namespace std;

struct Node {
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root = NULL;

int NodeHeight(struct Node *p) {
    int hl, hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(struct Node *p) {
    int hl, hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

struct Node *LLRotation(struct Node *p) {
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p) {
        root = pl;
    }

    return pl;
}

struct Node *LRRotation(struct Node *p) {
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root == p) {
        root = plr;
    }

    return plr;
}

struct Node *RRRotation(struct Node *p) {
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p) {
        root = pr;
    }

    return pr;
}

struct Node *RLRotation(struct Node *p) {
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if (root == p) {
        root = prl;
    }

    return prl;
}

struct Node *RInsert(struct Node *p, int key) {
    struct Node *t;

    if (p == NULL) {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data) {
        p->lchild = RInsert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = RInsert(p->rchild, key);
    }

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    }else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) {
        return RRRotation(p);
    }else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) {
        return LRRotation(p);
    }else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) {
        return RLRotation(p);
    }

    return p;
}

void Inorder(struct Node *p) {
    if (p) {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

int main() {

    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 2);
    RInsert(root, 20);
    RInsert(root, 1);

    Inorder(root);
    cout << endl;

    return 0;
}




