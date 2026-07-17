#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;


//LC-438 Find All Anagrams in a String
class Solution {
    public:
    //Approach: Sliding Window -> The question is to find all the start indices of p's anagrams in s. An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once. We will use a sliding window approach to solve this problem. We will maintain a counter array of size 26 to keep track of the frequency of characters in the pattern string p. We will then slide a window of size equal to the length of p over the text string s. For each character in the window, we will decrement its count in the counter array. When the window size matches the length of p, we will check if all counts in the counter array are zero, which indicates that we have found an anagram. If so, we will record the starting index of the window. After checking, we will increment the count of the character that is moving out of the window and move the left pointer forward. This process continues until we have traversed the entire string s.
        bool allzero(vector<int>& counter){
            for(int & i : counter){
                if(i!=0){
                    return false;
                }
            }
            return true;
        }
        vector<int> findAnagrams(string txt, string pat) {
             int n = txt.size();
             vector<int> ans;
            
            vector<int> counter(26 ,0);
            
            for(int i=0; i<pat.length(); i++){
                char ch = pat[i];
                
                counter[ch-'a']++;
            }
            
            
            
            int i=0, j =0;
            int result =0;
            while(j<n){
            
            counter[txt[j]-'a']--;    
                
                if(j-i == pat.size()-1){
                
                    if(allzero(counter)){
                       ans.push_back(i);
                    }
                  counter[txt[i]-'a']++; 
                  i++;
                }
                
                j++;
            
            }
            
            return ans;
        }
    };

int main(){
    Solution sol;
    vector<int> result = sol.findAnagrams("cbaebabacd", "abc");
    for(int i : result){
        cout << i << " ";
    }
    return 0;
}