#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr ={1,2,3,4};
    int sz= arr.size();
    // vector<int>ans;  ye aise initialize kara hai tbhi product variable bnana pda hai wrna directly ans ko hi multiply kar skte the
//     for(int i=0; i<sz; i++){
//         int product=1;
//         for(int j=0; j<sz; j++){   //this is brute force
//             if(i!=j){
//                 product*=arr[j];
//             }
//         }
//         ans.push_back(product);
//     }

//    for(int val:ans){
//     cout<<val<<" ";
//    }
vector<int>ans(sz,1);    // aise initialize karna hota hai

for(int i=1; i<sz; i++){
    ans[i]= ans[i-1]*arr[i-1];      //calculated the prefix like at 1st index it is 1 ,1,2,6
}

int suffix =1;
for(int i=sz-2; i>=0; i--){
suffix*=arr[i+1];                   //calculates the suffix and multiplies into ans 24,12,4,1 this the sequence 
ans[i]*=suffix;                     // here we get 24,12,8,6 that's it

}

for(int val:ans){
    cout<<val<<" ";
}


}