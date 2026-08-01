#include<iostream>
#include<vector>
using namespace std;

class Solution{
//Approach- Optimised Brute Force
public:
    int countOfSubstring(string s){
        int n=s.size();
        int count =0;
        //Optimised Brute Force solution
        for(int i=0;i<n;i++){
            bool hasA=false, hasB=false, hasC=false;
            for(int j=i;j<n;j++){
                if(s[j]=='a') hasA=true;
                else if(s[j]=='b') hasB=true;
                else if(s[j]=='c') hasC=true;

                if(hasA && hasB && hasC){
                    count += (n-j);
                    break;
                }
            }
        }
        return count;
    }

};

int main(){

    Solution sol;
    string s = "abcabc";
    int count = sol.countOfSubstring(s);
    cout << "Count of substrings containing all three characters: " << count << endl;
}