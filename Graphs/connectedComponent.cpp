class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, int& nodes, int& edges) {
        visited[node] = 1;
        nodes++;
        for (auto neigh : adj[node]) {
            edges++; // count edge
            if (!visited[neigh]) {
                dfs(neigh, adj, visited, nodes, edges);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // build adjacency list
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int nodes = 0, edgesCount = 0;
                dfs(i, adj, visited, nodes, edgesCount);
                edgesCount /= 2; // because we counted both directions
                if (edgesCount == nodes * (nodes - 1) / 2) {
                    cnt++;
                }
            }
        }

        return cnt;

    }
};