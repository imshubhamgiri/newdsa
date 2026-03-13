#include<iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left; 
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* rightmostInleft(Node* node){
    Node* ans;
    while(node){
        ans = node;
        node = node->left;
    }
    return ans;
}
Node* leftmostInright(Node* node){
    Node* ans;
    while(node){
        ans = node;
        node = node->right;
    }
    return ans;
}

vector<int> getPreorderSuccessor(Node* root, int key){
    Node* curr = root;
    Node* Ip = NULL;
    Node* IS = NULL;
    while(curr != NULL){

        if(curr->data == key){

            if(curr->left != NULL){
   
                Ip = rightmostInleft(curr->left);
            }
            if(curr->right != NULL){
                IS = leftmostInright(curr->right);
            }
            break;
        }

        else if(key < curr->data){
            IS = curr;
            curr = curr->left;
        }
        else{
            Ip = curr;
            curr = curr->right;
        }
    }

    // vector<int> result;
    // if(Ip != NULL) result.push_back(Ip->data);
    // if(IS != NULL) result.push_back(IS->data);
    return {Ip->data, IS->data};
}

int main(){
    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);

    Node* leftChild = new Node(1);
    root->left->left = leftChild;
    root->left->right = new Node(5);
    root->right->right = new Node(9);
    root->right->left = new Node(7);

    vector<int> result = getPreorderSuccessor(root, 3);
    for(int val : result){
        cout << val << " ";
    }
    return 0;
}
