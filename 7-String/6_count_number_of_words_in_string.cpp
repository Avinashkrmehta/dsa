
#include<bits/stdc++.h>
using namespace std;

int main(){
  char str[] ="How are   avi  you";
  int i, word=1;
  for(i=0; str[i] !='\0'; i++){
    if((str[i] == ' ') && (str[i-1] != ' ')){
      word++;
    }
      
  }
  cout << "Number of words is-->" << word;
  return 0;
}