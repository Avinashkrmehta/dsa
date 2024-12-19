
#include<bits/stdc++.h>
using namespace std;

int main(){
  int i=0;
  char str[] = "finding";
  int H[26] = {0};
  for(i=0; str[i] != '\0'; i++){
    H[str[i] - 97] += 1;
  }
  
  for(i=0; i<26; i++){
    if(H[i] > 1){
      cout << static_cast<char>(i+97) << " " << H[i] << endl;
    }
  }
return 0;
}