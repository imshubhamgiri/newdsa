#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool ispossible(vector<int> &nums , int maxallowdis,int cows){
    int lastcow= nums[0];
    int count=1;
    for(int i=1; i<nums.size();i++){
        if((nums[i]-lastcow)>=maxallowdis){
            count++;
            lastcow=nums[i];
        }
        if(cows==count){
            return true;
        }

    }
   return  false;
}

int aggresivecow(vector<int>&nums , int cows, int n){
    sort(nums.begin(),nums.end());
    int st = 1; 
    int end = nums[n-1]-nums[0];
   int ans=-1;
    while(st<=end){
        int mid= st+(end-st)/2;
        if(ispossible(nums,mid,cows)){
            st= mid+1;
            ans= mid;
        }
        else{
            end= mid-1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,8,4,9};
    int m = 3;
    int size= nums.size();
  cout<<  aggresivecow(nums,m,size);
}