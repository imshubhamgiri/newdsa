#include<iostream>
using namespace std;
int main(){
    int a = 20;
    int b= 28;
    int lcm;
    int gcd;
    int prod = a*b;
    while(a!=0 && b!=0){
        if(a>=b){
            a=a%b;
        }
        else{
            b=b%a;
        }
        if(a==0){
            gcd=b;
        }
        else{
            gcd=a;
        }
    }
    lcm = prod/gcd;
   cout<<lcm<<endl;
   cout<<"there is no error"<<endl;
 }