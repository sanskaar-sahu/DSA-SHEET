    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty()) {
            TreeNode* node1 = q1.front(); q1.pop();
            TreeNode* node2 = q2.front(); q2.pop();

            if (!node1 && !node2) continue; // both are null, OK
            if (!node1 || !node2) return false; // one is null, the other isn't
            if (node1->val != node2->val) return false;

            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->left);
            q2.push(node2->right);
        }

        return q1.empty() && q2.empty(); // both queues must end together
    }