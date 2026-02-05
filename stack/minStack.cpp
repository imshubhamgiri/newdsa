#include <iostream>
#include <stack>
#include <vector>
#include <stdexcept>
using namespace std;

/**
 * MinStack: A stack that supports push, pop, top, and retrieving 
 * the minimum element in constant time.
 */
class MinStack {
private:
    // Main stack to store the elements
    std::stack<int> dataStack;
    // Auxiliary stack to store the minimums
    std::stack<int> minStack;

public:
    stack<long long int> s;
    long long int minval;
    MinStack() {
        // Constructor logic if needed
    }

    void push(int val) {
        // TODO: Implement push operation
        if(s.empty()){
            s.push(val);
            minval=val;
        }else{
            if(val<minval){
                s.push((long long)2*val-minval);
                minval=val;
            }else{
                s.push(val);
            }
        }
    }

    void pop() {
        // TODO: Implement pop operation
        if(s.top()<minval){
            minval=2*minval-s.top();
        }
        s.pop();
    }

    int top() {
        // TODO: Implement top operation
        if(s.top()<minval){
            return minval;
        }else{
            return s.top();
        }
    }

    int getMin() {
        // TODO: Implement getMin operation
        return minval;
    }
};

/**
 * Main function for testing the MinStack implementation
 */
int main() {
    MinStack* obj = new MinStack();
    
    cout << "Test Case 1: Basic push and getMin" << endl;
    obj->push(10);
    cout << "Pushed 10, Min: " << obj->getMin() << " (Expected: 10)" << endl;
    
    cout << "\nTest Case 2: Push multiple elements" << endl;
    obj->push(20);
    cout << "Pushed 20, Min: " << obj->getMin() << " (Expected: 10)" << endl;
    obj->push(5);
    cout << "Pushed 5, Min: " << obj->getMin() << " (Expected: 5)" << endl;
    
    cout << "\nTest Case 3: Top element and Min" << endl;
    cout << "Top: " << obj->top() << " (Expected: 5)" << endl;
    cout << "Min: " << obj->getMin() << " (Expected: 5)" << endl;
    
    cout << "\nTest Case 4: Pop operations" << endl;
    obj->pop();
    cout << "After pop, Top: " << obj->top() << " (Expected: 20)" << endl;
    cout << "After pop, Min: " << obj->getMin() << " (Expected: 10)" << endl;
    
    cout << "\nTest Case 5: Push smaller element than min" << endl;
    obj->push(3);
    cout << "Pushed 3, Top: " << obj->top() << " (Expected: 3)" << endl;
    cout << "Pushed 3, Min: " << obj->getMin() << " (Expected: 3)" << endl;
    
    cout << "\nTest Case 6: Pop the minimum" << endl;
    obj->pop();
    cout << "After pop, Min: " << obj->getMin() << " (Expected: 10)" << endl;
    cout << "After pop, Top: " << obj->top() << " (Expected: 20)" << endl;
    
    cout << "\nTest Case 7: Negative numbers" << endl;
    obj->push(-5);
    cout << "Pushed -5, Min: " << obj->getMin() << " (Expected: -5)" << endl;
    
    cout << "\nTest Case 8: Pop all and verify" << endl;
    obj->pop();
    cout << "After pop, Min: " << obj->getMin() << " (Expected: 10)" << endl;
    obj->pop();
    cout << "After pop, Min: " << obj->getMin() << " (Expected: 10)" << endl;
    
    delete obj;
    cout << "\n✓ All test cases completed!" << endl;
    return 0;
}
