#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
 public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
    this->val = val;
    left = right = nullptr;
    }
};

class Solution{
public:
//Dfs approach
   void preOrd(Node* root , int curLvl ,int& maxlv, vector<int>&ans){  //preorder traversal with DFS
        if(!root) return;
        if(curLvl>maxlv){
            ans.push_back(root->val);
            maxlv = curLvl;
        }
        if(root->right) preOrd(root->right , curLvl+1 , maxlv , ans);
        if(root->left) preOrd(root->left , curLvl+1 , maxlv , ans);
       
    }
    vector<int> rightSideView(Node* root) {
         vector<int>result;
         int maxlevel = -1;
          preOrd(root ,0 , maxlevel , result);
          return result;
    }

    //BFS approach

    vector<int> rightSideViewBfs(Node* root){
        vector<int>result;
        if(!root) return result; //edge case if the tree is empty

        queue<Node*>q;
        //start with the root node
        q.push(root);

        while(!q.empty()){
            int sz = q.size(); //Here we are getting the size of the queue which is the number of nodes at the current level of the tree. This is important because we want to process all nodes at the current level before moving on to the next level. By knowing the size of the queue, we can ensure that we only process nodes that belong to the same level, allowing us to correctly identify and store the rightmost node's value for that level.
            for(int i=0 ; i<sz ; i++){
                Node* cur = q.front();
                q.pop();
                if(i==0) result.push_back(cur->val);   //Now here if you get confuse don't worry it's simple for first time root wil be added now see just below this we add right child first and then left child so the right child will be at the front of the queue and left child will be at the back of the queue so when we pop from the queue we will get the right child first and then left child so if i==0 means we are at the first node of the current level which is the rightmost node of that level so we add it to the result vector. 

                //simple right? Go ahead and dry run the code to understand it better.
                if(cur->right) q.push(cur->right);
                if(cur->left) q.push(cur->left);
            }
        }
        return result;  
    }

};

int main(){
Node* root = new Node(1);
root->left = new Node(2);
root->left->left = new Node(3);
root->right = new Node(0);
root->right->left = new Node(4);


Solution solve;
vector<int> ans = solve.rightSideView(root);

cout<<"right side view"<<endl;
for(int x :ans){
    cout<<x<<endl;
}
return 0;

}