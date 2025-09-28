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
    bool res(vector<int>level){
        int low = 0 ; int right = level.size() -1;
        while(low<=right){
            if(level[low]!= level[right]) return false;
            low++;
            right--;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                if (node) {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    level.push_back(INT_MIN); // marker for null
                }
            }

            // check if current level is palindrome
            int l = 0, r = level.size() - 1;
            while (l < r) {
                if (level[l] != level[r]) return false;
                l++; r--;
            }
        }
        return true;
    }
};