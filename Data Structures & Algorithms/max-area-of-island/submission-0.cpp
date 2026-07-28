class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
        int maxCount=0;;
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count=0;                                       //reset count after each island
                    dfs(i,j,grid,vis,m,n,count);                   //runs for each island
                    maxCount=max(maxCount,count);                  
                }
            }
        }
        return maxCount;
    }

    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis,int m,int n,int& count){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0 || vis[i][j]==1){
            return;
        }
        vis[i][j]=1;
        count++;
        dfs(i+1,j,grid,vis,m,n,count);   //bottom
        dfs(i-1,j,grid,vis,m,n,count);   //top
        dfs(i,j+1,grid,vis,m,n,count);   //right
        dfs(i,j-1,grid,vis,m,n,count);   //left
        }
    
};