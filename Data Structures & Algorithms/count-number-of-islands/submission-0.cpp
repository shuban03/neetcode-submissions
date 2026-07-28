    class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            int islands=0;
            int m=grid.size();
            int n=grid[0].size();

            vector<vector<bool>> vis(m,vector<bool>(n,false));

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]=='1' && !vis[i][j]){
                        dfs(i,j,grid,vis,m,n);
                        islands++;
                    }
                }
            }   
            return islands;
        }

        void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& vis,int m,int n){
            
            if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0' || vis[i][j]==1){
                return;
            }
            
            vis[i][j]=1;
            dfs(i-1,j,grid,vis,m,n);  //top
            dfs(i+1,j,grid,vis,m,n);  //bottom
            dfs(i,j-1,grid,vis,m,n);  //left
            dfs(i,j+1,grid,vis,m,n);  //right
        }


    };