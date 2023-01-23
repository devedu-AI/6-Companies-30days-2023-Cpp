class Solution {
public:
    void dfs(vector<vector<int>> &grid,vector<vector<bool>> &vis,int row,int col, int &cnt){
        
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col]=true;
        cnt++;
        
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,-1,0,+1};
        
        for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&
               grid[nrow][ncol]==1&& !vis[nrow][ncol]){
                dfs(grid,vis,nrow,ncol,cnt);
            }
            
        }
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int cnt = 0;
                    dfs(grid,vis,i,j,cnt);
                    maxi = max(maxi,cnt);
                }
            }
        }
        
        return maxi;
        
    }
};
