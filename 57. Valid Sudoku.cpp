bool issafe(int row,int col,int matrix[9][9],int k){
    for(int i=0;i<9;i++){
        if(matrix[i][col]==k)return false;
        if(matrix[row][i]==k)return false;
        if(matrix[3*(row/3)+i/3][3*(col/3)+i%3]==k)return false;
    }
    return true;
}
bool f(int matrix[9][9]){
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            if(matrix[row][col]==0){
                for(int k=1;k<=9;k++){
                  if (issafe(row, col, matrix, k)) {
                      matrix[row][col]=k;
                      if(f(matrix))return true;
                      matrix[row][col]=0;
                  }
                }
                return false;
            }
        }
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) {
   return f(matrix);
}
