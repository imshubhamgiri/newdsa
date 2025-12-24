#include <iostream>
#include <string>
#include <vector>
using namespace std;    
// Function to compress the string
void stringcompress(vector<char>& chars) {
    int n = chars.size();
    int idx=0;
    for(int i=0; i<n; ){
        int c= chars[i];
        int count=0;
        while(i<n && c==chars[i]){
            count++;
            i++;
        }
        chars[idx++]=c;
        if(count>1){
            string cnt=to_string(count);
            for(char d:cnt){
                chars[idx++]=d;
            }
        }
    }
    chars.resize(idx);
}
int main() {
   vector<char> chars = {'a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c', 'a', 'a', 'a'};
   stringcompress(chars);
   for(char c: chars){
       cout<<c<<" ";
   }
   return 0;
}