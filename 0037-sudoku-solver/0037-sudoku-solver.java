class Solution {
    public void solveSudoku(char[][] board) {
        solve(board);
    }
    public boolean solve(char board [][]){
        for(int i=0; i<board.length; i++){  
            for(int j=0; j<board.length; j++){
                if(board[i][j]!='.')
                   continue;
                for(char k ='1'; k<='9'; k++){
                    if(valid(board,i,j,k)){
                       board[i][j]=k;
                    if(solve(board))
                       return true;
                    board[i][j]='.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    public boolean valid(char board [][], int x, int y, char k){
        for(int i=0; i<board.length; i++){
            if(board[x][i]==k)
              return false;
            if(board[i][y]==k)
              return false;
        }
        int srow=(x/3)*3;
        int scol=(y/3)*3;
        for(int i=srow; i<srow+3; i++){
            for(int j=scol; j<scol+3; j++){
                if(board[i][j]==k)
                  return false;
            }
        }
        return true;
    }
}