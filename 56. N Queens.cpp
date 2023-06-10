bool issafe(int row,int col,vector<vector<int>> &board){
    int i=row,j=col;
    for(int r=0;r<col;r++){
        if(board[i][r]==1)return false;
    }
    while(i>=0 && j>=0){
        if(board[i][j]==1)return false;
        i--;
        j--;
    }
    i=row,j=col;
    while(i<board.size() && j>=0){
        if(board[i][j]==1)return false;
        i++;
        j--;
    }
    return true;
}
void f(int col,vector<vector<int>> &board,int n,vector<vector<int>> &ans){
    if(col>=n){
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
        return;
    }
    for(int row=0;row<n;row++){
        if(issafe(row,col,board)){
            board[row][col]=1;
            f(col+1,board,n,ans);
            board[row][col]=0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
   vector<vector<int>> board(n,vector<int>(n,0));
   vector<vector<int>> ans;
   f(0,board,n,ans);
   return ans;
}