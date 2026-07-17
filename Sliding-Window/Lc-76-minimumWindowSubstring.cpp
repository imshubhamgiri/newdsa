#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;


class Solution{
    public:
    //Approach: Sliding Window -> So the question is to find the minimum window substring in s which will contain all the characters in t including duplicates. Now t can have duplicates so we will use a map to store the count of each character in t. Now we will use two pointers i and j to maintain a window in s. We will keep expanding the window by moving j and when we have all the characters of t in the current window, we will try to shrink the window by moving i. We will keep track of the minimum window size and its starting index. Finally, we will return the substring from s starting at the recorded index with the recorded minimum length.

    //Simple bhasa me duplicate hai to count map me store karenge aur fir j aage badhega ek ek krke visit karega elements ko aur inka frequency -- krega to isse kya hoga ki jaise jiski freq phle se 1 hai jaise ki hamne jo value store ki map me wo agar mile to requiredcount kam krenge aur jab ye zero ho jayega mane ki hmko window mil gaya. ab iss window ko minimize karne ke liye i ko aage badhaenge aur fir se check krenge ki requiredcount zero hai ya nahi. Agar zero hai to fir se window ko minimize krenge aur agar nahi hai to fir se j ko aage badhaenge. Ye process tab tak chalega jab tak j n ke equal na ho jaye. Finally, agar minwindow INT_MAX hai to return "" otherwise return s.substr(start_i , minWindow). Aur hnn important point ye hai ki map me jo bhi character ka count hai wo negative bhi ho sakta hai to isliye requiredcount ko check karte waqt ye dekhenge ki mp[leftChar]>0 hai ya nahi. Agar hai to requiredcount++ krenge. last baat ki ye guranteeed hai ki agar t ka character s me hai to requiredcount zero ho hi jayega. aur whi window milega jo sabse minimum hoga. Eg- pehli baar me window milega "ADOBEC" aur fir i ko aage badhaenge to "DOBECODEBA" ye window milega isko shrink karenge to "CODEBA"(dry run krna) and then "BANC" ye window milega aur ye minimum hoga.
    string minWindow(string s , string t){
        int n = s.size();
        int m = t.size();
        if(n < m) return "";
        unordered_map<char, int> mp;
        for(char c : t) mp[c]++;

        int requiredCount = m;
        int i=0 , j =0;
        int minWindow = INT_MAX;
        int start_i =0;

        while(j<n){
          char ch = s[j];  
        
          if(mp[ch]>0){
            requiredCount--;
          }

          mp[ch]--;

          while(requiredCount==0){
            int currWindow = j-i +1;

            if(minWindow>currWindow){
                minWindow = currWindow;
                start_i = i;
            }

            char leftChar = s[i];
            mp[leftChar]++;

            if(mp[leftChar]>0){
                requiredCount++;
            }
            i++;
          }
          j++;
        }
        return minWindow == INT_MAX ? "" : s.substr(start_i , minWindow);
    }
};

int main(){
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sol.minWindow(s, t) << endl;
}