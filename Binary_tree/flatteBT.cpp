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
public:
   void preorder(TreeNode * root, vector<TreeNode *>& pre){

     if(root == NULL) return;

     pre.push_back(root);
     preorder(root->left , pre);
     preorder(root->right, pre);


   }
    void flatten(TreeNode* root) {
               if(!root) return;
        vector<TreeNode*> pre;
        preorder(root, pre);

        for(int i=0; i<pre.size()-1; i++){
            pre[i]->left = nullptr;
            pre[i]->right = pre[i+1];
        }
        pre.back()->left = nullptr;
        pre.back()->right = nullptr;
    }
};