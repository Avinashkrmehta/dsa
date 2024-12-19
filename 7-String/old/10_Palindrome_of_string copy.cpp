
#include<bits/stdc++.h>
using namespace std;

bool isPlaindrome(char str[]){
  int i,j;
  for(j=0; str[j] !='\0'; j++){
  }

  j=j-1;
  for(i=0; i<j; i++,j--){
      if(str[i] != str[j])
        return false;
  }
  return true;
}

int main(){
  char str[] = "12321";
  cout << boolalpha;
  cout << isPlaindrome(str);
return 0;
}