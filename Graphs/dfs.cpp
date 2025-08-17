class Solution {
    public: 
      void dfs(int v , vector<int>adj[] , vector<int>& visited , vector<int>& res){
         visited[v] = 1;
         res.push_back(v);
         for(auto it : adj[v]){
            if(!visited[it]){
                dfs(it , adj , visited , res);
            }
         }
      }
      vector<int> dfs(int V , vector<int>adj[], int n){
        vector<int>res;
        vector<int>visited(n+1 , 0);
        dfs(V , adj , visited , res);
        return res;
         
      }
}