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
class CircularLinkedList{
    Node* head;
    Node* tail;
    public:
    CircularLinkedList(){
        head = NULL;
        tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
            tail->next = head; // Point tail to head to make it circular
        }else{
            newNode->next = tail->next; // newNode points to head
            tail->next = newNode; // tail points to newNode
            head = newNode; // Update head to newNode
        }
    }
    void printList(){
        if(!head) return; // List is empty
        Node* temp = head;
        do{
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }while(temp != head);
        cout<<"(back to head: "<<head->data<<")"<<endl;
        cout<<"Node at tail-"<<tail->data<<endl;
    }
    void insertAtTail(int val){
           Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
            tail->next = head; // Point tail to head to make it circular
        }else{
            newNode->next = tail->next; // newNode points to head
            tail->next = newNode; // tail points to newNode
            tail = newNode; // Update tail to newNode
        }
    }

    void headD(){
        if(!head) return; // List is empty
        else if(head == tail){ // Only one element
            delete head;
            head = tail = NULL;
            return;
        }else{
            Node* temp = head;
            head = head->next;
            tail->next = head; // Update tail's next to new head
            temp->next = NULL; // Optional: clear the next of the deleted node
            delete temp;
        }
    }
    void TailD(){
        if(!head) return;
        else if(head==tail){
            delete tail;
            head = tail = NULL;
        }else{
            Node* temp = tail;
            Node* prev = head;
            while(prev->next != tail){
                prev = prev->next;
            }
            // prev->next = head;
            tail = prev;
            tail ->next = head;
            temp->next = NULL;
            delete temp;
        }
    }
};
int main(){
    CircularLinkedList cll;
    cll.push_front(10);
    cll.push_front(20);
    cll.push_front(30);
    cll.insertAtTail(40);
    cll.printList();
    cll.TailD();
    cout<<"After deleting tail:"<<endl;
    cll.printList();
    return 0;
}