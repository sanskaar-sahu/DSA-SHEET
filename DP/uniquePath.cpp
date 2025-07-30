
//Leetcode que 62

class Solution {
public:
     
     int explore(int row, int col, int m, int n) {
        // Base Case: If we reached the bottom-right corner
        if (row == m - 1 && col == n - 1) return 1;

        // If out of bounds
        if (row >= m || col >= n) return 0;

        // Move right and down
        return explore(row + 1, col, m, n) + explore(row, col + 1, m, n);
    }
    int uniquePaths(int m, int n) {
             // Create a 2D DP table with m rows and n columns
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // Fill the table starting from (1,1) to (m-1,n-1)
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // Current cell = paths from top + paths from left
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // The bottom-right corner contains the answer
        return dp[m - 1][n - 1];
    }
};