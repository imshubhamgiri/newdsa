#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool canDefuseBomb(vector<int>& code, int k) {
        int n = code.size();
        vector<int> prefixSum(n + 1, 0);

        // Calculate prefix sums
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + code[i];
        }

        // Check each subarray of length k
        for (int i = 0; i <= n - k; ++i) {
            int sum = prefixSum[i + k] - prefixSum[i];
            if (sum == 0) {
                return true; // Found a subarray with sum zero
            }
        }

        return false; // No subarray with sum zero found
    }

    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        
        // Base Case
        if (k == 0) return res;
        
        // Define the initial window pointers for index 0
        int l = (k > 0) ? 1 : n + k;
        int r = (k > 0) ? k : n - 1;
        
        int current_sum = 0;
        // Calculate the sum of the very first window
        for (int i = l; i <= r; i++) {
            current_sum += code[i];
        }
        
        // Slide the window for each element in the array
        for (int i = 0; i < n; i++) {
            res[i] = current_sum;
            
            // Remove the outgoing element from the sum
            current_sum -= code[l % n];
            // Move both pointers forward
            l++;
            r++;
            // Add the incoming element to the sum
            current_sum += code[r % n];
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> code = {1, -1, 2, -2, 3, -3};
    int k = 4;

    if (sol.canDefuseBomb(code, k)) {
        cout << "Bomb can be defused!" << endl;
    } else {
        cout << "Bomb cannot be defused." << endl;
    }

    code = {5, 7, 1, 4};
    k = 3;

    cout << "Decrypted code: ";
    for (int val : sol.decrypt(code, k)) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


/*
    This is a simple implementation of the bomb defusal problem using a sliding window approach.
    The 'canDefuseBomb' function checks if there exists a subarray of length k with a sum of zero.
    The 'decrypt' function decrypts the code based on the value of k.


    //Brute Force Approach
    int n = code.size();
    vector<int> res(n, 0); // Use a new array to avoid overwriting original data

   for (int i = 0; i < n; i++) {
       if (k > 0) {
           int sum = 0;
           // Look forward k times starting from i + 1
           for (int j = i + 1; j <= i + k; j++) {
               sum += code[j % n]; 
           }
           res[i] = sum;
       } 
       else if (k < 0) {
           int sum = 0;
           // Look backward |k| times starting from i - 1
           for (int j = i - 1; j >= i - abs(k); j--) {
               // (j % n + n) % n handles negative wrapping cleanly in C++
               sum += code[(j % n + n) % n];
           }
           res[i] = sum;
       } 
       else {
           res[i] = 0; // k == 0 case
       }
   }

   return res;
*/