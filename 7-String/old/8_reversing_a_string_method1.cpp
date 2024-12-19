
//Reversing a string using another array of string sapace
#include<bits/stdc++.h>
using namespace std;

int main(){
  char str[] = "avinash";
  char str2[8];
  int i,j;
  for(i=0; str[i] != '\0'; i++){}
  i = i-1;
  for(j=0; i>=0;i--,j++){
    str2[j]= str[i];
  }
  str[j] = '\0';
  cout << str2;
  return 0;
}