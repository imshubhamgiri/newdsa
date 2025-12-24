#include<iostream>
#include<vector>
using namespace std;
int vecotr(vector<int>&nums,int target, int st, int end){
      while(st<=end){
        int mid = st+ (end-st)/2;
        if(target==nums[mid]) return mid;
        if(nums[st]<=nums[mid]){
            if(target>=nums[st] && target<=nums[mid]){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        else{
            if(target>=nums[mid] && nums[end]>=target){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
      } 
      return -1;  
}

int main(){
   vector< int> nums={8,9,10,11,0,1,2,3,4};
   int target =11  ;
    int left=0; int right= nums.size()-1;

   int ans= vecotr(nums,target,left,right);
   cout<<"and the expected index is "<<ans<<endl;


}