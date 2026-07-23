class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));     //initialization of board 
        helper(res,board,n,0);
        return res;
    }

    bool isSafe(vector<string>& board,int row,int col,int n){
        //vertically  (row is changing)
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        //horizontally (col is changing)
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }

        //diagonal left
        for(int r=row,c=col;r>=0 && c>=0;r--,c--){
            if(board[r][c]=='Q'){
                return false;
            }
        }

        //diagonal right
        for(int r=row,c=col;r>=0 && c>=0;r--,c++){
            if(board[r][c]=='Q'){
                return false;
            }
        }
        return true;
    }

    void helper(vector<vector<string>>& res,vector<string>& board,int n,int row){
        if(row==n){                      //when it hits the last row
            res.push_back(board);
        }
       
        for(int col=0;col<n;col++){                   //place Q in each column
            if(isSafe(board,row,col,n)){           
                board[row][col]='Q';                    //insert Q           
                helper(res,board,n,row+1);              //go to next row (explore)
                board[row][col]='.';                    //remove Q
            }
        }
    }
};