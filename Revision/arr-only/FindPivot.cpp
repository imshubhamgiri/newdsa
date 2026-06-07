#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int pivotIndex(vector<int>& nums) {
        int n= nums.size();
        vector<int>prefix(n,0);
        //calculate prefix sum
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        //calculate suffix sum and compare with prefix sum
        int suffix = 0;
        int idx =-1;
        for(int i=n-1; i>=0; i--){
            if(prefix[i]==suffix){
               idx=i; 
            }
            suffix+= nums[i];
        }
        return idx;


        // int total_sum = accumulate(nums.begin(), nums.end(), 0);
        // int left_sum = 0;
        
        // for (int i = 0; i < nums.size(); i++) {
        //     // Right sum is total_sum - left_sum - nums[i]
        //     if (left_sum == total_sum - left_sum - nums[i]) {
        //         return i;
        //     }
        //     left_sum += nums[i];
        // }
        // return -1;
    }
int main(){
    vector<int> nums = {1,7,3,6,5,6};
    cout<<pivotIndex(nums)<<endl;
}