class Solution {
    public: 
    // 1. Recursive version (not optimal, for understanding only)
    int recurse(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0) return 0;
        if (grid[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;

        int leftp = recurse(i, j - 1, grid);
        int upp = recurse(i - 1, j, grid);

        return leftp + upp;
    }
     // 2. Recursive + Memoization (Top-down DP)
    int memo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;
        if (grid[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        int leftp = memo(i, j - 1, grid, dp);
        int upp = memo(i - 1, j, grid, dp);

        return dp[i][j] = leftp + upp;
    }

     // 3. Tabulation (Bottom-up DP)
    int tabulate(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else {
                    int leftp = (j > 0) ? dp[i][j - 1] : 0;
                    int upp = (i > 0) ? dp[i - 1][j] : 0;
                    dp[i][j] = leftp + upp;
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }

    int findPath(vector<vector<int>>grid){
        return tabulate(grid);
    }
}