// Print number from 1 to n and n to 1
#include<bits/stdc++.h>
using namespace std;

void printAsc(int n){
    if(n<1) return;
    printAsc(n-1);
    cout << n << " ";
}

void printDesc(int n){
    if(n<1) return;
    cout << n << " ";
    printDesc(n-1);

}

void printt(int n){
	if(n<1) return;	//(Base Case)
  	cout << n << " ";	    // (Induction part)  	
	printt(n-1);		//(Hypothesis)
	// cout << n << " ";	    // (Induction part)
}

int main(){
    int n;
    cin >> n;
    // printt(n);
    cout << endl;
    printAsc(n);
    cout << endl;
    printDesc(n);
    return 0;
}