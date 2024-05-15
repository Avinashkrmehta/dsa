// Sort an array using recursion.

#include<bits/stdc++.h>
using namespace std;

void Insert(vector<int> &v, int temp){
	if(v.size() == 0 || v[v.size()-1] <=temp){
		v.push_back(temp);
		return;
	}
	int val = v[v.size()-1];
	v.pop_back();
	Insert(v,temp);
	v.push_back(val);
	return;


}
void Sort(vector<int> &v){
	if(v.size()==1){
		return;
	}
	int temp = v[v.size()-1]; // last element.
	v.pop_back();
    Sort(v);
    Insert(v, temp);
}


void insertSort(vector<int> &v, int temp){
  int len = v.size();
  if(len == 0 || v[len-1] <= temp){
    v.push_back(temp);
    return;
  }
  int val = v[len -1];
  v.pop_back();
  insertSort(v,temp);
  v.push_back(val);
  return;
}

void sortArray(vector<int> &v){
  int len = v.size();
  if(len == 1) return;
  int temp = v[len-1];
  v.pop_back();
  sortArray(v);
  insertSort(v,temp);
}


int main(){
  vector<int> v = {3,5,9,2,6,1,3};
  sortArray(v);
  // Sort(v);
  for(int i=0; i<v.size(); i++){
    cout << v[i] << " ";
  }
  return 0;
}