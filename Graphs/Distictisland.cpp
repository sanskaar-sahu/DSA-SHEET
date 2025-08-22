// User function Template for C++

/**
 Que link : https://leetcode.com/problems/number-of-distinct-islands-ii/description/
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m) {
        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        
        /* {up , left , down , right , up-right , up-left , down-right , down-left } */
        int delrow[8] = {-1, 0 , 1 , 0 , -1 , -1 , 1 , 1};
        int delcol[8] = {0, -1 , 0 , 1 , 1 , -1 , 1 , -1};
        
        while(!q.empty()) {
            auto [r, c] = q.front(); 
            q.pop();
            
            // check all 8 directions
            for(int k = 0; k < 8; k++) {
                int nrow = r + delrow[k];
                int ncol = c + delcol[k];
                
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m 
                   && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        int island = 0;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    bfs(i, j, grid, vis, n, m);
                    island++;
                }
            }
        }
        return island;
    }
};
