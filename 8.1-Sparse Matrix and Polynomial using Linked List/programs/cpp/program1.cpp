// Let's Code Polynomial using Linklist

#include<bits/stdc++.h>
using namespace std;

struct Node{
  int coeff;
  int exp;
  struct Node *next;
}*poly=NULL;

void create(){
  struct Node *t, *last = NULL;
  int num;
  cout << "Enter number of terms: ";
  cin >> num;
  cout << "Enter each term with coeff and exp: ";
  for (int i = 0; i < num; i++)
  {
    t = new Node;
    cin >> t->coeff >> t->exp;
    t->next = NULL;
    if(poly == NULL){
      poly = last = t;
    }else{
      last->next = t;
      last = t;
    }
  }
}

void Display(struct Node *p){
  while(p){
    cout << p->coeff << "x" << p->exp;
    p = p->next;
    if(p!=NULL) cout << " + ";
  }
  cout << endl;
}

int evaluate(struct Node *p, int x){
  int sum = 0;
  while(p){
    sum += p->coeff * pow(x, p->exp);
    p = p->next;
  }
  return sum;
}

int main(){
  create();
  Display(poly);
  cout << "Result: " << evaluate(poly, 2) << endl;
  return 0;
}