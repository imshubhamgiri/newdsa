#include<iostream>
using namespace std;
int main(){
    int a = 20;
    int b= 28;
    int sum;
    while(a!=0 && b!=0){
        if(a>=b){
            a=a-b;
        }
        else{
            b=b-a;
        }
        if(a==0){
            sum=b;
        }
        else{
            sum=a;
        }
    }

   cout<<sum<<endl;
   cout<<"there is error"<<endl;
}