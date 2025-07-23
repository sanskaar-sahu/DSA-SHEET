#include<bits/stdc++.h> 

class Node{
    public : 
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
      void iterativePreOrder(Node * root){
        stack<Node* > st;
        vector<int>preOrder;
        if(!root) return preOrder;

        st.push_back(root)
        
        while(!st.empty()){
          Node * temp = st.top(); st.pop();

          preOrder.push_back(temp->data);

          if(root->right) st.push(root->right);
          if(root->left) st.push(root->left);
        }
        return preOrder;
      } 
}