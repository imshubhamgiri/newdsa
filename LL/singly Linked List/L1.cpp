//generat c++ boilerplate 

#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
int data;
Node* next;
Node(int val) {
    data = val;
    next = nullptr;
}

};  
class List{
    Node* head;
    Node* tail;

    List(){
        head = tail = NULL;
    }

};
int main() {
  

}