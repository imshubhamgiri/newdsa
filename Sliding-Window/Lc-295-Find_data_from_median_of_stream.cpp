#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class MedianFinder {

    //Approach: Using two heaps, one max heap for the left half of the numbers and one min heap for the right half of the numbers. The max heap will store the smaller half of the numbers, while the min heap will store the larger half. The median can be found by checking the sizes of the heaps and returning the appropriate value.
    public:
        priority_queue<int> left_maxHeap;
        priority_queue<int , vector<int> , greater<int>> right_minHeap;
    
        MedianFinder() {
            
        }
        
        void addNum(int num) {
            if(left_maxHeap.empty() || num < left_maxHeap.top()){
                left_maxHeap.push(num);
            }else{
                right_minHeap.push(num);
            }
    
            if(abs((int)left_maxHeap.size() - (int)right_minHeap.size()) > 1){
    
                 right_minHeap.push(left_maxHeap.top());
    
                 left_maxHeap.pop();
            }else if(left_maxHeap.size()<right_minHeap.size()){
    
                left_maxHeap.push(right_minHeap.top());
    
                right_minHeap.pop();
            }
        }
        
        double findMedian() {
            if(left_maxHeap.size() == right_minHeap.size()){
              return ( double)(right_minHeap.top() + left_maxHeap.top())/2;
    
            }
    
            return left_maxHeap.top();
        }
    };

    int main() {
        MedianFinder* obj = new MedianFinder();
        obj->addNum(1);
        obj->addNum(2);
        std::cout << obj->findMedian() << std::endl; // Output: 1.5
        obj->addNum(3);
        std::cout << obj->findMedian() << std::endl; // Output: 2
        return 0;
    }