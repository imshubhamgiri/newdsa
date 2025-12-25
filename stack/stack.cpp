#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

// class Stack{
// // vector<int>v;
// list<int>ll;
// public:

//     void push(int val){
//         // v.push_back(val);
//         ll.push_front(val);
//     }

//     void pop (){
//         // v.pop_back();
//         ll.pop_front();
//     }

//     int top(){
//         // return v[v.size()-1];
//         return ll.front();
//     }

//     bool empty(){
//         return ll.size() == 0;
//     }

// };

int main(){
    cout << "Stack implementation file" << endl;
    // Stack st;
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    // if(st.empty()){
    //     cout << "Stack is empty" << endl;
    //     return 0;
    // }
    // cout << "Top element: " << st.top() << endl;
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    return 0;

}