#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;



class Solution{
    public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> m;
            int n = nums.size();
            int l = 0, r = 0;
            long long sum = 0;       // Use long long to prevent integer overflow
            long long maxSum = 0;

            while (r < n) {
                int val = nums[r];
                // If a duplicate is found, shrink the window from the left 
                // until the duplicate element is completely removed
                while (m.find(val) != m.end()) {
                    sum -= nums[l];
                    m.erase(nums[l]);
                    l++;
                }

                // Safely insert the unique element
                m.insert(val); //insert 
                sum += val;

                // Check if the current window size is exactly k
                if (r - l + 1 == k) {
                    maxSum = max(maxSum, sum);

                    // Slide the left pointer forward to prepare for the next element
                    sum -= nums[l];
                    m.erase(nums[l]);
                    l++;
                }
                
                r++;
            }

            return maxSum;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {1,5,4,2,9,9,9};

   cout << sol.maximumSubarraySum(nums , 3);

}