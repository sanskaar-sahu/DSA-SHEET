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
      vector<int> iterativeInOrder(Node * root){
        if(!root) return [];
        stack<Node* > st;
        Node* node = root;
        vector<int>inOrder;
        
        while(true){
          if(node){
             st.push(node);
             node = node->left;
          }else{
            if(st.empty()) break;
            Node* node = st.top() ; st.pop();
            
            inOrder.push_back(node->data);

            node = node->right;
          }

        }
        return inOrder;
      } 
}