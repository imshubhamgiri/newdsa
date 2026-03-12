#include<iostream>
#include <vector>
#include <algorithm>
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

Node* buildBst(vector<int> v){
    Node* root = NULL;
    for(int i=0; i<v.size(); i++){
        root = insert(root, v[i]);
    }
    return root;
}

void inorder(Node* root , vector<int>& v){
    if(root == NULL){
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}


Node* buildBstFromSorted(vector<int>& v, int s, int e){
    if(s > e){
        return nullptr;
    }
    int mid = s + (e - s) / 2;
    Node* root = new Node(v[mid]);
    root->left = buildBstFromSorted(v, s, mid - 1);
    root->right = buildBstFromSorted(v, mid + 1, e);
    return root;
}

Node* mergeTrees(Node* root1, Node* root2){
    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2);


    vector<int> temp;
    int i = 0, j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            temp.push_back(v1[i]);
            i++;
        }
        else{
            temp.push_back(v2[j]);
            j++;
        }
    }
    while(i < v1.size()){
        temp.push_back(v1[i]);
        i++;
    }
    while(j < v2.size()){
        temp.push_back(v2[j]);
        j++;
    }

    Node* mergedTree = buildBstFromSorted(temp, 0, temp.size() - 1);
    
    return mergedTree;
}




int main(){
    vector<int> v1 = {8,2,1,10};
    vector<int> v2 = {5,3,0};

    // Build two BSTs
    Node* tree1 = buildBst(v1);
    Node* tree2 = buildBst(v2);

    Node* mergedTree = mergeTrees(tree1, tree2);
    
    vector<int> mergedInorder;
    inorder(mergedTree, mergedInorder);
    for(int val : mergedInorder){
        cout << val << " ";
    }
    
    return 0;
}