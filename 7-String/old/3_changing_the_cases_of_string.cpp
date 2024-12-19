
#include<bits/stdc++.h>
using namespace std;

int main(){
  char str[] ="welcome";
  int i;
  cout << "String Before changing the case"<< endl;
  cout << str<< endl;
  for(i=0; str[i] != '\0'; i++){
    str[i] = str[i] - 32;
  }
  cout << "String After changing the case"<< endl;
  cout << str<< endl;
  return 0;
}