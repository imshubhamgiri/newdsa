#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Sort intervals by their start times
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for (const auto& interval : intervals) {
            // If ans is empty or current interval does not overlap with the last one in ans
            if(ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            } else {
                // Merge the current interval with the last one in ans
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};


int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = solution.merge(intervals);

    cout << "Merged Intervals: ";
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}