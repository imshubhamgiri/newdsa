#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isvalid(vector<int>& nums, int mid, int student) {
    int count = 1;
    int sum = 0;
    for (int val : nums) {
        if (val > mid) return false;  // a single book larger than mid → impossible
        if (sum + val <= mid) {
            sum += val;
        } else {
            count++;
            sum = val;
        }
    }
    return count <= student;
}

int allocatepage(vector<int> &nums, int size, int m) {
    int st = *max_element(nums.begin(), nums.end());
    int end = size;
    int ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (isvalid(nums, mid, m)) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {40,30,10,20};
    int size = 0;
    int m = 2;

    for (int val : nums) {
        size += val;
    }

    cout << allocatepage(nums, size, m) << endl;
}
