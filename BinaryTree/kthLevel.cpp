#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
} ;
int index = -1;
Node* Buildtree(vector<int> preorder){
       index++;
    if(preorder[index] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[index]);
    root->left = Buildtree(preorder);
    root->right = Buildtree(preorder);
    return root;
}

void printKthLevel(Node* root, int k){
    if(root == nullptr){
        return;
    }
    if(k == 1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);

}

int main(){
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    Node* root = Buildtree(preorder);
    printKthLevel(root, 3);
}