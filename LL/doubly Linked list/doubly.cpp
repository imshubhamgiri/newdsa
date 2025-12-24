#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL{
private:
    Node* head;
    Node* tail;
public:
    DLL(){
        head = NULL;
        tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }

    }

    void printlist(){
        Node*temp = head;
        while(temp != NULL){
            cout<<temp->data<<"<=>";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void push_back(int val){
       Node* newNode = new Node (val);
       if(tail == NULL){
              head = newNode;
              tail = newNode;
       }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
       }
    };

    void pop_front(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }else{
            tail = NULL;
        }
        temp->next = NULL;
        delete temp;
    }
    void pop_back(){
        if (head == NULL){
            cout<<"list is empty"<<endl;
        }
        Node* temp= tail;
        tail = tail->prev;
        if(head!= NULL){
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;

    }

};


int main(){
    DLL list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.pop_front();
    list.printlist();
    return 0;
}