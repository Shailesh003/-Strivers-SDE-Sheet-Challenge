#include <bits/stdc++.h> 
void f(int i,int j,int n,vector<vector<int>>& board,vector<vector<int>> &maze,vector<vector<int>> &ans){
  if(i<0||j<0|| i>=n|| j>=n|| board[i][j]==1|| maze[i][j]==0)return;
  if(i==n-1 && j==n-1){
    board[i][j]=1;
    vector<int> temp;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        temp.push_back(board[i][j]);
      }
    }
    board[i][j]=0;
    ans.push_back(temp);
    return;
  }
  board[i][j]=1;
  f(i+1,j,n,board,maze,ans);
  f(i-1,j,n,board,maze,ans);
  f(i,j+1,n,board,maze,ans);
  f(i,j-1,n,board,maze,ans);
  board[i][j]=0;

}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> board(n,vector<int>(n,0));
  vector<vector<int>> ans;
  f(0,0,n,board,maze,ans);
  return ans;
}