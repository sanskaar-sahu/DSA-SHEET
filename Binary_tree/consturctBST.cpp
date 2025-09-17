/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    TreeNode* build(vector<int>& pre, int ps, int pe, vector<int>& in, int is,
                    int ie, unordered_map<int, int>& mp) {

        if (ps > pe || is > ie)
            return NULL;

        TreeNode* root = new TreeNode(pre[ps]);
        int inRoot = mp[root->val];
        int left = inRoot - is;
        root->left = build(pre, ps + 1, ps + left, in, is, inRoot - 1, mp);
        root->right = build(pre, ps + left + 1, pe, in, inRoot + 1, ie, mp);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1, mpp);
    }
};