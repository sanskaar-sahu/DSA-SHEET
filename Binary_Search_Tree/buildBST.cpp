#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) {
        val = v;
        left = right = nullptr;
    }
};

// Step 1: Build a Balanced BST from sorted array
TreeNode* buildBalancedBST(vector<int>& arr, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(arr[mid]);

    root->left = buildBalancedBST(arr, start, mid - 1);
    root->right = buildBalancedBST(arr, mid + 1, end);

    return root;
}

// Step 2: Pre-order traversal with custom print format
void preorder(TreeNode* root) {
    if (!root) return;

    string leftVal = root->left ? to_string(root->left->val) : ".";
    string rightVal = root->right ? to_string(root->right->val) : ".";

    cout << leftVal << " <- " << root->val << " -> " << rightVal << endl;

    preorder(root->left);
    preorder(root->right);
}



void userLogic(int N, int arr[]) {
    // user logic goes here
    sort(arr , arr + N);
    TreeNode* root = buildBalancedBST(arr , 0 , N);
    preorder(root);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    userLogic(N, arr);
    return 0;
}