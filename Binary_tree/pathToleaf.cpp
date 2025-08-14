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
    
    void dfs(TreeNode* root, string path, vector<string>& ans) {
        if (!root) return;

        // Append current node value to path
        if (!path.empty()) path += "->";
        path += to_string(root->val);

        // If leaf node, add to result
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }

        // Continue DFS
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(!root) return ans;

         dfs(root ,"",  ans);
         return ans;

    }
};