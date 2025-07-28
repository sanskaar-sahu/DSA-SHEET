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


 //leetcode problem 110 
class Solution {
public:
bool isLeaf(TreeNode* node) {
    return !node->left && !node->right;
}

void addLeftBoundary(TreeNode* root, vector<int>& res) {
    TreeNode* curr = root->left;
    while (curr) {
        if (!isLeaf(curr)) res.push_back(curr->val);
        if (curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addLeaves(TreeNode* root, vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->val);
        return;
    }
    if (root->left) addLeaves(root->left, res);
    if (root->right) addLeaves(root->right, res);
}

void addRightBoundary(TreeNode* root, vector<int>& res) {
    TreeNode* curr = root->right;
    vector<int> tmp;
    while (curr) {
        if (!isLeaf(curr)) tmp.push_back(curr->val);
        if (curr->right) curr = curr->right;
        else curr = curr->left;
    }
    // Reverse right boundary before adding
    for (int i = tmp.size() - 1; i >= 0; i--) {
        res.push_back(tmp[i]);
    }
}

    void leftOrder(TreeNode * root , vector<int>& res){
        if(!root) return;
        
        if(isLeft(root)) res.push_back(root->val);
        else 

        leftOrder(root->left , res);
        leftOrder(root->right , res);
    }


  vector<int>boundaryOrder(TreeNode* root){
      vector<int>res;
      if(!root) return res;
      res.push_back(root->val);
      if(!root->left &&!root->right) return res;

      addLeftBoundary(root->left , res);
      addLeaves(root , res);
      addRightBoundary(root->right , res);

      return res;
  }
};