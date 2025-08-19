class Solution {
public:

       void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int m, int n) {
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};

        vis[row][col] = 1; // mark visited

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, grid, m, n);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        /*
        Ques say that we have to calculate total number of 1s where path do not exist
        to go out of the grid . Very similar to previous one SURROUNDING REGION
        */
         int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // check first and last row
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1 && !vis[0][i]) {
                dfs(0, i, vis, grid, m, n);
            }
            if (grid[m-1][i] == 1 && !vis[m-1][i]) {
                dfs(m-1, i, vis, grid, m, n);
            }
        }

        // check first and last column
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0, vis, grid, m, n);
            }
            if (grid[i][n-1] == 1 && !vis[i][n-1]) {
                dfs(i, n-1, vis, grid, m, n);
            }
        }

        int enclave = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    enclave++;
                }
            }
        }
        return enclave;
    }
};