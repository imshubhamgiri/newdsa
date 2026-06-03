//Write boilder plate class and full implementation of main function

#include<iostream>
#include<stack>
using namespace std;

// class MinStack {
//     //We will use two stacks, one to store the actual values and another to store the minimum values. Whenever we push a new value onto the main stack, we will compare it with the current minimum value (the top of the min stack) and push the smaller of the two onto the min stack. When we pop a value from the main stack, we will also pop from the min stack to ensure that it always has the current minimum value at its top.

// public:
//     stack<int> mainStack; // Stack to store the actual values
//     stack<int> minStack;  // Stack to store the minimum values

//     void push(int x) {
//         mainStack.push(x);
//         if (minStack.empty() || x <= minStack.top()) {
//             minStack.push(x);
//         }
//     }

//     void pop() {
//         if (mainStack.top() == minStack.top()) {
//             minStack.pop();
//         }
//         mainStack.pop();
//     }

//     int top() {
//         return mainStack.top();
//     }

//     int getMin() {
//         return minStack.top();
//     }
// };  

class MinStack2 {
    public:
       //using Pair to store the value and the minimum value at that point in the stack
       stack<pair<int, int>> st;
    
        //easiet solution but it uses extra space for the minimum values, we can optimize it by only storing the minimum values when they change, but this solution is straightforward and easy to understand. SC(2n) because we are storing both the value and the minimum value for each element in the stack.
    
        void push(int x) {
            if (st.empty()) {
                st.push({x, x});
            } else {
                int currentMin = st.top().second;
                st.push({x, min(x, currentMin)});
            }
        }
    
        void pop() {
            st.pop();
        }
    
        int top() {
            return st.top().first;
        }
    
        int getMin() {
            return st.top().second;
        }
    };
    

    class OptimalMinStack{
    //This is the most optimized solution which uses only one stack and a variable to keep track of the minimum value, but it is a bit tricky to implement and understand. The idea is to store the difference between the current value and the minimum value in the stack. When we push a new value onto the stack, we will compare it with the current minimum value and push the difference onto the stack. If the new value is smaller than the current minimum value, we will update the minimum value to the new value. When we pop a value from the stack, we will check if it is negative, if it is negative then it means that it is a minimum value and we will update the minimum value to the previous minimum value by adding the popped value to it. This way we can keep track of the minimum values without using extra space for them in another stack.
        public:
        stack<int> st;
        int minVal;
         OptimalMinStack() {
            // Initialize minVal to the maximum integer value
        }
    
        void push(int val){
            if(st.empty()){
                st.push(val);
                minVal = val;
            }else{
                if(val>minVal){
                    st.push(val);
                }else{
                   int dig = 2 * val - minVal;
                    st.push(dig);
                    minVal = val;
                }
            }
        }
    
        void pop(){
         int x = st.top();
         st.pop();
         if(x<minVal){
            minVal = 2 * minVal - x;
         }
        }
    
        int top(){
         int x = st.top();
         if(x<minVal){
            return minVal;
         }
         return x;
        }
    
        int getMin(){
            return minVal;
        }
    
    };
int main() {
    // MinStack2 minStack;
    OptimalMinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum: " << minStack.getMin() << endl; // Returns -3
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;       // Returns 0
    cout << "Minimum: " << minStack.getMin() << endl; // Returns -2         
    return 0;
}


// class MinStack {
//     private:
//         vector<vector<int>>st;  a solution using vector of pairs, we will store the value and the minimum value at that point in the stack. Whenever we push a new value onto the stack, we will compare it with the current minimum value (the second element of the last pair in the vector) and push a new pair with the value and the smaller of the two onto the vector. When we pop a value from the stack, we will simply pop the last pair from the vector to ensure that it always has the current minimum value at its last element. This solution is straightforward and easy to understand, but it uses extra space for the minimum values. SC(2n) because we are storing both the value and the minimum value for each element in the stack. (Got this solution from solution Tab of LeetCode, I have implemented it using stack of pairs in the above code, but this is also a valid solution using vector of pairs.)
//     public:
//         MinStack() { 
    
//         }
        
//         void push(int val) {
//             int min_val = getMin();
//             if (st.empty() || min_val > val) {
//                 min_val = val;
//             }
//             st.push_back({val, min_val});
//         }
        
//         void pop() {
//             st.pop_back();
//         }
        
//         int top() {
//             return st.empty()?-1 : st.back()[0];
//         }
        
//         int getMin() {
//           return st.empty() ? -1 : st.back()[1];
//         }
//     };


//there is also the most optimized solution which uses only one stack and a variable to keep track of the minimum value, but it is a bit tricky to implement and understand, so I have implemented the above two solutions which are more straightforward and easy to understand.
