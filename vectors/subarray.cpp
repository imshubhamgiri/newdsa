//kadane's algorithm

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    vector<int>vec={2,-3,5,6,-7,7};

    int maxsum=INT_MIN;
    int currentsum= 0;
    for(int i=0; i<vec.size(); i++){
        currentsum+=vec[i];
        maxsum= max(maxsum,currentsum);
        if(currentsum<0){
            currentsum=0;
        }
    }

//     for (int i = 0; i < vec.size(); i++) {
//     currentsum = max(vec[i], currentsum + vec[i]);  this will be used when every number will be zero
//     maxsum = max(maxsum, currentsum);
// // }
    cout<<maxsum;
}