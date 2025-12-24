void printList(){
        Node* temp = head;
        while(temp){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }