#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
 int data;
 Node* left = NULL;
 Node* right = NULL;
    
    Node(int val){
        data = val;
        this->left = NULL;
        this->right = NULL;
    }

};

int index = -1;
Node* Buildtree(vector<int>preorder){
index++;
if(preorder[index] == -1){
    return NULL;
}
Node* root = new Node(preorder[index]);
root->left = Buildtree(preorder);
root->right = Buildtree(preorder);
return root;
}


vector<int> morrisInorder(Node* root){

    vector<int> ans;
    Node* curr = root;
    while(curr){
        if(!curr->left){
            ans.push_back(curr->data);
            curr = curr->right;
        }else{
            Node* Ip = curr->left;
            while(Ip->right  && Ip->right != curr){
                Ip = Ip->right;
            }
            if(!Ip->right){
                Ip->right = curr;
                curr = curr->left;
            }else{
                Ip->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }


    }

    return ans;
}

int main(){
    vector<int>preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,-1};
    Node* root = Buildtree(preorder);
    vector<int> inorder = morrisInorder(root);
    for(int i = 0; i < inorder.size(); i++){
        cout << inorder[i] << " ";
    }
    return 0;

}