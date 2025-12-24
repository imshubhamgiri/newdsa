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

     void push_back(int val){
        Node* n = new Node(val);
        if(!head){
            head = tail = n;
            return;
        }
        tail->next = n;
        tail = n;
    }
    void mid(){
         Node* temp = head;
         int index=0;
         while(temp){
        index++;
        temp = temp->next;
         }
         temp = head;

         for(int i=0; i<index/2; i++){
           temp= temp->next;
         }
         cout<<temp->data<<endl;

    }
    void slowfast(){
        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next){
            slow = slow->next; 
            fast = fast->next->next;
        }
        cout << "Middle element is: " << slow->data << endl;
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

    cout << "mid number is : ";
    ll.slowfast();

}