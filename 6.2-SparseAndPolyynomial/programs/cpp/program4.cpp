#include<bits/stdc++.h>
using namespace std;
struct Term{
  int coeff;
  int exp;
};
struct Poly{
  int n;
  struct Term *terms;
};

void create(struct Poly *p){
  cout<<"Enter number of terms: ";
  cin>>p->n;
  p->terms = new Term[p->n];
  cout<<"Enter terms: ";
  for(int i = 0; i < p->n; i++){
    cin>>p->terms[i].coeff>>p->terms[i].exp;
  }
}

void display(struct Poly p){
  for(int i = 0; i < p.n; i++){
    cout<<p.terms[i].coeff<<"x"<<p.terms[i].exp<<" + ";
  }
  cout<<endl;
}

struct Poly *addPoly(struct Poly *p1, struct Poly *p2){
  struct Poly *sum = new Poly;
  sum->terms = new Term[p1->n + p2->n];
  int i = 0, j = 0, k = 0;
  while(i < p1->n && j < p2->n){
    if(p1->terms[i].exp > p2->terms[j].exp){
      sum->terms[k++] = p1->terms[i++];
    }
    else if(p1->terms[i].exp < p2->terms[j].exp){
      sum->terms[k++] = p2->terms[j++];
    }
    else{
      sum->terms[k].exp = p1->terms[i].exp;
      sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
    }
  }
  for(; i < p1->n; i++){
    sum->terms[k++] = p1->terms[i];
  }
  for(; j < p2->n; j++){
    sum->terms[k++] = p2->terms[j];
  }
  sum->n = k;
  return sum;
}

int main(){
  struct Poly p,p1,*p2;
  create(&p);
  display(p);
  
  create(&p1);
  display(p1);

  p2 = addPoly(&p, &p1);
  display(*p2);


  return 0;
}
