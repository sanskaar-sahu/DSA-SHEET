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
    // Step 1: Mark parents for each node
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    // Step 2: Find start node
    TreeNode* find(TreeNode* root, int start) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->val == start) return node;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return nullptr;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);

        unordered_map<TreeNode*, bool> visited;
        TreeNode* startNode = find(root, start);

        int burnTime = 0;
        queue<TreeNode*> q;
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            int sz = q.size();
            bool spread = false;  // check if infection spreads in this level
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front(); q.pop();

                // Left child
                if (curr->left && !visited[curr->left]) {
                    spread = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                // Right child
                if (curr->right && !visited[curr->right]) {
                    spread = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                // Parent
                if (parent[curr] && !visited[parent[curr]]) {
                    spread = true;
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
            if (spread) burnTime++;  // increment only if infection spread
        }
        return burnTime;
    }
};