class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int m = image.size() ; int n = image[0].size();
        vector<vector<int>>vis(m , vector<int>(n , 0));
        queue<pair<int,int>>q;
        q.push({sr , sc });
        int pixel = image[sr][sc];
        image[sr][sc] = color;

        int drow[4] = {-1 , 0 , 1 , 0};
        int dcol[4] = {0 , 1 , 0 , -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nrow = drow[i] + r;
                int ncol = dcol[i] + c;
                if( nrow >= 0 && ncol>= 0 && nrow < m && ncol < n && 
                    !vis[nrow][ncol] && image[nrow][ncol] == pixel
                ){
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = color;
                    q.push({nrow , ncol});
                }

             }
        }
        return image;
    }
};