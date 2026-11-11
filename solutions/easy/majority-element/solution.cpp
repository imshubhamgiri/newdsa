// ============================================================================
// Problem: Majority Element (EASY)
// URL: https://leetcode.com/problems/majority-element/
// Language: C++
// Runtime: 1 ms
// Memory: 42 MB
// Time Complexity: O(n)
// Space Complexity: O(1)
// Synced by: Career OS (cos-leet)
// ============================================================================

class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int candidate = nums[0]; // Assume first element as initial candidate
        int count=1;               // Count for the current candidate
  for(int i=1;i<nums.size(); i++){ // Iterate from second element
    if(candidate==nums[i]){
        count++;               // Same as candidate -> increase count
    }
    else{
        count--;               // Different -> decrease count
    }
   if(count==0){
        candidate=nums[i];    // When count drops to 0, pick new candidate
        count=1;              // Reset count for new candidate
    }
  }

int freq =0;                     // Verify candidate's actual frequency
for(int val:nums){
 if(candidate==val){
    freq++;                    // Increment when match found
 }
}
if(freq >= nums.size()/2){      // Majority condition (>= floor(n/2))
     return candidate;
}


return -1;                      // No majority element (shouldn't happen per problem)

    }
};
