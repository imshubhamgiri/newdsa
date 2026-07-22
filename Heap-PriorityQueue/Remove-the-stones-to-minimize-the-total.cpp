#include <iostream>
#include <vector>
#include <queue>   // Required for std::priority_queue
#include <cmath>   // Required for std::floor
#include <numeric> // Required if using std::accumulate (optional)

using namespace std;

class Solution {
public: 
    int minStoneSum(vector<int>& piles, int k) {
        // Max-heap to always process the largest pile first
        priority_queue<int> q;
        int sum = 0;
        
        for(int p : piles){
            sum += p;
            q.push(p);
        }

        while(k != 0 && !q.empty()){
            int d = q.top();
            q.pop();
            
            // Calculate floor(d / 2) using integer division
            int remove = d / 2; 
            sum -= remove;
            d -= remove;
            
            q.push(d);
            k--;
        }

        return sum;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    vector<int> piles1 = {5, 4, 9};
    int k1 = 2;
    cout << "Minimum remaining stones (Test 1): " << solver.minStoneSum(piles1, k1) << " (Expected: 12)" << endl;

    // Test Case 2
    vector<int> piles2 = {4, 3, 6, 7};
    int k2 = 3;
    cout << "Minimum remaining stones (Test 2): " << solver.minStoneSum(piles2, k2) << " (Expected: 12)" << endl;

    return 0;
}
