
//Reversing a string using another array of string sapace
#include<bits/stdc++.h>
using namespace std;

int main(){
  char str[] = "avinash";

  int i,j,t;
  for(j=0; str[j] != '\0'; j++){}
  j = j-1;
  for(i=0; i<j;i++,j--){
    t = str[i];
    str[i] = str[j];
    str[j] = t;
  }

  cout << str;
  return 0;
}