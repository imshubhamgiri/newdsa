#include<iostream>
using namespace std;

int printarray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}
void insertion(int arr[], int size){

    for(int i=1; i<size; i++){
        int current = arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>current){
            arr[prev+1]=arr[prev]; 
            prev--;
        }
        arr[prev+1]=current;
    }
}
int main(){
    int arr[]={4,1,5,2,3};
    int size= sizeof(arr)/sizeof(int);

    insertion(arr,size);
    printarray(arr,size);
}