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
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
        }
}