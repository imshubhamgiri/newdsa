#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void topView(Node* root){
    queue<pair<Node*, int>> q;
    map<int, int> m;
    q.push({root, 0});
    

    while(q.size()>0){
        Node* curr = q.front().first;
        int currHd = q.front().second;
        q.pop();
        
        if(m.find(currHd) == m.end()){
            m[currHd] = curr->data;
        }

        if(curr->left != nullptr){
            q.push({curr->left, currHd-1});
        }
        if(curr->right != nullptr){
            q.push({curr->right, currHd+1});
        }
    }

    for(auto i : m){
        cout<<i.second<<" ";
    }
    cout<<endl<<"top view completed"<<endl;
}

int main(){
    vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,-1};
    int index = -1;
    Node* root = buildTree(preorder, index);
    cout<<"top view of this tree should be 4 ,2 , 1 , 3 " <<endl; 
    topView(root);
    return 0;

}