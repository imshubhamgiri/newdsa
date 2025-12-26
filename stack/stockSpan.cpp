#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(arr)/sizeof(arr[0]);

    stack<int> st;
    vector<int> ans(n,0);

    for(int i=0; i<n; i++){
      while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
          }
        
        if(st.empty()){
            ans[i] = i+1;
        }
        else{
            ans[i] = i - st.top();
        }
        st.push(i);
    }
    for(int val:ans){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}