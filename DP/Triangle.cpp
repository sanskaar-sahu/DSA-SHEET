class Solution {
public: 
    int recurr(int row , int col ,vector<vector<int>>& triangle ){
        if(row == triangle.size() -1){
            return triangle[row][col];
        }

        int down = triangle[row][col] + recurr(row+1 , col , triangle);
        int diag = triangle[row][col] + recurr(row+1 , col + 1 , triangle);

        return min(down , diag);
    }

    int memo(int row , int col ,vector<vector<int>>& triangle, vector<vector<int>>& dp ){
        if(row == triangle.size() -1){
            return  triangle[row][col];
        }

        if(dp[row][col]!= -1) return dp[row][col];
        
        int down = triangle[row][col] + memo(row+1 , col , triangle,dp);
        int diag = triangle[row][col] + memo(row+1 , col + 1 , triangle,dp);

        return dp[row][col] =  min(down , diag);
    }

    int tabulate(vector<vector<int>>& triangle){
        int row = triangle.size() ;
        vector<vector<int>> dp(row, vector<int>(row, -1));  // Proper dp initialization
        for(int i = 0 ; i < row ; i++){
            dp[row -1 ][i] = triangle[row-1][i];
        }
        for(int i = row - 2 ; i>= 0 ; i--){
            for(int j = i ; j>= 0 ; j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];    
                dp[i][j] = min(down , diag);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return tabulate(triangle);
    }
};