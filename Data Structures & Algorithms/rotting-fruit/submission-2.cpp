class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;

        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>> q;   //{{i,j},time}
        
        //add all rotten oranges to the queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        //bfs
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int time=q.front().second;
            q.pop();

            ans=max(ans,time);

            if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==1){    //top
                q.push({{i-1,j},time+1});
                vis[i-1][j]=1;
            }

            if(i+1<m && !vis[i+1][j] && grid[i+1][j]==1){    //bottom
                q.push({{i+1,j},time+1});
                vis[i+1][j]=1;
            }

            if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==1){    //left
                q.push({{i,j-1},time+1});
                vis[i][j-1]=1;
            }

            if(j+1<n && !vis[i][j+1] && grid[i][j+1]==1){    //right
                q.push({{i,j+1},time+1});
                vis[i][j+1]=1;
            }
        }

        //check for un-rotten oranges
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return ans;
        
    }
};