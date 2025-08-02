#include<bits/stdc++.h> 

class Solution {
public:

    int solve(int row, int col, vector<vector<int>>& matrix) {
        if (col < 0 || col >= matrix[0].size()) return 1e9; // out of bounds

        if (row == matrix.size() - 1) {
            return matrix[row][col]; // base case: last row
        }

        int left = solve(row + 1, col - 1, matrix);
        int down = solve(row + 1, col, matrix);
        int right = solve(row + 1, col + 1, matrix);

        return matrix[row][col] + min({left, down, right});
    }

    int memo(int row, int col, vector<vector<int>>& matrix,vector<vector<int>>& dp) {
        if (col < 0 || col >= matrix[0].size()) return 1e9; // out of bounds

        if (row == matrix.size() - 1) {
            return matrix[row][col]; // base case: last row
        }

        if(dp[row][col]!= -1) return dp[row][col];

        int left = memo(row + 1, col - 1, matrix,dp);
        int down = memo(row + 1, col, matrix,dp);
        int right = memo(row + 1, col + 1, matrix,dp);

        return dp[row][col] = matrix[row][col] + min({left, down, right});
    }
     
     
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int cols = matrix[0].size();
        int rows = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>>dp(rows , vector<int>(cols , -1));

        // Initialize the last row
        for (int j = 0; j < cols; j++) {
            dp[rows - 1][j] = matrix[rows - 1][j];
        }

        // Build the DP table from bottom to top
        for (int i = rows - 2; i >= 0; i--) {
            for (int j = 0; j < cols; j++) {
                int left = j > 0 ? dp[i + 1][j - 1] : 1e9;
                int down = dp[i + 1][j];
                int right = j < cols - 1 ? dp[i + 1][j + 1] : 1e9;

                dp[i][j] = matrix[i][j] + min({left, down, right});
            }
        }

        // The answer is the minimum in the top row
        return *min_element(dp[0].begin(), dp[0].end());
    }
};