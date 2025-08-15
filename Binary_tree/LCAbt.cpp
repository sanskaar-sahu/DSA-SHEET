/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode * ancestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL || root == p || root == q) return root;

        TreeNode*  left = ancestor(root->left , p , q);
        TreeNode* right = ancestor(root->right , p , q);

        if(!left) return right; //left is null then return right
        else if(!right) return left; //if right is null return left
        else  return root;   //both are not null
     }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * node  = ancestor(root , p , q);
        return node;
    }
};