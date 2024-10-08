class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        
        queue<pair<int, int>> que;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        que.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        while(!que.empty()){
            int row = que.front().first;
            int col = que.front().second;
            que.pop();
            
            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    que.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};