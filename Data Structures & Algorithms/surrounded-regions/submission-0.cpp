class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        //first and last row
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                dfs(board,0,j,m,n);
            }
        }
        for(int j=0;j<n;j++){
            if(board[m-1][j]=='O'){
                dfs(board,m-1,j,m,n);
            }
        }

        //first column and last column
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,m,n);
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='O'){
                dfs(board,i,n-1,m,n);
            }
        }

        //make all the 'O' as 'X' 
        //and all  the 'T' as 'O'
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }

    }

    void dfs(vector<vector<char>>& board,int i,int j,int m,int n){
        //out of bounds
        if(i<0 || j<0 || i>=m || j>=n){
            return;
        }

        //if not zero
        if(board[i][j]!='O'){
            return;
        }

        if(board[i][j]=='O'){
            board[i][j]='T';
        }

        dfs(board,i-1,j,m,n);  //top
        dfs(board,i+1,j,m,n);  //bottom
        dfs(board,i,j-1,m,n);  //left
        dfs(board,i,j+1,m,n);  //right

        
    }
};