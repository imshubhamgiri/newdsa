#include<bits/stdc++.h>
using namespace std;
//This question is similar to Koko Eating Bananas. We have to find the smallest divisor such that the sum of the division of each element in the array by the divisor is less than or equal to the threshold. We can use binary search to find the smallest divisor. The search space for the divisor is from 1 to the maximum element in the array. We can use a helper function to check if a given divisor is possible or not. If it is possible, we can move the end of the search space to mid, otherwise we can move the start of the search space to mid + 1. Finally, we will return the start of the search space as the answer.
class Solution {
    public:
        bool isPossible(vector<int>& nums , int mid , int thres){
          int divisor =0;
            for(int i=0; i<nums.size(); i++){
                divisor+= (nums[i]+ mid -1)/mid;
                if(divisor>thres) return false;
            }
            return divisor<=thres;
        }
        int smallestDivisor(vector<int>& nums, int threshold) {
    
            int s =1 , e = *max_element(nums.begin(), nums.end());
            while(s<e){
                int mid = s+(e-s)/2;
                if(isPossible(nums , mid , threshold)){
                    e = mid;
                }else{
                    s = mid+1;
                }
            }
            return s;
        }
    };
//Leetcode link : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
int main(){
    Solution s;
    vector<int> nums = {1,2,5,9};
    int thres = 6;
    cout<<s.smallestDivisor(nums , thres)<<endl;
    return 0;
}