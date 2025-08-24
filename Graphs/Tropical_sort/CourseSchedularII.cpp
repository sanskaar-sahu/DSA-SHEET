class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        // Build graph
        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][0]; // course to take
            int v = prerequisites[i][1]; // prerequisite
            adj[v].push_back(u);   // edge: v → u
            inDegree[u]++;         // u depends on v
        }

        queue<int> q;
        for(int i = 0 ; i < numCourses ; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        int count = 0;
        vector<int> res;
        while(!q.empty()){
            int node = q.front(); q.pop();
            res.push_back(node);
            count++;

            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }

        if(count != numCourses) return {}; // cycle detected → no valid order
        return res;
    }
};