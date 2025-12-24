#include<iostream>
#include<string>
using namespace std;
bool isfrqsame(int frq1[26], int frq2[26]){
        for (int i = 0; i < 26; i++)
        {
            if(frq1[i]!=frq2[i]) return false;
        }
        return true;
        
}
bool nextpermutation(string s1, string s2){

    int frq[26]={0};
    for(int i=0; i<s1.length(); i++){
        int idx= s1[i]-'a';
        frq[idx]++;
    }

    for(int i=0;i<s2.length(); i++){
        int frq2[26]={0};
        int idx=i, windsize=0;
        while(windsize<s1.length()&& idx<s2.length()){
            frq2[s2[idx]-'a']++;
            windsize++,idx++;
        } 
        
       
        if(isfrqsame(frq,frq2)){
            return true;
        } 
        
    }
   return false;
}
int main(){
    string s1={"ab"};
    string s2={"eidboabo"};
if(nextpermutation(s1,s2)){
    cout<<"yes it exits"<<endl;
}
    else{
        cout<<"doesn't exits";
    }
}