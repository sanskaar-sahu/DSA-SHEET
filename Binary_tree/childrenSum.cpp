/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
    bool Helper(Node * root){
            // Empty tree or leaf node satisfies the property
        if (!root || (!root->left && !root->right)) return true;

        int leftVal = (root->left ? root->left->data : 0);
        int rightVal = (root->right ? root->right->data : 0);

        if (root->data != leftVal + rightVal) return false;

        return Helper(root->left) && Helper(root->right);
        
    }
  public:
    int isSumProperty(Node *root) {
        // code here
        return Helper(root) ? 1 : 0;
    }
};