#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
    public:
        string frequencySort(string s) {
            int n = s.length();
            unordered_map<char,int> mp;
            for(char ch: s){
                mp[ch]++;
            }
            vector<vector<char>>bucket(n+1);
            string result;
    
            for(auto val: mp){
                char ch = val.first;
                int frq = val.second;
                bucket[frq].push_back(ch);
            }
    
            for(int i=n; i>=0; i--){
                for(char ch: bucket[i]){
                   result.append(i,ch);
                }
            }
    
            return result;
        }
    };


int main(){
    Solution s;
    string str = "tree";

    cout<<s.frequencySort(str);
    cout<<endl;
}