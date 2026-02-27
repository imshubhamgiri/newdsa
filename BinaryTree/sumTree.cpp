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
};

Node* buildTree(vector<int> preorder, int& index){
    index++;
    if(preorder[index] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[index]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);
    return root;
}

void preOrder(Node* root){
  if(root == NULL){
    return ;
  }
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);

}

int sum(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    root->data = leftSum + rightSum + root->data;
    return root->data;
}

int main(){
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int index = -1;
    Node* root = buildTree(preorder, index);
    cout<<"Preorder Traversal before sum: ";
    preOrder(root);
    cout<<endl;
    sum(root);
    cout<<"Preorder Traversal after sum: ";
    preOrder(root);

    return 0;


}