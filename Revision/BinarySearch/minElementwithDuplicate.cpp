#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//This question Have two variations, one is with duplicates and another is without duplicates. This code is for the one without duplicates. The code for the one with duplicates is in the next file.

class Solution{
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }else if(nums[mid] < nums[high]){
                high = mid;
            }else{
                high--;   //This is the only line that is different from the code without duplicates. When nums[mid] == nums[high], we cannot determine which side is sorted, so we just reduce the search space by one element (high--). 
            }
        }
        return nums[low];
    }

};

int main(){
    Solution s;
    vector<int> nums = {3,4,5,1,2,2,2};
    cout<<s.findMin(nums)<<endl;
    return 0;
}