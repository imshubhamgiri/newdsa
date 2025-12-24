#include<iostream>
#include<vector>
using namespace std;
int reverservector(vector<int>&nums){
    int size= nums.size();
    int left=0, right=size-1;
    while(left<right){
        swap(nums[left],nums[right]);
        left++;
        right--;
    }


}
int main(){
 
   vector<int> nums ={3,4,2,7,8};
   reverservector(nums);
   for(int val: nums){
    cout<<val<<" ";
  }
cout<<endl;
}