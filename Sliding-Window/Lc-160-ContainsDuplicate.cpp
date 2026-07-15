#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{

    public:

        bool containsDuplicate(vector<int>& nums , int k) {
            unordered_set<int> seen;
           
            for (int i = 0; i < nums.size(); ++i) {
                /*
                if (i > k) {
                    seen.erase(nums[i - k - 1]); you can also use this approach to maintain the size of the set to be at most k, but in this case, we are using a different approach to maintain the size of the set.    
                }
                */
                    if (seen.count(nums[i])) { //This checks if the current number is already in the set, indicating a duplicate within the range of k.
                        return true; // Duplicate found
                    }


                    seen.insert(nums[i]);
                    
                    // Maintain the size of the set to be at most k

                    if (seen.size() > k) {
                        seen.erase(nums[i - k]); // Remove the element that is now out of the k-range
                    }

                }   
            return false; // No duplicates found
        }
};

int main(){
Solution sol;
vector<int> nums = {1, 2, 1, 4, 5, 1}; // Example input
int k = 3; // Example k value
cout << sol.containsDuplicate(nums, k) << endl;
}