#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main (){
    vector<int>container ={1,8,6,2,5,4,8,3,7};
    int mw =0; 
    int left=0, right = container.size()-1;
    while(left<right){
        int base= right -left;
        int height= min (container[left],container[right]);
        int area = base*height;
        mw =max(mw,area);
        // if(container[left]<container[right]){
        //     left++;
        // }
        // else right++;

    container[left]<container[right]? left++ : right--;
    }
    cout<<mw<<endl;
   
}