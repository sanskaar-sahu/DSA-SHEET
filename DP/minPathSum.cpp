class Solution {
public:
       
    int memo(int i , int  j ,vector<vector<int>>& grid , vector<vector<int>>& dp){
        if(i == 0 && j == 0) return grid[0][0];

        if(i < 0 || j < 0) return 1e9;

        if(dp[i][j]!= -1) return dp[i][j];


        int leftP = grid[i][j] + memo(i , j-1 , grid,dp);
        int upP = grid[i][j] + memo(i -1 , j , grid , dp ) ;
            
        return dp[i][j] =  min(leftP , upP);
    }

    int tabulate(vector<vector<int>>& grid){
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = grid[i][j];  // Starting point
            } else {
                int up = (i > 0) ? dp[i - 1][j] : 1e9;
                int left = (j > 0) ? dp[i][j - 1] : 1e9;
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }

    return dp[rows - 1][cols - 1]; 

    }

    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size() ; int cols = grid[0].size();
        if(rows < 2 && cols < 2) return grid[0][0];
        vector<vector<int>>dp(rows , vector<int>(cols , -1));
        memo(rows - 1, cols - 1 , grid , dp);
        return dp[rows-1][cols-1];
    }
};