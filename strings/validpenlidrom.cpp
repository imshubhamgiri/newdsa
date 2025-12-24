#include<iostream>  
#include<string>
#include<algorithm>
using namespace std;
bool ispelindrom(string s){
    if(s==" ") return true;
    int st=0, end= s.length()-1;
    while(st<end){
        if (!((s[st] >= 'a' && s[st] <= 'z') || 
      (s[st] >= 'A' && s[st] <= 'Z') || 
      (s[st] >= '0' && s[st] <= '9'))) {
    st++;    // skip invalid start character
    continue;
}
    if (!((s[end] >= 'a' && s[end] <= 'z') || 
      (s[end] >= 'A' && s[end] <= 'Z') || 
      (s[end] >= '0' && s[end] <= '9'))) {
    end--;   // skip invalid end character
    continue;
}

//while(st<end && !isalnum(s[st])){st++,continue;}
//while(st<end && !isalnum(s[end])){end--,continue;} same approach with c++ stL support

        if(tolower(s[st])!=tolower(s[end])){
            return false;
        }
        st++,end--;
        
    }
}
int main(){
    string s={" "};
    if(ispelindrom(s)){
        cout<<"yes it is a pelindrom string";
    }
    else{
        cout<<"invalid not a palindrom";
    }
}