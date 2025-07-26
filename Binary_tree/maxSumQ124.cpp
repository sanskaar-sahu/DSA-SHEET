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
      
    int maxPath = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        // Compute max path sum from left and right subtrees; ignore negatives
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Path passing through root (possibly the answer)
        int pathThroughRoot = root->val + left + right;

        // Update global max path sum
        maxPath = max(maxPath, pathThroughRoot);

        // Return max path sum including root and one of its subtrees
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxPath;
    }
};