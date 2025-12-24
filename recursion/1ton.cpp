#include<iostream>
using namespace std;

void printn(int n)
{
    if(n==1)
    {
        cout<<n<<" ";
        return;
    }
    else
    {
        printn(n-1);
        cout<<n<<" ";
    }
}
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
   printn(n);
    return 0;
}