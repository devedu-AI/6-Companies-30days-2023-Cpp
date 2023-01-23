class Solution {
public:
    void dfs(vector<vector<int>> &grid,vector<vector<bool>> &vis,int row,int col){
        vis[row][col]=true;
        
        int n=grid.size();
        int m=grid[0].size();
        
        int delR[] = {-1,0,+1,0};
        int delC[] = {0,-1,0,+1};
        
        for(int i=0;i<4;i++){
            int nrow = row+delR[i];
            int ncol = col+delC[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&
              grid[nrow][ncol]==0 && !vis[nrow][ncol]){
                dfs(grid,vis,nrow,ncol);
            }
        }
        
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        //row
        for(int i=0;i<m;i++){
            if(grid[0][i]==0 && !vis[0][i]) dfs(grid,vis,0,i);
        }
        for(int i=0;i<m;i++){
            if(grid[n-1][i]==0 && !vis[n-1][i]) dfs(grid,vis,n-1,i);
        }
        
        //col
        for(int i=0;i<n;i++){
            if(grid[i][0]==0 && !vis[i][0]) dfs(grid,vis,i,0);
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==0 && !vis[i][m-1]) dfs(grid,vis,i,m-1);
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    ans++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        
        return ans;
        
        
    }
};
