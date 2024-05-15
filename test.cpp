
#include<bits/stdc++.h>
using namespace std;


int main(){

        string word  = "abcdefd";
        char ch = 'd';
        string res;
        int i;
        int len = word.length();
        for(i=0; i< len; i++){
            if(word[i] == ch)
                break;
        }
        cout << "iii" << i << endl;
        for(int j=0; j<len; j++){
            if(0<i){
              cout << "jj" << j << endl;
              cout << "ii" << i << endl;
                res +=word[i--];
            }else{
                res += word[j];
            }
        }

    // vector<int> nums1 = {2,2,4,4};
    // vector<int> nums2 = {2,2,4,4};
    // vector<int> merged(nums1.size() + nums2.size()); 
    // merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), 
    // merged.begin());
    // for(int i=0; i< merged.size(); i++){
    //    cout << merged[i] << " ";
    // }
    // if(merged.size()%2 == 0){
    //  cout << ((merged[merged.size()/2]-1) + merged[merged.size()/2]) / 2 ;
    // }
    // cout << endl;
    // cout << merged[merged.size()/2];
  return 0;
}