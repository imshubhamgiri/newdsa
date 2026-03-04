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
Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}
Node* buildBst(vector<int> v  ){
    Node* root = NULL;
    for(int i=0; i<v.size(); i++){
        root = insert(root, v[i]);
    }
    return root;
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool search(Node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}
int main(){
    vector<int> v = {3,2,1,5,4};
    Node* root = buildBst(v);
    // inorder(root);
    cout<<endl;
    if(search(root, 9)){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}