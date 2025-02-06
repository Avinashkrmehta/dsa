// Stack implementation

#include<bits/stdc++.h>
using namespace std;

struct Stack{
  int size;
  int top;
  int *S;
};

void create(struct Stack *st){
  cout << "Enter size: ";
  cin >> st->size;
  cout << st->size << endl;
  st->top = -1;
  st->S = new int[st->size];
}

void Display(struct Stack st){
  for (int i = st.top; i >= 0; i--)
  {
    cout << st.S[i] << " ";
  }
  cout << endl;
}

void push(struct Stack *st, int x){
  if(st->top == st->size-1){
    cout << "Stack Overflow" << endl;
  }else{
    st->top++;
    st->S[st->top] = x;
  }
}

int pop(struct Stack *st){
  int x = -1;
  if(st->top == -1){
    cout << "Stack Underflow" << endl;
  }else{
    x = st->S[st->top];
    st->top--;
  }
  return x;
}

int peek(struct Stack st, int index){
  int x = -1;
  if(st.top-index+1 < 0){
    cout << "Invalid Index" << endl;
  }else{
    x = st.S[st.top-index+1];
  }
  return x;
}

int stackTop(struct Stack st){
  if(st.top == -1){
    return -1;
  }else{
    return st.S[st.top];
  }
}

int isEmpty(struct Stack st){
  return st.top == -1;
}

int isFull(struct Stack st){
  return st.top == st.size-1;
}

int main(){
  struct Stack st;
  create(&st);

  push(&st, 10);
  push(&st, 20);
  push(&st, 30);
  push(&st, 40);
  push(&st, 50);
  push(&st, 60);

  cout << "Popped: " << pop(&st) << endl;

  cout << "Peek: " << peek(st, 2) << endl;

  Display(st);

  return 0;
}
