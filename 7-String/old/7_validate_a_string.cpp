
#include<bits/stdc++.h>
using namespace std;

int valid(char *name){
  int i;
  for(i=0; name[i] != '\0'; i++){
    if (!(name[i] >=65 && name[i] <= 90) &&
        !(name[i] >=97 && name[i] <= 122) &&
        !(name[i] >=48 && name[i] <= 54))
          return 0;
  }
  return 1;
}

int valid1(char *name){
  int i;
  for(i=0; name[i] != '\0'; i++){
    if (!(name[i] >='A' && name[i] <= 'Z') &&
        !(name[i] >= 'a' && name[i] <= 'z') &&
        !(name[i] >=48 && name[i] <= 54))
          return 0;
  }
  return 1;
}

int main(){
  char *name = "Avinash321";
  if(valid1(name))
    cout << "Valid Stringh";
  else
    cout << "Invalid String";
}