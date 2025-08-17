class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;
        int n = isConnected.size();
        for (int j = 0; j < n; j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         int n = isConnected.size() ;
         int cnt = 0;
         vector<int>visited(n+1, 0);
         for(int i = 0 ; i < n ; i++){
                 if(!visited[i]){
                    cnt++;
                    dfs(i, isConnected , visited);
                 }
         }
         return cnt;
    }
};