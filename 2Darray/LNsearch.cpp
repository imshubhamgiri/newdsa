#include<iostream>
using namespace std;
int main()
{   int n;
    cout<<"Enter the row of array: ";
    cin>>n;
    int m;
    cout<<"Enter the column of array: ";
    cin>>m;
   int arr[n][m];
   cout<<"Enter the elements of array: ";
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           cin>>arr[i][j];
       }
   }
   int key;
   cout<<"Enter the element to be searched: ";
   cin>>key;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(arr[i][j]==key)
           {
               cout<<"Element found at ("<<i<<","<<j<<")"<<endl;
               return 0;
           }
       }
   }
   cout<<"Element not found"<<endl;
   return 0;
}

