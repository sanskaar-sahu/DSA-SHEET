class Solution {
public:

    bool check(int row , int rows , int col , int cols){
        return (row >= 0 && row < rows && col < cols && col >= 0);
    }

    void dfs(int row , int col ,vector<vector<int>>& vis , vector<vector<char>>& grid){
       vis[row][col] = 1;

       int delrow[4] = {0 ,-1 , 0 , 1};
       int delcol[4] = {-1 , 0 , 1 , 0};

       for(int i = 0 ; i < 4 ; i++){
        int dr = row + delrow[i];
        int dc = col + delcol[i];
       
          //CHECK BOUNDARY FIRST
            if(check(dr, grid.size(), dc, grid[0].size())) {
                if(!vis[dr][dc] && grid[dr][dc] == '1'){
                    dfs(dr, dc, vis, grid);
                }
            }
       }
    }
    
    //has to see
    int numIslands(vector<vector<char>>& grid) {
        int v = grid.size();
        int c = grid[0].size();
        vector<vector<int>>vis(v , vector<int>(c , 0));
        int cnt = 0;
        for(int i = 0 ; i < v ; i++){
            for(int j = 0 ; j < c ; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};