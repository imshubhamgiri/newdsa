//Use bucket sort to find the top k frequent elements in an array
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int num : nums) {
            freq[num]++;
        }
        
        vector<vector<int>> buckets(nums.size() + 1);
        // for (const auto& pair : freq) {
        //     buckets[pair.second].push_back(pair.first);
        // }
        
        // vector<int> result;
        // for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
        //     if (!buckets[i].empty()) {
        //         result.insert(result.end(), buckets[i].begin(), buckets[i].end());
        //     }
        // }
        
        // result.resize(k); // Ensure we only return k elements
        // return result;

        for (auto& pair : freq) {
            int num = pair.first;
            int frequency = pair.second;
            buckets[frequency].push_back(num);
        }
    
        // 4. Collect top k frequent elements from right to left
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
    
        return result;
    }

};

int main(){
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> topK = sol.topKFrequent(nums, k);
    for (int num : topK) {
        printf("%d ", num);
    }
    return 0;
}

//another solution can be implemented using a min-heap (priority queue) to keep track of the top k elements based on their frequency. Here's how you can do it:

//here is the implementation not using PQ but it is similar to the bucket sort approach, but it uses a vector of pairs to store the frequency and the corresponding number, and then sorts this vector to find the top k elements.

// vector<pair<int, int>> freq_vec(ct.begin(), ct.end());

//     //  Sort manually using a lambda comparator (descending by frequency)
//     sort(freq_vec.begin(), freq_vec.end(), 
//      [](const pair<int, int>& a, const pair<int, int>& b
//     ) {
//         return a.second > b.second; 
//     });

//     //  Extract the top k elements
//     vector<int> result;
//     for(int i = 0; i < k; i++) {
//         result.push_back(freq_vec[i].first);
//     }

//     return result;