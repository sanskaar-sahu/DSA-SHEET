/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  
   TreeNode* build(TreeNode* root , vector<vector<TreeNode*>>v){
       
       if(!root || !root->left || !root->right) return nullptr;
       
       return root;
   }

public:
    TreeNode* invertTree(TreeNode* root) {
       if(!root) return nullptr;

       swap(root->left , root->right);

       invertTree(root->left);
       invertTree(root->right);
       return root;
    }
};
