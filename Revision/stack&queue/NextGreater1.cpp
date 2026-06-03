#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        unordered_map<int , int> mp;    //Unordered map to track greater element for each element
        stack<int>s;  // stack to store elements until there next greater is found;

        for(int val:nums2){
            //Here instaed of if condition we used while loop why? because if we use if condition then we will only pop one element from the stack and we will not get the right answer for the rest of the elements in the stack which are less than the current element but greater than the popped element. so to get the right answer for all the elements in the stack we need to use while loop to pop all the elements which are less than the current element and update their next greater element in the map.
            while(!s.empty() && s.top()<val){  
                mp[s.top()] = val;
                s.pop();
            }
            s.push(val);
        }
        vector<int>result;
        for(int val:nums1){
            int ans = mp[val]? mp[val] : -1;  
            result.push_back(ans);
        }


        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {4,1,2};   //in case of this if else condition then according to current code we will get right answer even if we use if else
    vector<int> nums2 = {1,3,4,2};
    vector<int> result = s.nextGreaterElement(nums1, nums2);
    vector<int>nums3 = {1,3,5,2,4};
    vector<int> nums4 = {6,5,4,3,2,1,7}; //But here the thing will go wrong as the stack will only pop 1 and the loop will finsh and the rest of the elements will be left in the stack and we will not get the right answer for 5,4,3,2 as they are all less than 6 but greater than 1 that is the reason we used while loop instead of if else condition
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl; 
}