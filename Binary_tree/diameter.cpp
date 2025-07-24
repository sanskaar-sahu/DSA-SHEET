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


//Leetcode Problem 543
class Solution {

public:

    int height(TreeNode * root , int& diameter){
        if(!root) return 0;
        int lh = height(root->left , diameter);
        int rh = height(root->right , diameter);

        diameter = max(diameter , lh + rh);

        return 1 + max(lh , rh);
    }

    
    int diameterOfBinaryTree(TreeNode* root) {
        int dim = 0;
        height(root , dim);
        return dim;
    }
};