#include<vector>
#include<queue>
#include<iostream>
using namespace std;



class Node{
    int data ;
    Node* left;
    Node*right;

    Node(int val){
        this->data = val;
        left = right = NULL;
    }
};
    

class Solution{
    public  : 

      vector<vector<int>> levelOrder(Node * root){
            vector<vector<int>> res;
            queue<Node*>q;

            if(root == nullptr) return;
            q.push(root);

            while(!q.empty()){
                int size = q.size();
                vector<int>level;
                for(int i = 0 ; i < size ; i++){
                    Node* temp = q.front();
                    q.pop();

                    if(temp->left) q.push(temp->left->data);
                    if(temp->right) q.push(temp->right->data);
                    level.push_back(temp->data);
                }
                res.push_back(level);
            }
            return res;
      }
}