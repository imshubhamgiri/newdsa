#include<iostream>
using namespace std;
#include<queue>
class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{

    public:
    Node* qFront;
    Node* tail;
    Queue(){
        qFront = NULL;
        tail = NULL;
    }
    void pop(){
        if(qFront == NULL){
            return;
        }
        Node* temp = qFront;
        qFront = qFront->next;
        if(qFront == NULL){
            tail = NULL;
        }
        delete temp;
    }
    bool empty(){
        return qFront == NULL;
    }
    int front(){
        if(qFront == NULL){
            throw runtime_error("Queue is empty");
        }
        return qFront->data;
    }
    void push(int val){
        Node* newNode = new Node(val);
        if(tail == NULL){
            qFront = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
};

int main(){
    cout << "Queue implementation file" << endl;
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    cout<<q.front()<<endl;  // This will throw an exception
    return 0;
}