     
     vector<vector<int>> verticleOrder(TreeNode * root){
     // map<col, map<level, multiset<node values>>>
        map<int, map<int, multiset<int>>> nodes;

        // queue of node and its (level, col) position
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}}); // root at level=0, col=0

        while (!q.empty()) {
            auto front = q.front(); q.pop();
            TreeNode* node = front.first;
            int row = front.second.first;
            int col = front.second.second;

            nodes[col][row].insert(node->val);

            if (node->left) {
                q.push({node->left, {row + 1, col - 1}});
            }

            if (node->right) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }

        vector<vector<int>> result;
        for (auto& [col, rowMap] : nodes) {
            vector<int> colVec;
            for (auto& [row, values] : rowMap) {
                colVec.insert(colVec.end(), values.begin(), values.end());
            }
            result.push_back(colVec);
        }

        return result;
     }
     
