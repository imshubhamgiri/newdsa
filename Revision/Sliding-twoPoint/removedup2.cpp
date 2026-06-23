#include<iostream>
#include<vector>
using namespace std;



class Solution{
public:
int removeDuplicates(vector<int>& nums) {
    vector<int>ans;    //Brute force approach is to use a vector to store the unique elements and then copy them back to the original vector. The time complexity of this approach is O(n) and the space complexity is O(n) as we are using an extra vector to store the unique elements.
    int freq =1;
    int prevElm=nums[0];
    ans.push_back(prevElm);
    for(int i=1; i<nums.size(); i++){
      if(prevElm == nums[i] && freq<2){
            freq++;
            ans.push_back(nums[i]);
        }else if(nums[i]!=prevElm){
            prevElm = nums[i];
            freq =1;
            ans.push_back(nums[i]);
       }
    }
   for(int i=0; i<ans.size(); i++){
     nums[i] = ans[i];
   }
   return ans.size();
}

int removeDuplicate2(vector<int>& nums){
        int k=2;
        int n = nums.size();
        if(n<=k) return n;

        //Optimised solution for removing duplicates from sorted array. The time complexity of this approach is O(n) and the space complexity is O(1) as we are not using any extra space to store the unique elements.

        for(int i=k; i<n; i++){   //here we start from i =2 and look at every index if does not match with the element at index k-2 then we can add it to the array and increment k. This way we are keeping track of the unique elements in the array and removing the duplicates. 
            if(nums[i]!=nums[k-2]){
                nums[k] = nums[i];
                k++;
            }
        }
        //Dry run on the array [1,1,1,2,2,3] and k=2. The first two elements are 1 and 1. The third element is 1 which is equal to nums[k-2] so we skip it. The fourth element is 2 which is not equal to nums[k-2] so we add it to the array and increment k. The fifth element is 2 which is equal to nums[k-2] so we skip it. The sixth element is 3 which is not equal to nums[k-2] so we add it to the array and increment k. The final array will be [1,1,2,3] and k=4.
}
};



int main(){

}