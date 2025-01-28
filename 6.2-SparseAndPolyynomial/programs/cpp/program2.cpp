#include<bits/stdc++.h>
using namespace std;

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s){
    cout << "Enter dimensions: ";
    cin >> s->m >> s->n;
    cout << "Enter number of non-zero elements: ";
    cin >> s->num;
    s->ele = new Element[s->num];
    cout << "Enter non-zero elements: ";
    for(int i = 0; i < s->num; i++){
        cin >> s->ele[i].i >> s->ele[i].j >> s->ele[i].x;
    }
}

void display(struct Sparse s){
    int k = 0;
    for(int i = 0; i < s.m; i++){
        for(int j = 0; j < s.n; j++){
            if(i == s.ele[k].i && j == s.ele[k].j){
                cout << s.ele[k++].x << " ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

struct Sparse * add( struct Sparse *s1, struct Sparse *s2){
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;
    if(s1->m != s2->m || s1->n != s2->n){
        return NULL;
    }
    sum = new Sparse;
    sum->ele = new Element[s1->num + s2->num];
    while(i < s1->num && j < s2->num){
        if(s1->ele[i].i < s2->ele[j].i){
            sum->ele[k++] = s1->ele[i++];
        }
        else if(s1->ele[i].i > s2->ele[j].i){
            sum->ele[k++] = s2->ele[j++];
        }
        else{
            if(s1->ele[i].j < s2->ele[j].j){
                sum->ele[k++] = s1->ele[i++];
            }
            else if(s1->ele[i].j > s2->ele[j].j){
                sum->ele[k++] = s2->ele[j++];
            }
            else{
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }
    for(; i < s1->num; i++){
        sum->ele[k++] = s1->ele[i];
    }
    for(; j < s2->num; j++){
        sum->ele[k++] = s2->ele[j];
    }
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;
    return sum;
}

int main(){

    struct Sparse s;
    create(&s);
    display(s);
    struct Sparse s1;
    create(&s1);
    display(s1);
    struct Sparse *sum;
    sum = add(&s, &s1);
    display(*sum);
    
    return 0;
}
