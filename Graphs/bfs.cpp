class Solution {
public: 
    vector<int> bfs(int start, vector<int> adj[], int n) {
        vector<int> visited(n + 1, 0); 
        queue<int> q;
        visited[start] = 1;
        q.push(start);
        vector<int> res;

        while (!q.empty()) {
            int curr = q.front(); 
            q.pop();
            res.push_back(curr);

            for (auto it : adj[curr]) {
                if (!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return res; 
    }
};
