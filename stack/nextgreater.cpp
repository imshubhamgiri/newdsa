#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    int n = arr.size();

    stack<int>s;
    vector<int> ans;

    for(int i= n-1; i>=0; i--){
        while(s.size()>0 && s.top() <= arr[i]){
                s.pop();
        }
        if(s.empty()){
            ans.push_back(-1);
        }else{
            ans.push_back(s.top());  
        }
        s.push(arr[i]);
    }
 

    for(int val:ans){
        cout<<val<<" ";
    }

    return 0;

}