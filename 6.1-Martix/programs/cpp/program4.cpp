// Lower triangular matrix
// Lower triangular matrix is a square matrix in which all the elements above the main diagonal are zero.
// Column major mapping
#include<bits/stdc++.h>
using namespace std;

struct Matrix{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x){
    if(i>=j){
        m->A[m->n * (j-1)+(j-2) * (j-1)/2+i-j] = x;
    }
}

int Get(struct Matrix m, int i, int j){
    if(i>=j){
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
    }
    else{
        return 0;
    }
}

void Display(struct Matrix m){
    cout << "The matrix is: " << endl;
    for(int i = 1; i <= m.n; i++){
        for(int j = 1; j <= m.n; j++){
            if(i>=j){
                cout << m.A[m.n * (j-1)+(j-2) * (j-1)/2+i-j] << " ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main(){
    struct Matrix m;
    cout << "Enter dimension of matrix: ";
    cin >> m.n;
    cout << m.n << endl;
    m.A = new int[m.n * (m.n + 1) / 2];
    int x;
    cout << "Enter all elements: " << endl;
    for(int i = 1; i <= m.n; i++){
        for(int j = 1; j <= m.n; j++){
            cin >> x;
            cout << x << " ";
            Set(&m, i, j, x);
        }
        cout << endl;
    }
    cout << endl;
    cout << "Matrix is: " << endl;
    Display(m);

    return 0;
}
