#include<iostream>
#include<vector>
using namespace std;
void bn(vector<int>arr,int target,int s,int e){
    int mid=s+(e-s)/2;
    cout<<mid<<endl;
    if(s>e){
        cout<<"Element not found";
        return;
    }
    if(arr[mid]==target){
        cout<<"Element found at index "<<mid;
        return; 
    }
    else if(arr[mid]>target){
        e=mid-1;
        bn(arr,target,s,e);
    }
    else{
        s=mid+1;
        bn(arr,target,s,e);
    }   
}
int main(){
    vector<int>arr= {-1,2,5,9,12,15};
    int target = 9;
    int n=arr.size();
    int s=0, e=n-1;
    bn(arr,target,s,e);
}