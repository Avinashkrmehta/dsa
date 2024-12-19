
#include<bits/stdc++.h>
using namespace std;

int main(){
  char str[] ="How are you";
  int i, vcount=0,ccount=0;
  for(i=0; str[i] != '\0'; i++){
    if( str[i] == 'a' || str[i] == 'A' ||
        str[i] == 'e' || str[i] == 'E' ||
        str[i] == 'i' || str[i] == 'I' ||
        str[i] == 'o' || str[i] == 'O' ||
        str[i] == 'u' || str[i] == 'U'
      )
        vcount++;
    else if(str[i] >=65 && str[i] <= 90 ||
            str[i] >=97 && str[i] <= 122
           )
            ccount++;
  }
  cout << "Vowel in string-->" << vcount << endl;
  cout << "Consonent in string-->" << ccount << endl;
  return 0;
}