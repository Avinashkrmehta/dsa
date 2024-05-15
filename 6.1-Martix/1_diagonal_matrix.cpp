
#include<bits/stdc++.h>
using namespace std;
class Matrix{
  private:
   int *A;
   int n;
  public:
    Matrix(){
      n=2;
      A = new int[2];
    }
    Matrix(int num){
      this->n=num;
      A = new int[n];
    }
    int Get(int i, int j);
    void Set(int i, int j, int x);
    void Dispaly();

};
void Matrix::Set(int i, int j, int x){
  if(i==j){
    A[i-1] = x;  
  }
}

int Matrix::Get(int i, int j){
  if(i==j){
    return A[i-1];
  }else{
    return 0;
  }
}

void Matrix::Dispaly(){
  int i, j;
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(i==j){
        cout << A[i-1] << " " ;
      }else{
        cout << "0 ";
      }
    }
    cout << endl;
  }
}
int main(){
  Matrix matrix(4);
  matrix.Set(1,1,2);
  matrix.Set(2,2,3);
  matrix.Set(3,3,4);
  matrix.Set(4,4,5);
  matrix.Set(0,0,1);
  cout << matrix.Get(0,0) << "\n";
  matrix.Dispaly();
  return 0;
}