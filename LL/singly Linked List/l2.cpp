//C++ boillerplate code
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;
public:
    List() {
        head = tail = NULL;
    }
     
    void push_front(int val){
        Node* newNode = new Node(val);
        // Node newNode(val); //Static allocation data get deleted after function ends
        if(!head){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        // tail = newNode; // Update tail to the new node

    }
        void pop_front(){
        if(!head) return; // List is empty
        Node* temp = head;
        head = head->next;
        delete temp;
        if(!head) tail = NULL; // If list becomes empty, update tail
    }

    void pop_back(){
        if(!head) return; // List is empty
        if(head == tail){ // Only one element
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL; 
    }


    void printList(){
        Node* temp = head;
        while(temp){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

      
    void insert(int val, int index){
        if(index==0){
            push_front(val);
        }
        if(index<0){
            cout<<"invalid value";
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
    
        for(int i=0; i<index-1; i++){
            if(!temp){
                cout<<"Index out of bounds";
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }


    void push_back(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void search(int val){
        Node* temp = head;
        int index = 0;
        while(temp){
            if(temp->data == val){
                // Found the value
                // cout<<"data found\n";
                // Do something with the found value
                cout << "Found value: " << temp->data << " at index " << index << endl;
                return;
            }
            temp = temp->next;
            index++;
        }
        cout<<"No data found\n";
        return;
    }
};

int main() {
    List ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);

    // ll.push_back(40);
    // ll.push_back(50);
    // ll.push_back(60);

    // ll.pop_front();
    // ll.pop_back();

    ll.insert(40, 2); // Insert 40 at index 2
//    ll.search(20); // Search for value 20
    ll.printList(); // Expected Output: 30 -> 20 -> 10 -> 40 -> 50 -> 60 -> NULL

    return 0;
}