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
      void inOrder(Node* root){
        if(root == nullptr){
            return;
        }
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
        }
}