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

    TreeNode* findLast(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }

    TreeNode* resolve(TreeNode* root) {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        TreeNode* rightSub = root->right;
        TreeNode* lastLeft = findLast(rightSub);
        lastLeft->left = root->left;
        return rightSub;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // If root itself is the node to delete
        if (root->val == key) {
            return resolve(root);
        }

        TreeNode* temp = root;

        while (root) {
            if (root->val > key) {
                if (root->left && root->left->val == key) {
                    root->left = resolve(root->left);
                    break; // stop after deletion
                } else {
                    root = root->left;
                }
            } else {
                if (root->right && root->right->val == key) {
                    root->right = resolve(root->right);
                    break; // stop after deletion
                } else {
                    root = root->right;
                }
            }
        }
        return temp;
    }
};