// Generate all the strings of length n drawn from 0... k – 1.

#include<bits/stdc++.h>
using namespace std;

char A[32];
void k_string(int n, int k){
  if(n < 1){
    cout << A << endl;
  }else{
    for(int j=0; j<k;j++){
      A[n-1] = j;
      k_string(n-1,k);
    }
  }
}


int main(){
  string s = "aaBAbcCAb";
  char c  = s[0]-32;
  cout << c << endl;
  sort(s.begin(), s.end());
  cout << s;
  int n = 3;
  int k = 3;
  // k_string(n,k);
  return 0;
}