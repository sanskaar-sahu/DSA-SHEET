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
      void preOrder(Node* root){
        if(root == nullptr){
            return;
        }
        preOrder(root->left);
        cout<<root->data<<" ";
        preOrder(root->right);
        }
}