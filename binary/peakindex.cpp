#include<iostream>
#include<vector>
using namespace std;
int peakindex(vector<int>&arr, int size){
    int st=0, end=size-1;
    while(st<=end){
        int mid= st+(end-st)/2;
        if(mid==0 && arr[mid]>arr[mid+1]) return arr[mid];
        if(mid==size-1 && arr[mid]>arr[mid-1]) return arr[ mid];
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            return arr[mid];
        }
        else if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1]){
            end = mid-1;
        }
        else{
            st=mid+1;
        }
    }

}
int main(){
    vector<int> arr={0,2,1,0};
    int size= arr.size();
    cout<<peakindex(arr,size)<<endl;
}

//one more solution
// while(st<end){
//     if(arr[mid]>arr[mid]+1){
//         end=mid;
//     }
//     else{
//         st=mid+1;
//     }
//     return nums[st];
// }