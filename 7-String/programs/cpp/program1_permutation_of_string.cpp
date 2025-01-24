#include<bits/stdc++.h>
using namespace std;

void Permutation(char str[], int k){
  static int  A[10] = {0};
  static char res[10];

  if(str[k] == '\0'){
    res[k] = '\0';
    cout<< res << endl;
  }
  else
  {
    for (int i = 0; str[i]!='\0'; i++)
    {
      if (A[i]==0)
      {
        res[k] = str[i];
        A[i] =1;
        Permutation(str,k+1);
        A[i] = 0;
      }
    }
  }

}



int main(){
  char s[] = "ABC";
  Permutation(s,0);
  return 0;
}