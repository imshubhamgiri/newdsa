#include<iostream>
#include<unordered_map> 
using namespace std;
int main(){
//     int n, target;
//     cin >> n >> target;
//     int arr[n];
//     for(int i = 0; i < n; i++)
//         cin >> arr[i];
//     unordered_map<int, int> map;
//     for(int i = 0; i < n; i++)
//     {
//         int complement = target - arr[i];
//         if(map.find(complement) != map.end())
//         {
//             cout << map[complement] << " " << i << endl;
//             return 0;
//         }
//         map[arr[i]] = i;
//     }
//     cout << "No two sum solution" << endl;
//     return 0;

    int arr [] = {5,2,11,7,15};
    int target=9;
    int n= sizeof(arr)/sizeof(arr[0]);
    unordered_map<int,int> map;
    for(int i=0; i<n; i++){
        int first = arr[i];
        int second = target - first;
        if(map.find(second) != map.end()){
            cout<<map[second]<<" "<<i<<endl;
            return 0;
        }
        map[first] = i;
    }
}