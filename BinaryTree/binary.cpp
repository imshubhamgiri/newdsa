#include<iostream>
#include<vector>
#include<queue>
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

void Inorder(Node* root){
    if(root == nullptr){
return;
    }
    Inorder( root->left);
    cout<<root->data<<" ";
    Inorder(root->right);

}

void postOrder(Node* root){
    if(root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<"  ";
}

void levelOrder(Node* root){
    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);

    while(q.size()>0){
        Node* curr = q.front();
        q.pop();
        if(curr == NULL){
            if(!q.empty()){
            cout<<endl;
            q.push(NULL);
            continue;
            }
             else{
                break;
            }
        }
        cout<<curr->data<<" ";

        if(curr->left != nullptr){
            q.push(curr->left);
        }
        if(curr->right != nullptr){
            q.push(curr->right);
        }
    }
    cout<<endl;
}

int main(){
    vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,-1};
    int index = -1;
    Node* root = buildTree(preorder, index); 
    // cout<<"Root Node: "<<root->data<<endl;
    // cout<<"Left Child of Root: "<<root->left->data<<endl;
    // cout<<"Right Child of Root: "<<root->right->data<<endl;
    levelOrder(root);
    return 0;

}