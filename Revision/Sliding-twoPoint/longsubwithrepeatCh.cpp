#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

class Solution{
//This is a sliding window problem, we will use two pointers to represent the current substring, and a set to store the characters in the current substring. We will move the right pointer to expand the window until we find a duplicate character, then we will move the left pointer to shrink the window until we remove the duplicate character from the set. We will keep track of the maximum length of the substring without repeating characters.
public:
    int lengthOfLongestSubstring(string s) {

        //Hash-set to store the characters which are currently in the sliding window
        unordered_set<char> w;
        int n = s.size();
        int left =0; 
        int right =0;
        int maxc = 0;
        while(right<n){  //Here Time complexity is O(2n) = O(n) because in the worst case, each character will be visited twice by the left and right pointers.
            while(w.find(s[right])!=w.end()){    // if the character is already in the set, we need to move the left pointer
                w.erase(s[left]);
                left++;
            }
            w.insert(s[right]);
            maxc = max(maxc , right - left +1);
            right++;
        }
        return maxc;
    }


};

int main(){
    Solution s;
    string str = "abcabcbb";
    cout<<s.lengthOfLongestSubstring(str)<<endl;  
    return 0;
}

