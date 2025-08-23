
/**
 Que link : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
 */

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>adj[V];
        vector<int>indegree(V , 0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            // u-->v
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int>q;
        
        for(int i = 0 ; i < V ; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        int count = 0;  //Total nodes in list
        
        while(!q.empty()){
            int node= q.front() ; q.pop();
            count++;
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return (count != V);
    }
}; 