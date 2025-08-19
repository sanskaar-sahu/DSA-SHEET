class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int n, int m) {
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                dfs(nrow, ncol, vis, board, n, m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Left & Right columns
        for (int row = 0; row < n; row++) {
            if (board[row][0] == 'O' && !vis[row][0]) {
                vis[row][0] = 1;
                dfs(row, 0, vis, board, n, m);
            }
            if (board[row][m-1] == 'O' && !vis[row][m-1]) {
                vis[row][m-1] = 1;
                dfs(row, m-1, vis, board, n, m);
            }
        }

        // Top & Bottom rows
        for (int col = 0; col < m; col++) {
            if (board[0][col] == 'O' && !vis[0][col]) {
                vis[0][col] = 1;
                dfs(0, col, vis, board, n, m);
            }
            if (board[n-1][col] == 'O' && !vis[n-1][col]) {
                vis[n-1][col] = 1;
                dfs(n-1, col, vis, board, n, m);
            }
        }

        // Flip unvisited 'O' → 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
