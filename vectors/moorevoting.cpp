 #include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums= {3,2,3,2,5,3,2,4,2,5,5,5,5,5,5};
  int candidate = nums[0];
  int count=1;
  for(int i=1;i<nums.size(); i++){
    if(candidate==nums[i]){
        count++;
    }
    else if(candidate!=nums[i]){
        count--;
    }
   if(count==0){
        candidate=nums[i];
        count=1;
    }
  }
//  if(count >= nums.size()/2) // galat hai bhai ye count to hmesh kam rahega size/2 se dry run karke dekh lena
//     cout << candidate << endl;
// else 
//     cout << "No majority element" << endl;
// ek dusra loop me candidate ki frequency le lo
int freq =0;
for(int val:nums){
 if(candidate==val){
    freq++;
 }
}
if(freq >= nums.size()/2){
     cout << candidate << endl;
}
 else 
    cout << "No majority element" << endl;


}