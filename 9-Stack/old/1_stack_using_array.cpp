// Array Introduction
#include<bits/stdc++.h>
using namespace std;
struct Stack
{
  int size;
  int top;
  int *S;
};

void create(struct Stack *st){
  cout << "Enter Size of Stack \n";
  cin >> st->size;
  cout << st->size;
  st->top = -1;
  st->S = new int[st->size];
}

void Display(struct Stack st){
  int i;
  for(i=st.top; i>=0; i--){
    cout << st.S[i] << " ";
  }
  cout << "\n";
}

void Push(struct Stack *st, int x){
  if(st->top == st->size -1)
    cout << " \nStack Overflow";
  else{
    st->top++;
    st->S[st->top] = x;
  }
}

int Pop(struct Stack *st){
  int x = -1;
  if(st->top == -1){
    cout << "\n Stack Underflow";
  }
  else{
    x = st->S[st->top];
    st->top--;
  }
  return x;
}

int Peek(struct Stack st, int pos){
  int x = -1;
  if(st.top - pos +1 < 0)
    cout << "Invalid Position passed";
  else
    x = st.S[st.top-pos+1];
  return x;
}
int IsEmpty(struct Stack st){
  if(st.top == -1)
    return 1;
  return 0;
}
int StackTop(struct Stack st){
  if(!IsEmpty(st))
    return st.S[st.top];
  return -1;
}

int IsFull(struct Stack st){
  return st.top == st.size-1;
}

int main(){
  struct Stack st;
  create(&st);
  // Push(&st,5);
  // Push(&st,4);
  // Push(&st,3);
  // Push(&st,2);
  // Push(&st,3);
  // Push(&st,2);1
  cout << "\n";
  Display(st);
  // cout << Pop(&st);
  // cout << "\n";
  // Display(st);
  cout << "Peek--->" <<  Peek(st,2);
    cout << "\n";
  cout << "ISFull--->" << IsFull(st);
    cout << "\n";
  cout << "StackTop--->" << StackTop(st);
    cout << "\n";
  cout << "IsEmpty--->" << IsEmpty(st);
  return 0;
}