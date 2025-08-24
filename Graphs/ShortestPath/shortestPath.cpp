
/**
  Calculate the distance form source to each node with the edge represent the unit distance
  Que : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
 */

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        vector<int>dist(adj.size() , -1);
        queue<pair<int,int>>q;
        q.push({src , 0});
        dist[src] = 0;
        
        while(!q.empty()){
            auto [node , dis] = q.front() ; q.pop();
            
            for(auto it : adj[node]){
                if(dist[it] == -1){
                    dist[it] = dis + 1;
                    q.push({it , dis + 1});
                }
            }
            
        }
        return dist;
    }
};