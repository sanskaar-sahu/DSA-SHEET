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
    TreeNode* buildTree(vector<int>&arr ,int& idx , int Upperbound){
        if(idx >= arr.size() || arr[idx] > Upperbound ) return nullptr;

        TreeNode* root = new TreeNode(arr[idx++]);  //root will have arr[idx] as val
        root->left = buildTree(arr , idx , root->val);
        root->right = buildTree(arr, idx , Upperbound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        TreeNode* node = buildTree(preorder , i , INT_MAX);
        return node;
    }
};