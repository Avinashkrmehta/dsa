
#include<bits/stdc++.h>
using namespace std;

int main(){
  char str[] ="WeLcOmE";
  int i;
  cout << "Before changing"<< endl;
  cout << str<< endl;
  for(i=0; str[i] != '\0'; i++){
    if(str[i] >= 'a' && str[i] <= 122)
      str[i] = str[i] - 32;
    else if(str[i] >= 65 && str[i] <= 90)
      str[i] += 32;
  }
  cout << "After changing"<< endl;
  cout << str<< endl;
  return 0;
}