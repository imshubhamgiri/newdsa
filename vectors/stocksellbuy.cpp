#include<iostream>
using namespace std;
int main(){
    int arr[]= {7,1,5,3,6,4};
    int sz= sizeof(arr)/4;
    int  mp =0 , bestbuy = arr[0];
    for(int i=1; i<sz; i++){
        if(arr[i]>bestbuy){
            mp = max(mp , arr[i]-bestbuy);
        }
        bestbuy=min(bestbuy,arr[i]);
    }
    cout<<mp<<endl;
}