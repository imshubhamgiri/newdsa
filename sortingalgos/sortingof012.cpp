#include<iostream>
using namespace std;
int main(){
    int arr[]={0,0,1,2,0,1,0,2,2,0,1,1};
    int size= sizeof(arr)/sizeof(int);
    // int count0=0, count1=0, count2=0;
    // for(int i=0; i<size; i++){
    //   if(arr[i]==0) count0++;
    //   if(arr[i]==1) count1++;
    //   if(arr[i]==2) count2++;
    // }
    // int idx=0;

    // for(int i=0; i<count0; i++){
    //     arr[idx++]=0;
    // }
    // for(int i=0; i<count1; i++){
    //     arr[idx++]=1;
    // }
    // for(int i=0; i<count2; i++){
    //     arr[idx++]=2;
    // }

    // for(int i=0; i<size; i++){
    //     cout<<arr[i]<<" ";                        //brute force for sorting 0s 1s and 2s soritng not a better approach 
    // }
    
    int mid=0 , high = size -1 , low = 0;
    
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++,low++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";                        //brute force for sorting 0s 1s and 2s soritng not a better approach 
    }
}