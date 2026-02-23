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

Node* preOrder(Node* root){
  if(root == NULL){
    return NULL;
  }
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);

}

int htInorder(Node* root){
    if(root == nullptr){
return 0;
    }

     int  right = htInorder(root->right);
     int  left = htInorder(root->left);
     return max(left,right)+1;
    
}

int jod(Node* root){
    if(root == nullptr){
        return 0;
    }
    int left = jod(root->left);
    int right = jod(root->right);
    return left+right+ root->data ;
}

int main(){
vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,-1};
int index = -1;
Node* root = buildTree(preorder, index);
// preOrder(root);
// cout<<endl;
cout<<htInorder(root)<<endl;
cout<<jod(root)<<endl;


}
