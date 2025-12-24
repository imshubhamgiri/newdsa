#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
    
};

class LinkedList{
    Node* head;
    Node* tail;
    public:
    LinkedList(){
        head = tail = NULL;
    }
    void reverse(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        tail = head; // Update tail to the old head
        while(curr){
            next = curr->next; // Store next node
            curr->next = prev; // Reverse the link
            prev = curr;       // Move prev to current
            curr = next;      // Move to next node
        }
        head = prev; // Update head to the new front
    }
     void push_back(int val){
        Node* n = new Node(val);
        if(!head){
            head = tail = n;
            return;
        }
        tail->next = n ;
        tail = n;
    }

    void printList(){
        Node* temp = head;
        while(temp){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main(){
    //complete this code give the values which is going to be reversed

    LinkedList ll;
       // sample values to be inserted
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.push_back(50);

    cout << "Before reverse: ";
    ll.printList();

    ll.reverse();

    cout << "After reverse: ";
    ll.printList ();
    return 0;
}

