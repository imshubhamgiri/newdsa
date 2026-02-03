#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> arr1 = {2,4};
    vector<int> arr2 = {1,2,3,4};
    int n = arr1.size();
    stack<int>s;
    unordered_map<int,int> mp;
    vector<int>ans(n ,0);
    int i= n-1 , j= arr2.size()-1;

    
    while( j>=0){
        while(s.size()>0 && s.top()<=arr2[j]){
            s.pop();
        }
        if(s.empty()){
            if(mp.find(arr2[j])==mp.end()){
                mp[arr2[j]] = -1;
            }
        }else{
            if(mp.find(arr2[j])==mp.end()){
                mp[arr2[j]] = s.top();
            }
        }
        s.push(arr2[j]);
        j--;
    }

    for(int k=0; k<n; k++){
        ans[k] = mp[arr1[k]];
    }
    cout<<"[";
    for(int val:ans){
        cout<<val<<" ";
    }
    cout<<"]";
}