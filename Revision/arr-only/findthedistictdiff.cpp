#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

void distinctDiff(vector<int>& nums) {
    int n=nums.size();
    vector<int>prefix(n,0);
    unordered_set<int>s;
    int count =0;
    for(int i=0; i<n; i++){
       if(s.find(nums[i])==s.end()){
        count++;
    }
    prefix[i] = count;
       s.insert(nums[i]);
    }

        for(int i=0; i<n; i++){
            cout<<"at"<<i<<" prefix "<<prefix[i]<<endl;
        }
        // int suffix = 0;
        // int idx =-1;
        // for(int i=n-1; i>=0; i--){
        //     // if(prefix[i]==suffix){
        //     //    idx=i; 
        //     // }
        //     cout<<"at"<<i<<" prefix "<<prefix[i]<<" suffix "<<suffix<<endl;
        //     suffix+= nums[i];
        // }
        // return idx;
    }
int main(){
    vector<int> nums = {3,2,3,4,2};
    distinctDiff(nums);
}