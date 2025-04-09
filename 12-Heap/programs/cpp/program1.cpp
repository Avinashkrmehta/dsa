//code Heap and Heap sort

#include<bits/stdc++.h>
using namespace std;

void Insert(int H[],int n){
  int i=n, temp;
  temp=H[n];
  while(i>1 && temp<H[i/2]){
    H[i]=H[i/2];
    i=i/2;
  }
  H[i]=temp;
}

int main(){
  int H[]={0,20,5,8,9,4,10,7};
  Insert(H,2);
  Insert(H,3);
  Insert(H,4);
  Insert(H,5);
  cout<<"Heap after insertion: ";
  for(int i=1;i<=7;i++){
    cout<<H[i]<<" ";
  }
  cout<<endl;
  return 0;
}



