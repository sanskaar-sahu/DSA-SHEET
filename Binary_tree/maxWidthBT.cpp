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
    int widthOfBinaryTree(TreeNode* root) {
        int maxw = 0;
        queue<pair<TreeNode* ,unsigned long long>> q;
        q.push({root , 0});
        while(!q.empty()){
            int sz = q.size();
            unsigned long long firstIdx = q.front().second; //first node of that level
            unsigned long long lastIdx =  q.back().second; //last node of that level will be stored 
            maxw = max(maxw ,(int)(lastIdx - firstIdx + 1));
            for(int i = 0 ; i < sz; i++){
              TreeNode* curr = q.front().first;
              unsigned long long idx = q.front().second;  q.pop();
              if(curr->left) q.push({curr->left , 2*idx+1});
              if(curr->right) q.push({curr->right , 2*idx+2});
            }
        }
        return maxw;
    }
};