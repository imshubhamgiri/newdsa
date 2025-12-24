#include<iostream>
#include<vector>
using namespace std;
int main(){
   vector< int> arr={-1,0,3,4,5,9,12};
   int target =5 ;
    int left=0; int right= arr.size()-1;
    while(left<=right){
        int mid = (left + right)/2;
        if(arr[mid]==target){
            cout<<mid<<","<<arr[mid]<<endl;
            break;
            
        }
        else if(arr[mid]>target){
            right= mid-1;
        }
        else{
            left=mid+1;
        }

    }

   


}