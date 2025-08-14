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
    bool res(TreeNode*root , int key, vector<int>& ans){
          if(!root) return false;

          res.push_back(root->val);
          if(root->val == key) return true;

          if(res(root->left , key , ans) || res(root->right , key , ans)){
            return true;
          }
        
        ans.pop_back();
        return false;
    } 
   
    vector<int> getPathtoNode(TreeNode* root, int target) {
        if(root == NULL) return [];

        vector<int> ans;
        res(root , target , ans);
        return ans;


    }
};