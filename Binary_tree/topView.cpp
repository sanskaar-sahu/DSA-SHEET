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
  
   vector<int> topView(TreeNode* root) {
     map<int, int> mpp;
     queue<pair<TreeNode*, int>> q;
     vector<int> res;

     if(!root) return res;

     q.push({root, 0});

     while(!q.empty()) {
         auto [node, hd] = q.front(); q.pop();

         if(mpp.find(hd) == mpp.end()) {
             mpp[hd] = node->val;
         }

         if(node->left) q.push({node->left, hd - 1});
         if(node->right) q.push({node->right, hd + 1});
     }

     for(auto it : mpp) {
         res.push_back(it.second); // ✅ Corrected here
     }

     return res;
   }
};