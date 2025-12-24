#include<iostream>
using namespace std;
int main(){
    int x=3 ,pow=3;

    int ans=1;
    while(pow>0){
     if(pow%2!=0){
            ans*=x;
        }
        pow=pow/2;
        x*=x;
    }
    cout<<ans<<endl;
}