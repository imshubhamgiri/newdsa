#include<iostream>
using namespace std;
int main(){
    int n= 1;
    int org = n;
    int sum=0;
    while(n>0){
        int last= n%10;        //yha orginal number hi zero ho jata hai
        int ans = last;
        ans*= ans*ans;
        sum+= ans;
        n= n/10;
    }

    if(org==sum){
        cout<<"armstrong";
    }
    else{
        cout<<"not armstrong";
        
    }
}