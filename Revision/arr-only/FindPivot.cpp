#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int pivotIndex(vector<int>& nums) {
        int n= nums.size();
        vector<int>prefix(n,0);
        //calculate prefix sum
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i-1]; //{1,7,3,6,5,6} for this array prefix sum will be {0,1,8,11,17,22}
        }

        //calculate suffix sum and compare with prefix sum
        int suffix = 0;
        int idx =-1;
        for(int i=n-1; i>=0; i--){ //this loop will go on prefix like suffix = {0,6,11,17,22,28} for this array and as you can see at index 3 prefix sum and suffix sum are equal so we will update the index of pivot element to 3

            if(prefix[i]==suffix){        //Now we will compare prefix sum and suffix sum if they are equal then we will update the index of pivot element
               idx=i; 
            }
            suffix+= nums[i];  
        }   //
        return idx;


        // int total_sum = accumulate(nums.begin(), nums.end(), 0); //Now int this approach we will calculate the total sum of the array and then we will iterate through the array and calculate the left sum and right sum and compare them if they are equal then we will return the index of pivot element
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