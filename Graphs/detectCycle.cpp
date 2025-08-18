//question : https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670


bool isCycle(int node, vector<vector<int>>& adj, vector<int>& visited) {
    int n = adj.size();
    vector<int> parent(n, -1);

    queue<int> q;
    visited[node] = true;
    q.push(node);

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(auto it : adj[front]) {
            if(!visited[it]) {
                visited[it] = true;
                parent[it] = front;
                q.push(it);
            }
            else if(it != parent[front]) {
                // already visited & not parent → cycle found
                return true;
            }
        }
    }

    return false;
}
