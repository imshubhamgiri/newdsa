#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> nums= {3,2,4};
    sort(nums.begin(),nums.end());
    int target =6;
    int left=0, right=nums.size()-1;

    while(left<right){
      if(nums[left]+nums[right]>target){
            right--;
        }
        else if(nums[left]+nums[right]<target){
            left++;
        }
        else{
            cout<<left<<","<<right<<endl;
            cout<<"this two are the indices ";
          break;
           
        }
    }
}