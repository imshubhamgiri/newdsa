#include <iostream>
#include <stack>
#include <vector>
#include <stdexcept>
using namespace std;


//Approach: Greedy + Stack


//let's understand the problem what it want so we have to remove the duplicate letters from the string and return the smallest lexicographical order of the string after removing the duplicate letters. Now the approach is to use a stack to keep track of the characters in the string and a boolean array to keep track of the characters that have already been added to the stack. We will iterate through the string and for each character, we will check if it has already been added to the stack. If it has, we will skip it. If it hasn't, we will check if the current character is smaller than the top character of the stack and if the top character of the stack appears later in the string. If both conditions are true, we will pop the top character from the stack and mark it as not appeared. We will continue this process until we can no longer pop characters from the stack. Finally, we will add the current character to the stack and mark it as appeared. After iterating through the entire string, we will return the characters in the stack as a string.

class Solution {
    public:
        string removeDuplicateLetters(string s) {
            int n = s.size();
            vector<int> lastIdx(26);
            vector<bool> appeared(26 , false);
    
            for(int i=0; i<n; i++){
                char ch = s[i];
                int idx = ch - 'a';
                lastIdx[idx] = i;
            }
    
            string result; 
    
            for(int i=0; i<n; i++){
             char ch = s[i];
             int idx = ch - 'a';
             if(appeared[idx]) continue;
             while(result.length() > 0 && s[i] < result.back() && lastIdx[result.back() - 'a'] > i){
                appeared[result.back()- 'a'] = false;
                result.pop_back();
             }
    
             appeared[idx] = true;
             result+= ch;
    
            }
    
            return result;
    
        }
    };

    int main(){
        Solution sol;
        string s = "bcabc";

        string result = sol.removeDuplicateLetters(s);
        cout << result << endl;
        return 0;
    }